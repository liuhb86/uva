#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vLength;
vector<int> vGroupLength;

void init() {
	vLength.push_back(0);
	vGroupLength.push_back(0);
	int start =1;
	for (int ndigits=1;;++ndigits) {
		int end = start*10;
		for (int k=start;k<end;++k) {
			vGroupLength.push_back(vGroupLength.back() + ndigits);
			int len = vLength.back() + vGroupLength.back();
			if (len<0) return; //overflow
			vLength.push_back(len);
		}
		start = end;
	}
}
int solve(int i) {
	int k = lower_bound(vLength.begin(), vLength.end(), i) - vLength.begin();
	i-= vLength[k-1];
	int n = lower_bound(vGroupLength.begin(), vGroupLength.end(), i) - vGroupLength.begin();
	i-= vGroupLength[n-1];
	int ndigit = vGroupLength[n] - vGroupLength[n-1];
	int j = ndigit - i;
	for (int t=0;t<j;++t) n/=10;
	return n%10;
}

int main() {
	init();
	int nkase = 0;
	cin>>nkase;
	for (int kase =0;kase<nkase;++kase) {
		int i;
		cin>>i;
		int r = solve(i);
		cout<<r<<endl;
	}
	return 0;
}
