#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double PI=4*atan(1);

int main(){
	int kase;
	cin>>kase;
	bool first=true;
	for(int i=0;i<kase;i++){
		if(first) first=false; else cout<<endl;
		float b,h;
		cin>>b>>h;
		float r=b*h/(sqrt(2*h*h+b*b)+b);
		float sumr=0,l=h;
		while(r>=1e-6){
			sumr+=r;
			l-=r+r;
			r=r*l/(l+r+r);
		}
		printf("%12.6lf\n",2*sumr*PI);
	}
	return 0;	
}
