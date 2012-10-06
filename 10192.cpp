#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXT=100+10;

int same[MAXT][MAXT];
char t1[MAXT];
char t2[MAXT];

inline int MAX(int a, int b){
	return (a<b)?b:a;	
}
inline int MAX(int a,int b, int c){
	return MAX(MAX(a,b),c);	
}

int main(){
	int kase=0;
	char* s1=t1+1;
	char* s2=t2+1;
	while(true){
		int n1,n2;
		cin.getline(s1,MAXT-1);
		if(s1[0]=='#') break;
		cin.getline(s2,MAXT-1);
		++kase;
		n1=strlen(s1);
		n2=strlen(s2);
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

		printf("Case #%d: you can visit at most %d cities.\n",kase,same[n1][n2]);
	}
	return 0;
}
