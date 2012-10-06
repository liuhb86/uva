#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(3);
	while(1){
		int h,m;
		scanf("%d:%d",&h,&m);
		if(h==0 && m==0) break;
		int d1=h*30*2+m*1;
		int d2=m*6*2;
		if (d1<d2) d1+=360*2;
		int d=d1-d2;
		if(d>=180*2) d=360*2-d;
		cout<<d/(2.0)<<endl;
	}
	return 0;	
}
