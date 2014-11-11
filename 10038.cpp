#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n;
	while(cin>>n) {
		if (n==0) {
			cout<<"Not jolly"<<endl;
			continue;
		}
		vector<bool> checked(n);
		int last;
		cin>>last;
		bool isJolly = true;
		int i;
		int k;
		for (i=1;i<n;++i) {
			cin>>k;
			int d = abs(k-last);
			if (d<1 || d>=n || checked[d]) {isJolly = false; break;}
			checked[d] = true;
			last = k;
		}
		for (i=i+1;i<n;++i) {cin>>k;}
		if (isJolly)
			cout<<"Jolly"<<endl;
		else
			cout<<"Not jolly"<<endl;
	}
	return 0;
}
