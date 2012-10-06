#include <iostream>
#include <cmath>
using namespace std;

int main(){
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(10);
	double x1,y1,x2,y2,ax1,ax2,ay1,ay2,cx,cy;
	while(cin>>x1>>y1>>x2>>y2){
		if(x1==x2 && y1==y2) {cout<<"Impossible."<<endl;continue;}
		cx=(x1+x2)/2;
		cy=(y1+y2)/2;
		ax1=cx-(y1-cy);
		ax2=cx-(y2-cy);
		ay1=cy+(x1-cx);
		ay2=cy+(x2-cx);
		cout<<ax1<<" "<<ay1<<" "<<ax2<<" "<<ay2<<endl;
		
	}
	return 0;	
}
