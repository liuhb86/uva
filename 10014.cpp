#include <iostream>
//#include <cmath>
using namespace std;

/*
an+ =2an+2cn-an-;
an+-an=an-an- + 2cn;
let bn=an+-an;
bn=bn-+cn;
bn=\sum cn +b0;
\sumbn=an+-a0=\sum\sum cn+b0.
b0=a1-a0 is solvable.
*/

//double a[1000+10];
double c[3000+100];
int main(){
	int kase;
	cin>>kase;
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	int first=true;
	for(int i=0;i<kase;i++){
		if(first)first=false; else cout<<endl;
		int n;
		cin>>n;	
		double a0,ae;
		cin>>a0>>ae;
		for(int i=1;i<=n;i++) cin>>c[i];
		double sum=0;
		for(int i=1;i<=n;i++) sum+=2*c[i]*(n+1-i);
		double b0=(ae-a0-sum)/(n+1);
		//a[0]=a0;a[1]=a0+b0;a[n+1]=ae;
		//for(int i=1;i<n;i++) a[i+1]=2*a[i]+2*c[i]-a[i-1];
		//if(n>0 && fabs(a[n]*2+2*c[n]-a[n-1]-ae)>1e-5) cout<<"err"<<endl;
		cout<<a0+b0<<endl;
	}
}
