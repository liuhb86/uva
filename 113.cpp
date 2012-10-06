#include <iostream>
#include <cmath>
using namespace std;

int main(){

	double d,dk;
	int n,k;
	while(cin>>n){
		cin>>d;
		dk=exp((log(d)/n));
		k=static_cast<int>(dk+.5 );
		cout<<k;
	}
	return 0;	
}
