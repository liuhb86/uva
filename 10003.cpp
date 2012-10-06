#include <iostream>
#include <cstdio>
using namespace std;

const int MAX=50+10;
int points[MAX];

int cost[MAX][MAX];

inline int min(int a, int b){
	return (a<=b)?a:b;	
}

int main(){
	while(true){
		int l,n;
		cin>>l;
		if (l==0) break;
		cin >>n;
		points[0] = 0;
		for(int i=1;i<=n;++i) cin>>points[i];
		points[n+1]=l;
		++n;

		int max_cost=l*n;
		for (int ss=1; ss<=n;++ss){
			cost[ss][1]=0;	
		}
		for(int ts=2;ts<=n;++ts){
			for( int ss=1;ss+ts-1<=n;++ss){
				int es=ss+ts-1;
				int min_cost = max_cost;
				for(int cs=1;cs<ts;++cs){
					int cur_cost = cost[ss][cs]+ cost[ss+cs][ts-cs];
					if(cur_cost<min_cost) min_cost=cur_cost;
				}
				cost[ss][ts]=min_cost+points[es]-points[ss-1];
			}
		}
		printf("The minimum cutting is %d.\n", cost[1][n]);
	}
	return 0;	
}
