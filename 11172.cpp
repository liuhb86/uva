#include <iostream>
using namespace std;

int main() {
	int nkase;
	cin>>nkase;
	for (int kase=0;kase<nkase;++kase) {
		int a,b;
		cin>>a>>b;
		if (a<b) cout<<"<";
		else if (a>b) cout<<">";
		else cout<<"=";
		cout<<endl;
	}
	return 0;
}