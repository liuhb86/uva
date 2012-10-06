#include <iostream>
#include <sstream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

const int MAX=10000;
TreeNode nodes[MAX+10];
int inOrder[MAX+10];
int postOrder[MAX+10];
int alloc;
int sum;
int minSum;
int minNode;

TreeNode* buildTree(int start, int end,int startp,int endp){
	if(start>=end) return 0;
	TreeNode* tn=&(nodes[alloc++]);
	tn->val=postOrder[endp-1]+sum;
	//cout<<"+"<<postOrder[endp-1]<<" "<<start<<" "<<end<<" "<<tn->val<<" -- "<<minNode<<" "<<minSum<<endl;
	int middle=find(inOrder+start,inOrder+end,postOrder[endp-1])-inOrder;
	sum=tn->val;
	tn->left=buildTree(start,middle,startp,startp+middle-start);
	sum=tn->val;
	tn->right=buildTree(middle+1,end,startp+middle-start,endp-1);
	if(tn->left==0 && tn->right==0){
		if(tn->val<minSum){minSum=tn->val;minNode=postOrder[endp-1];}
		else if(tn->val==minSum && postOrder[endp-1]<minNode){minNode=postOrder[endp-1];}
	}
	//cout<<"-"<<postOrder[endp-1]<<" "<<start<<" "<<end<<" "<<tn->val<<" -- "<<minNode<<" "<<minSum<<endl;
	return tn;
}
int main(){
	string buffer;
	while(getline(cin,buffer)){
		istringstream iss(buffer);
		int n_nodes=0;
		while(iss>>inOrder[n_nodes++]);
		--n_nodes;
		for(int i=0;i<n_nodes;++i) cin>>postOrder[i];
		getline(cin,buffer);
		alloc=0; sum=0;minSum=INT_MAX;minNode=0;
		//for(int i=0;i<n_nodes;++i) cout<<inOrder[i]<<" ";
		//cout<<endl;
		//for(int i=0;i<n_nodes;++i) cout<<postOrder[i]<<" ";
		//cout<<endl;
		TreeNode* root=buildTree(0,n_nodes,0,n_nodes);
		cout<<minNode<<endl;
	}	
}
