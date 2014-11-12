#include <iostream>
using namespace std;

int buffer[100];

bool checkAndReverse(unsigned int k, unsigned int& r) {
	int n=0;
	while(k>0) {
		buffer[n++] = k%10;
		k/=10;
	}
	bool isPal = true;
	for (int i=0, j=n-1; i<j;++i,--j) {
		if (buffer[i]!=buffer[j]) {isPal = false; break;}
	}
	r = 0;
	for (int i=0;i<n;++i) {
		r = r*10+buffer[i];
	}
	return isPal;
}

int main() {
	int nkase;
	cin>>nkase;
	for (int kase=0;kase<nkase;++kase) {
		unsigned int k, r;
		cin>>k;
		int count = 0;
		while(true) {
			bool isPal = checkAndReverse(k, r);
			if (count>0 && isPal) break;
			++count;
			k+=r;
		}
		cout<<count<<" "<<k<<endl;
	}
	return 0;
}