#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long  n;
	cin>>n;
	for(long long  i=0;i<n;i++){
		int x,y,d;
		cin>>x>>y;
		d=y-x;
		if (d==0) {cout<<0<<endl;continue;}
		int k=sqrt(d);				//There is round error!!!!!!!!!!
		int r=d-k*k;
		if(r<0) k--;
		if(r>k+k) k++;
		r=d-k*k;
		int s=k-1+k;
		if(r>0) s++;
		if(r>k) s++;
		cout<<s<<endl;
	}
	return 0;	
}
