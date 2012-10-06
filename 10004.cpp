#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VecAdj;

struct Node{
	int color;
	VecAdj adjacent;
	Node():color(0){}
	void connect(int i){adjacent.push_back(i);}
};

Node* nodes;

bool paint(int i_node, int color){
	if(nodes[i_node].color==color) return true;
	if(nodes[i_node].color!=0) return false;
	nodes[i_node].color=color;
	for(VecAdj::iterator it=nodes[i_node].adjacent.begin();it!=nodes[i_node].adjacent.end();++it){
		bool r=paint(*it,3-color);
		if(!r) return false;
	}
	return true;
}
int main(){
	while(1){
		int n_nodes;
		int n_edges;
		cin>>n_nodes>>n_edges;
		if(n_nodes==0) break;
		nodes=new Node[n_nodes];
		for(int i=0;i<n_edges;++i){
			int m,n;
			cin>>m>>n;
			nodes[m].connect(n);
			nodes[n].connect(m);
		}
		bool bicolorable=paint(0,1);
		if(bicolorable)cout<<"BICOLORABLE."<<endl;
		else cout<<"NOT BICOLORABLE."<<endl;


	}	
	return 0;	
}
