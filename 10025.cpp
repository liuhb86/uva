#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		if(i!=0) cout<<endl;
		int k;
		cin>>k;
		if(k==0){ cout<<3<<endl; continue;}
		if(k<0) k=-k;
		int up=(sqrt(1+8.0*k)-1)/2;
		if(up*(up+1)/2<k) up++;
		int sum=up*(up+1)/2;
		if((k-sum)%2==0) cout<<up<<endl;
		else if(up%2==0) cout<<up+1<<endl;
		else cout<<up+2<<endl;
	}
	return 0;	
}
