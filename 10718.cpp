#include <iostream>
using namespace std;

int main() {
	unsigned int n;
	while(cin>>n) {
		unsigned int l, u;
		cin>>l>>u;
		unsigned int m=0;
		unsigned int bitmask = 1<<31;
		for (int i=0;i<32;++i){
			if ((l&bitmask) && m<l) {
				m= m|bitmask;
			}
			else if ((n&bitmask)==0) {
				unsigned int t = m | bitmask;
				if (t>=l && t<=u) {
					m=t;
				}
			}
			bitmask>>=1;
		}
		if (m<l) m=l;
		cout<<m<<endl;
	}
	return 0;
}