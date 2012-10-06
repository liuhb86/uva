#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
	int n;
	while (1){
		int x,y;
		cin>>n;
		if(n==0) break;
		n=n-1;
		int base=static_cast<int>(sqrt(n));
		int r=n-base*base;
		//cout<<base<<" "<<r<<endl;
		if (r<base){
			x=base;
			y=r;
		}else{
			y=base;
			x=2*base-r;	
		}
		if(base%2==1) {int temp=x;x=y;y=temp;}
		cout<<x+1<<" "<<y+1<<endl;
		
	}
	return 0;	
}
