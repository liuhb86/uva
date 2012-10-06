//Key: convert from dfs to bfs
#include <iostream>
#include <deque>
#include <cstring>
#include <cctype>
using namespace std;

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	char val;
};

typedef deque<TreeNode*> Stack;
typedef deque<TreeNode*> Queue;

const int MAX=10000;
char buffer[MAX+30];
TreeNode node[MAX+30];

int main(){
	int kase;
	cin>>kase;
	Stack tstack;
	Queue tqueue;
	for(int i=0;i<kase;++i){
		cin>>buffer;
		//cout<<buffer<<endl;
		int len=strlen(buffer);
		for(int j=0;j<len;++j){
			node[j].val=buffer[j];
			if(islower(buffer[j])){
				node[j].left=node[j].right=0;
				tstack.push_back(&(node[j]));
			}else{
				node[j].right=tstack.back();
				tstack.pop_back();
				node[j].left=tstack.back();
				tstack.pop_back();
				tstack.push_back(&(node[j]));
			}
		}
		//cout<<"build done"<<endl;
		TreeNode* root=tstack.back();
		tstack.pop_back();		//Assert(tstack.empty());
		tqueue.push_back(root);
		int j=len;
		while(!tqueue.empty()){
			--j;
			TreeNode* tn=tqueue.front();
			buffer[j]=tn->val;
			if(tn->left) tqueue.push_back(tn->left);
			if(tn->right) tqueue.push_back(tn->right);
			tqueue.pop_front();
		}
		buffer[len]=0;
		cout<<buffer<<endl;
		tqueue.clear();
	}
	return 0;
}
