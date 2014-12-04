#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
	while(b!=0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	int nkase;
	cin>>nkase;
	string line;
	std::getline(cin, line);
	for (int kase=0; kase<nkase;++kase) {
		std::getline(cin, line);
		istringstream iss(line);
		vector<int> n;
		int t;
		while(iss>>t) n.push_back(t);
		int maxd = 1;
		for (int i=0;i<n.size();++i) {
			for (int j=i+1; j<n.size();++j) {
				int d=gcd(n[i], n[j]);
				maxd=max(maxd,d);
			}
		}
		cout<<maxd<<endl;
	}
	return 0;
}