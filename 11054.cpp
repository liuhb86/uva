#include <iostream>
using namespace std;

int main() {
	while(true) {
		int n;
		cin>>n;
		if (n==0) break;
		long long cost = 0;
		long long balance = 0;
		for (int i=0;i<n;++i) {
			cost+=abs(balance);
			long long a;
			cin>>a;
			balance+=a;
		}
		cout<<cost<<endl;
	}
	return 0;
}