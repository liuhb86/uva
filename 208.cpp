//use calcReachable to prune is critical.
//#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_SIZE=25;
int table[MAX_SIZE][MAX_SIZE];
int length[MAX_SIZE];
bool visited[MAX_SIZE];
//bool unreachable[MAX_SIZE];
int path[MAX_SIZE];
int lenPath;
int n_route;
int dest;

void calcReachable(int node,bool* reachable){
	for(int i=0;i<length[node];++i){
		int nextNode=table[node][i];
		if(!reachable[nextNode] && !visited[nextNode]){
			reachable[nextNode]=true;
			calcReachable(nextNode,reachable);
		}
	}	
}
void visit(int node){
	path[lenPath++]=node;
	if(node==dest){
		for(int i=0;i<lenPath;++i){
			if(i) printf(" ");
			printf("%d",path[i]);		
		}
		printf("\n");
		++n_route;
		--lenPath;
		return ;
	}
	visited[node]=true;
	bool reachable[MAX_SIZE]={false};
	reachable[dest]=true;
	calcReachable(dest,reachable);
	for(int i=0;i<length[node];++i){ 
		int nextNode=table[node][i];
		if(!visited[nextNode]&& reachable[nextNode]) visit(nextNode);
	}
	--lenPath;
	visited[node]=false;	
} 

void trim(int node){
	if(visited[node] || node==1 || node==dest) return;
	visited[node]=true;
	if(length[node]==0) return;
	length[node]=0;
	int peer=table[node][0];
	for(int i=0;i<length[peer];++i){
		if(table[peer][i]==node){
			table[peer][i]=table[peer][--length[peer]];
			if(length[peer]<2) trim(peer);
			break;
		}
	}
}
int main(){
	int kase=0;
	while(scanf("%d",&dest)!=EOF){
		++kase;
		for(int i=0;i<MAX_SIZE;++i){
			length[i]=0;
			visited[i]=false;
		}
		lenPath=0;
		n_route=0;
		//cout<<"CASE "<<kase<<":"<<endl;
		printf("CASE %d:\n",kase);
		while(1){
			int u,v;
			scanf("%d%d",&u,&v);
			if(u==0 &&v==0) break;
			table[u][length[u]++]=v;
			table[v][length[v]++]=u;
		}
		for(int i=0;i<MAX_SIZE;++i){
			if(length[i]<2) trim(i); 
		}
		for(int i=0;i<MAX_SIZE;++i) sort(table[i],table[i]+length[i]);
		visit(1);
		printf("There are %d routes from the firestation to streetcorner %d.\n",n_route,dest);
		//cout<<"There are "<<n_route<<" routes from the firestation to streetcorner "<<dest<<"."<<endl;
	}
	return 0;
}
