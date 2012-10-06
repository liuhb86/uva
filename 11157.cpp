#include <iostream>
#include <cstdio>
using namespace std;

char buffer[100];
int main(){
	int nkase;
	cin>>nkase;
	for(int kase=1;kase<=nkase;++kase){
		int n,d;
		cin>>n>>d;
		//int bloc=0;
		int sloc[2]={0,0};
		int maxleap=0;
		int psloc=0;
		for(int i=0;i<=n;++i){	
			char type;
			int loc;
			if(i==n){type='B'; loc=d;}
			else {
				cin>>buffer;
				type=buffer[0];
				sscanf(buffer+2,"%d",&loc);
			}
			if( type=='S'){
				int dist=loc-sloc[psloc];
				sloc[psloc]=loc;
				psloc = (psloc+1)%2;
				if(dist>maxleap) maxleap=dist;
			}else {//(type=='B')
				int dist;
				dist=loc-sloc[0];
				if(dist>maxleap) maxleap=dist;
				dist=loc-sloc[1];
				if(dist>maxleap) maxleap=dist;
				sloc[0]=sloc[1]=loc;
			}
		}
		printf("Case %d: %d\n",kase,maxleap);
	}
	return 0;
}