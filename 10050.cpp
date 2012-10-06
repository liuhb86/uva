#include <iostream>
using namespace std;

int hartals[100+20];
int main(){
	int kase;
	cin>>kase;
	for(int i=0;i<kase;i++){
		int n_days;
		cin>>n_days;
		int n_parties;
		cin>>n_parties;
		for(int j=0;j<n_parties;++j){
			cin>>hartals[j];
		}
		int lose=0;
		for(int j=1;j<=n_days;++j){
			//cout<<j<<" "<<lose<<endl;
			if(j%7==6 || j%7==0) continue;
			for(int k=0;k<n_parties;++k){
				if(j%hartals[k]==0) {++lose; break;}
			}
		}
		cout<<lose<<endl;
	}
	
	return 0;
}
