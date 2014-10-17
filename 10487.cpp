#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int kase = 0;
	while(true) {
		int n;
		cin>>n;
		if (n==0) break;
		++kase;
		cout<<"Case "<<kase<<":"<<endl;
		vector<int> num;
		for (int i=0;i<n;++i) {
			int t;
			cin>>t;
			num.push_back(t);
		}
		sort(num.begin(), num.end());
		int m;
		cin>>m;
		for (int i=0;i<m;++i){
			int q;
			cin>>q;
			int cloest = num[0]+num[1];
			int diff = abs(cloest-q);
			for (int j=0;j<n-1;++j) {
				int k = lower_bound(num.begin()+j+1, num.end(), q-num[j]) - num.begin();
				if (k<n) {
					int t = num[j]+num[k];
					if (t-q<diff) {cloest=t; diff= t-q;}
				}
				if (k>j+1) {
					int t= num[j]+num[k-1];
					if (q-t<diff) {cloest = t; diff= q-t;}
				}
				if (diff==0 || num[j]>=q/2) break;
			}
			cout<<"Closest sum to "<<q<<" is "<<cloest<<"."<<endl;
		}
	}
	return 0;
}
