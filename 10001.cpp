#include <iostream>
using namespace std;

int rule[2][2][2];
int cellular[100];
int ancestor[100];
int n;

bool solve(int i){
	//cout<<"***"<<i<<endl;
	if(i==n){
		//cout<<"---"<<endl;
		//cout<<rule[ancestor[i-1]][ancestor[0]][ancestor[1]]<<" "<<cellular[i]<<endl;
		if(rule[ancestor[i-2]][ancestor[i-1]][ancestor[0]]!=cellular[i-1]) return false;
		if(rule[ancestor[i-1]][ancestor[0]][ancestor[1]]!=cellular[i]) return false;
		return true;
	}
	for(int j=0;j<2;++j){
		if(rule[ancestor[i-2]][ancestor[i-1]][j]==cellular[i-1]){
			ancestor[i]=j;
			if (solve(i+1)) return true;
		}
	}
	return false;
}
int main(){
	int identifier;
	while(cin>>identifier){
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k){
					rule[i][j][k]=identifier%2;
					//cout<<i<<j<<k<<" "<<rule[i][j][k]<<endl;
					identifier/=2;
				}
		cin>>n;
		for(int i=1;i<=n;++i){
			char c;
			cin>>c;
			cellular[i]=c-'0';
			//cout<<cellular[i];
		}
		//cout<<endl;
		bool gardenOfEden=true;
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k){
					if(rule[i][j][k]!=cellular[1]) continue;
					ancestor[0]=i;ancestor[1]=j;ancestor[2]=k;
					if(solve(3)){
						gardenOfEden=false;
						goto break1;
					}
				}
break1:
		if(gardenOfEden) cout<<"GARDEN OF EDEN"<<endl;
		else {cout<<"REACHABLE"<<endl;
			//for(int i=1;i<n;++i) cout<<ancestor[i];
			//cout<<ancestor[0]<<endl;
		}
	}
	return 0;
}
