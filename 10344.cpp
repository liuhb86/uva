#include <iostream>
#include <algorithm>
using namespace std;

int a[5+3];
bool success;
int result;

void solve(int idxOp){
	if(idxOp==5){
		if (result==23) success=true;
		return;
	}
	result+=a[idxOp]; solve(idxOp+1); result-=a[idxOp];
	if(success) return ;
	result-=a[idxOp]; solve(idxOp+1); result+=a[idxOp];
	if(success) return ;
	result*=a[idxOp]; solve(idxOp+1); result/=a[idxOp];
}

int main(){
	while(1){
		for(int i=0;i<5;++i) cin>>a[i];
		if(a[0]==0) break;
		sort(a,a+5);
		success=false;
		while(1){
			result=a[0];
			solve(1);
			if(success) break;
			if(!next_permutation(a,a+5)) break;
		}
		if(success) cout<<"Possible"<<endl;
		else cout<<"Impossible"<<endl;
	}	
	return 0;
}
