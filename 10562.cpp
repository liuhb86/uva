#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

struct TreeNode{
	char label;
	TreeNode* child;
	TreeNode* sibling;
	TreeNode(char c):label(c),child(0),sibling(0){}
};
void printSubTree(TreeNode* tn){
	//assert(tn!=0);
	cout<<tn->label<<'(';
	TreeNode* p=tn->child;
	while(p){
		printSubTree(p);
		p=p->sibling;
	}
	cout<<')';
}
void printTree(TreeNode* tn){
	cout<<'(';
	if(tn) printSubTree(tn);
	cout<<')'<<endl;	
}
void delTree(TreeNode* tn){
	if(tn==0) return ;
	TreeNode* p=tn->child;
	while(p){
		delTree(p);
		p=p->sibling;
	}
	delete tn;
}
char bufDash[300];
char bufNode[300];
char bufBar[300];
typedef deque<TreeNode*> Queue;

int main(){
	Queue nodeQue;
	int kase;
	cin>>kase;
	for(int i=0;i<kase;++i){
		//get root
		char c;
		cin>>c;
		TreeNode* root=0;
		TreeNode* sibling=0;
		if (c=='#') goto print;
		root=new TreeNode(c);
		nodeQue.push_back(root);
		cin.getline(bufNode,sizeof(bufNode));
		cin.getline(bufBar,sizeof(bufBar));
		if(bufBar[0]=='#') {
			nodeQue.pop_front();
			goto print;
		}
		do{
			sibling=0;
			cin.getline(bufDash,sizeof(bufDash));
			cin.getline(bufNode,sizeof(bufNode));
			cin.getline(bufBar,sizeof(bufBar));
			int len=strlen(bufNode);
			int lenBar=strlen(bufBar);
			for(int j=0;j<len;++j){
				if(bufDash[j]==' '){
					sibling=0;
					continue;
				}
				if(bufNode[j]!=' '){
					TreeNode* tn=new TreeNode(bufNode[j]);
					if(sibling==0){
						nodeQue.front()->child=tn;
						nodeQue.pop_front();
					}else{
						sibling->sibling=tn;
					}
					sibling=tn;
					if(j<lenBar && bufBar[j]=='|') nodeQue.push_back(tn);
				}
			}
		}while(bufBar[0]!='#');

print:
		//assert(nodeQue.empty());
		nodeQue.clear();
		printTree(root);
		delTree(root);
	}
	return 0;
}
