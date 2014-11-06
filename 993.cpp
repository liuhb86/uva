#include <iostream>
using namespace std;

int main() {
	int nkase;
	cin>>nkase;
	for (int kase=0;kase<nkase;++kase){
		int n;
		cin>>n;
		if (n==1) {cout<<1<<endl; continue;}
		int n2=0, n3=0;
		int r[10] ={0};
		while(n%2==0) {n/=2;++n2;}
		while(n%3==0) {n/=3;++n3;}
		while(n%5==0) {n/=5;++r[5];}
		while(n%7==0) {n/=7;++r[7];}
		if (n>1) {cout<<-1<<endl; continue;}
		r[8]=n2/3; n2=n2%3;
		r[4]=n2/2; n2=n2%2;
		r[9]=n3/2; n3=n3%2;
		if (n2 && n3) r[6]=1; else {r[2]=n2; r[3]=n3;}
		for (int i=2;i<10;++i) {
			for (int j=0;j<r[i];++j) cout<<i;
		}
		cout<<endl;
	}
	return 0;
}