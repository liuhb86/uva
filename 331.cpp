#include <iostream>
using namespace std;

int a[10];
int n;
int numSol;

void solve(){
	bool swapped=false;
	for(int i=1;i<n;++i){
		if(a[i]<a[i-1]){
			swapped=true;
			int t=a[i]; a[i]=a[i-1]; a[i-1]=t;
			solve();
			a[i-1]=a[i]; a[i]=t;
		}
	}
	if(!swapped) ++numSol;
}
int main(){
	int kase=0;
	while(1){
		cin>>n;
		if(n==0) break;
		++kase;
		for(int i=0;i<n;++i) cin>>a[i];
		bool ordered=true;
		for(int i=1;i<n;++i) if(a[i]<a[i-1]){ordered=false;break;}
		numSol=0;
		if(!ordered)	solve();
		cout<<"There are "<<numSol<<" swap maps for input data set "<<kase<<"."<<endl;	
	}
	return 0;	
}
