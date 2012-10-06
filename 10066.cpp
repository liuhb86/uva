#include <iostream>
#include <cstdio>
using namespace std;

const int MAXT=100+10;

int same[MAXT][MAXT];
int t1[MAXT];
int t2[MAXT];

inline int MAX(int a, int b){
	return (a<b)?b:a;	
}
inline int MAX(int a,int b, int c){
	return MAX(MAX(a,b),c);	
}

int main(){
	int kase=0;
	while(true){
		int n1,n2;
		cin>>n1>>n2;
		if(n1==0 && n2==0) break;
		++kase;
		for(int i=1;i<=n1;++i) cin>>t1[i];
		for(int i=1;i<=n2;++i) cin>>t2[i];
		for(int i=0;i<=n1;++i) same[i][0]=0;
		for(int i=0;i<=n2;++i) same[0][i]=0;
		for(int i=1;i<=n1;++i){
			for(int j=1;j<=n2;++j){				
				if(t1[i]==t2[j])
					same[i][j]=MAX(same[i-1][j],same[i][j-1],1+same[i-1][j-1]);
				else
					same[i][j]=MAX(same[i-1][j],same[i][j-1]);
			}
		}
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",kase,same[n1][n2]);
	}
	return 0;
}
