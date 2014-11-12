#include  <iostream>
using namespace std;

int main() {
	int nkase;
	cin>>nkase;
	for (int kase=1;kase<=nkase;++kase) {
		int a,b;
		cin>>a>>b;
		if (a%2==0) ++a;
		if (b%2==0) --b;
		int s;
		if (a>b) {
			s=0;
		} else {
			int n = (b-a)/2 + 1;
			s = (a+b) * n /2;
		}
		cout<<"Case "<<kase<<": "<<s<<endl;
	}
	return 0;
}