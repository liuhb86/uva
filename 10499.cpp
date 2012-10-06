#include <iostream>
using namespace std;

int main(){
	long long n;
	while(1){
		cin>>n;
		if(n<0) break;
		if (n==1) {cout<<"0%"<<endl; continue;}
		n=n*1000/4+5;
		n/=10;
		cout<<n<<'%'<<endl;
	}	
	return 0;
}
