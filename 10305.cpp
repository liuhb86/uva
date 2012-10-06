#include <iostream>
#include <cstring>
using namespace std;

const int MAX_NODE=100+10;
bool G[MAX_NODE][MAX_NODE];
char visit[MAX_NODE];
int order[MAX_NODE];
int loc;
int n_nodes,n_edges;

bool DFS(int i_node){
	//cout<<i_node<<" "<<static_cast<int>(visit[i_node])<<endl;
	if(visit[i_node]==1) return true;
	if(visit[i_node]==-1) return false;
	visit[i_node]=-1;
	for(int i=1;i<=n_nodes;++i){
		if(G[i_node][i]){
			bool r=DFS(i);
			if(!r) return false;
		}
	}
	visit[i_node]=1;
	order[--loc]=i_node;
	/*cout<<loc<<" : ";
	for(int i=loc;i<n_nodes;++i) cout<<order[i];
	cout<<endl;*/
	return true;
}

bool topoSort(){
	loc=n_nodes;
	for(int i=1;i<=n_nodes;++i){
		int r=DFS(i);
		if(!r) return false;
	}
	return true;
}
int main(){
	while(1){
		cin>>n_nodes>>n_edges;
		if(n_nodes==0 && n_edges==0) break;
		memset(G,0,sizeof(G));
		memset(visit,0,sizeof(visit));
		for(int i=0;i<n_edges;++i) {
			int u,v;
			cin>>u>>v;
			G[u][v]=1;
		}
		/*for(int i=1;i<=n_nodes;++i){
			for(int j=1;j<=n_nodes;++j) cout<<G[i][j];
			cout<<endl;
		}*/
		bool r=topoSort();
		if(r){
			bool first=true;
			for(int i=0;i<n_nodes;++i){
				if(first) first=false; else cout<<" ";
				cout<<order[i];
			}
			cout<<endl;
		}else{
			cout<<endl;
			//assert(false);
		}
	}
}
