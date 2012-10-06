#include <iostream>
#include <cmath>
using namespace std;

const double PI=4*atan(1);

int main(){
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	while(1){
		int a,b,s,m,n;
		cin>>a>>b>>s>>m>>n;
		if(a==0 &&b==0 && s==0 && m==0  && n==0) break;
		double A,v;
		if(a*m==0) A=90.0; else A=atan((double)b*n/(a*m))/PI*180;
		v=sqrt(((double)a)*m*a*m+((double)b)*n*b*n)/s;
		cout<<A<<" "<<v<<endl;
	}
	return 0;	
}
