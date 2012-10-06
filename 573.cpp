#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long h,u,d,f;
	while(1){
		cin>>h>>u>>d>>f;
		if(h==0) break;
		h*=100;u*=100;d*=100;
		long long du=u/100*f;
		long long curh=0;
		long long n=0;
		while(1){
			n++;
			curh+=u;
			if(curh>h) {cout<<"success on day "<<n<<endl; break;}
			u-=du;
			if(u<0) u=0;
			curh-=d;
			if(curh<0) {cout<<"failure on day "<<n<<endl;break;}
		}
		
	}
	
	return 0;	
}
