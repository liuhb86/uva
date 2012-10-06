#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;

const int MAXN=10+2;
const int INF=INT_MAX;
struct Node{
	int nedge;
	int to[MAXN];
	int cost[MAXN];
};

Node graph[MAXN];
int cost[MAXN];
int pred[MAXN];
bool visited[MAXN];
int result[MAXN];

int main(){
	int kase=0;
	while(true){
		int n;
		cin>>n;
		if (n==0) break;
		++kase;
		for(int i=1;i<=n;++i){
			int ne;
			cin>>ne;
			graph[i].nedge=ne;
			for(int j=1;j<=ne;++j) {
				cin>>graph[i].to[j]>>graph[i].cost[j];
				visited[i]=false;
			}
		}
		int src,dest;
		cin>>src>>dest;
		for(int i=1;i<=n;++i) cost[i]=INF;
		cost[src]=0;
		for(int i=1;i<=n;++i){
			int min_d=INF;
			int s=INF;
			for(int j=1;j<=n;++j){
				if(!visited[j] && cost[j]<min_d){
					min_d=j;
					s=j;
				}
			}
			if (s==INF) break;
			visited[s]=true;
			for(int j=1;j<=graph[s].nedge;++j){
				int next=graph[s].to[j];
				int newcost=cost[s]+graph[s].cost[j];
				if(newcost<cost[next]){
					cost[next]=newcost;
					pred[next]=s;
				}
			}
		}

		int length=1;
		int next=dest;
		while(true){
			result[length]=next;
			if(next==src) break;
			next=pred[next];
			++length;
		}
		cout<<"Case "<<kase<<": Path =";
		for(int i=length;i>=1;--i) cout<<' '<<result[i];
		if (length ==1) cout<<' '<<result[1];
		cout<<"; "<<cost[dest]<<" second delay"<<endl;
	}
	return 0;
}