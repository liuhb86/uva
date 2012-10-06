#include <iostream>
#include <iomanip>
using namespace std;

int gcd(int a,int b){
	while(1){
		int r=a%b;
		if(r==0) break;
		a=b;b=r;
	}
	return b;
}
int main(){
	int step,mod;
	while(cin>>step>>mod){
		cout<<setw(10)<<step<<setw(10)<<mod<<setw(4)<<' ';
		if(gcd(step,mod)>1) cout<<"Bad Choice"<<endl<<endl;
		else cout<<"Good Choice"<<endl<<endl;
	}
	return 0;	
}
