//10130 - SuperSale
//DP, pack

#include <iostream>
#include <cstring>
using namespace std;

int weights[1000+5];
int prices[1000+5];
int N,G;
int solution[1000+5][30+5];

int solve(int m,int n){
	if (n<0) return 0;
	if (m<=0) return 0;
	if (solution[n][m]>0) return solution[n][m];
	int sol = solve(m,n-1);
	if (weights[n]<=m){
		int sol2=solve(m-weights[n],n-1)+prices[n];
		if (sol2>sol) sol=sol2;
	}
	solution[n][m]=sol;
	return sol;
}

int main(){
	int nkase;
	cin>>nkase;
	for(int kase=0;kase<nkase;++kase){
		memset(solution,-1,sizeof(solution));
		cin>>N;
		for(int i=0;i<N; ++i){
			cin>>prices[i]>>weights[i];
		}
		cin>>G;
		int sum=0;
		for(int i=0;i<G;++i){
			int m;
			cin>>m;
			sum+=solve(m,N-1);
		}
		cout<<sum<<endl;
	}
	return 0;
}