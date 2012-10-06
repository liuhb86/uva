#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_COLORS=50+10;

struct Edge{
	int in;
	int out;
	Edge* next;
};

Edge* edgeEndOfColor[MAX_COLORS];
int remainOfColor[MAX_COLORS];
int remainEdges[MAX_COLORS][MAX_COLORS];
int n_remainEdges;
int n_edges;

int main(){
	int kase;
	int first=true;
	cin>>kase;
	for(int i=1;i<=kase;++i){
		memset(remainOfColor,0,sizeof(remainEdges));
		memset(edgeEndOfColor,0,sizeof(edgeEndOfColor));
		memset(remainOfColor,0,sizeof(remainOfColor));
		cin>>n_edges;
		int m,n;
		int n_colors=0;
		for(int j=0;j<n_edges;++j){
			cin>>m>>n;
			if(m>n) {int t=m;m=n;n=t;}
			if(n>n_colors) n_colors=n;
			++remainOfColor[m];
			++remainOfColor[n];
			++remainEdges[m][n];
		}
		n_remainEdges=n_edges;
		Edge *front,*back;
		front=new Edge();
		front->in=m;front->out=n;
		back=front;
		--remainOfColor[m]; --remainOfColor[n]; --remainEdges[m][n]; --n_remainEdges;
		edgeEndOfColor[n]=front;
		bool possible=true;
		while(n_remainEdges>0){
			//cout<<back->in<<" "<<back->out<<" "<<remainOfColor[1]<<endl;
			if(remainOfColor[back->out]==0){
				if(back->out!=front->in) {possible=false;break;}
				//add new ring.
				back->next=front;
				bool rearranged=false;
				//cout<<"SEARCH REARR"<<endl;
				for(int j=1;j<=n_colors;++j) {
					
					//cout<<j<<" "<<edgeEndOfColor[j]<<" "<<remainOfColor[j]<<endl;
					if(edgeEndOfColor[j] && remainOfColor[j]){
					rearranged=true;
					back=edgeEndOfColor[j];
					front=back->next;
					//cout<<"REARR ";
					//cout<<back->in<<" "<<back->out<<" "<<remainOfColor[1]<<endl;
					break;
				}}
				if(!rearranged){possible=false; break;}
			}
			int newIn=back->out,newOut=-1,newM,newN;
			for(int j=1;j<newIn;++j) if(remainEdges[j][newIn]>0){newOut=j;newM=newOut;newN=newIn;break;}
			if(newOut<0) for(int j=newIn;j<=n_colors;++j) 
				if(remainEdges[newIn][j]>0){newOut=j;newM=newIn; newN=newOut;break;}
			--remainOfColor[newIn]; --remainOfColor[newOut];
			--remainEdges[newM][newN];
			--n_remainEdges;
			back->next=new Edge();
			back=back->next;
			back->in=newIn; back->out=newOut;
			edgeEndOfColor[newOut]=back;
		}
		if(back->out!=front->in) possible=false;
		back->next=front;
		if(first) first=false; else cout<<endl;
		cout<<"Case #"<<i<<endl;
		if(possible){
			Edge* p=front;
			do{
				cout<<p->in<<" "<<p->out<<endl;
				p=p->next;
			}while(p!=front);
		}
		else cout<<"some beads may be lost"<<endl;
		Edge* p=front;
		do{
			Edge*q=p->next;
			delete p;
			p=q;
		}while(p!=front);
	}
	return 0;
}
