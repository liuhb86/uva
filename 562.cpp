#include <iostream>
#include <cstring>
using namespace std;

const int MAX_M=100+10;
const int MAX_COUNT=100*500/2+10;
int counts[MAX_M][MAX_COUNT];
int coins[MAX_M];

int compute(int m, int limit){
	if(m<0 || limit<=0) return 0;
	if(counts[m][limit]>=0) return counts[m][limit];
	counts[m][limit]=compute(m-1,limit);
	if(coins[m]<=limit){ 
		int v2=compute(m-1,limit-coins[m])+coins[m];
		if(v2>counts[m][limit]) counts[m][limit]=v2;
	}
	return counts[m][limit];
}

int main(){
	int kase;
	cin>>kase;
	for(int i=0;i<kase;++i){
		int sum=0,half;
		int result;
		int m;
		cin>>m;
		for(int j=0;j<m;++j){
			cin>>coins[j];
			sum+=coins[j];
		}
		half=sum/2;
		memset(counts,-1,sizeof(counts));
		result=compute(m-1, half);
		cout<<sum-2*result<<endl;
	}
	return 0;	
}
