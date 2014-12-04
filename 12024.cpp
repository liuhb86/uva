// https://en.wikipedia.org/wiki/Derangement
#include <iostream>
using namespace std;

int f[13] ={1,0,1,2,9,44,265,1854,14833,133496,1334961,14684570,176214841};
int d[13] ={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};


//f(n)=n!-\sum_{i=1..n} {n}\choose{i}*f(n-i); f(0)=1;
//f(n)=(n-1)(f(n-1)+f(n-2)
//f(n={n!/e}
void generator() {
	f[0]=1; d[0]=1;
	for (int n=1;n<=12;++n) {
		d[n] = d[n-1]*n;
		f[n]=d[n];
		int b = 1;
		for (int i=1;i<=n;++i) {
			b = b*(n-i+1)/i;
			f[n]-=b*f[n-i];
		}
	}
	for(int i=0;i<=12;++i) cout<<f[i]<<",";
	cout<<endl;
	for(int i=0;i<=12;++i) cout<<d[i]<<",";

}

int main() {
	//generator();
	int nkase;
	cin>>nkase;
	for (int kase=0;kase<nkase;++kase) {
		int n;
		cin>>n;
		cout<<f[n]<<"/"<<d[n]<<endl;
	}
	return 0;
}