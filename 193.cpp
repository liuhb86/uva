#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE=105;
const char NOCOLOR=0;
const char BLACK=1;
const char WHITE=2;
int table[MAX_SIZE][MAX_SIZE];
int length[MAX_SIZE];
char color[MAX_SIZE];
char optColor[MAX_SIZE];
int maxBlack;
int numBlack;
int m,n;
int n1;

void paint(int node){
	if(node>n){
		if(numBlack>maxBlack){
			maxBlack=numBlack;
			memcpy(optColor,color,n1);
		}
		return;
	}
	bool canPaintBlack=true;
	for(int i=0;i<length[node];++i)
		if(color[table[node][i]]==BLACK) {canPaintBlack=false;break;}
	if(canPaintBlack) {
		color[node]=BLACK;
		++numBlack;
		paint(node+1);
		--numBlack;
	}
	color[node]=WHITE;
	paint(node+1);
}
int main(){
	int kase;
	cin>>kase;
	for(int i=0;i<kase;++i){
		cin>>n>>m;
		n1=n+1;
		for(int j=1;j<n1;++j) length[j]=0;
		for(int j=1;j<n1;++j) color[j]=NOCOLOR;
		for(int j=0;j<m;++j){
			int u,v;
			cin>>u>>v;
			table[u][length[u]++]=v;
			table[v][length[v]++]=u;
		}
		maxBlack=0;
		numBlack=0;
		paint(1);
		cout<<maxBlack<<endl;
		bool first=true;
		for(int j=1;j<n1;++j)
			if(optColor[j]==BLACK){
				if(first) first=false; else cout<<' ';
				cout<<j;
			}
		cout<<endl;
	}
	return 0;
}
