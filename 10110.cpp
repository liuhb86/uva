//why signed yields ***TL****???????    ----2^32-1......
//
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	while(1){
		unsigned int n;
		cin>>n;
		//if(n<=0) break;
		if(n==0) return 0;
		unsigned int k=sqrt(n);	
		if(k*k<n) k++;
		if(k*k!=n) cout<<"no"<<endl; else cout<<"yes"<<endl;
	}
	return 0;	
}
