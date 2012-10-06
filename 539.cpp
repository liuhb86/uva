#include <iostream>
using namespace std;

struct Node{
	int numNode;
	int adj[3];
	bool visited[3];
	bool* visitedDual[3];
};

Node nodes[30];

int maxLen;
int len;

void solve(int node){
	if(len>maxLen) maxLen=len;
	for(int i=0;i<nodes[node].numNode;++i){
		if(nodes[node].visited[i]) continue;
		++len;
		nodes[node].visited[i]=true;
		*(nodes[node].visitedDual[i])=true;
		solve(nodes[node].adj[i]);
		*(nodes[node].visitedDual[i])=false;
		nodes[node].visited[i]=false;
		--len;
	}
}
int main(){
	while(1){
		int m,n;
		cin>>n>>m;
		if(n==0 && m==0) break;
		for(int i=0;i<n;++i) nodes[i].numNode=0;
		for(int i=0;i<m;++i){
			int v1,v2;
			cin>>v1>>v2;
			int &n1=nodes[v1].numNode, &n2=nodes[v2].numNode;
			nodes[v1].adj[n1]=v2;
			nodes[v1].visited[n1]=false;
			nodes[v1].visitedDual[n1]=&(nodes[v2].visited[n2]);
			nodes[v2].adj[n2]=v1;
			nodes[v2].visited[n2]=false;
			nodes[v2].visitedDual[n2]=&(nodes[v1].visited[n1]);
			++n1; ++n2;
		}
		maxLen=0;
		len=0;
		for(int i=0;i<n;++i) solve(i);
		cout<<maxLen<<endl;
	}
	return 0;
}
