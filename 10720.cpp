//ref: http://en.wikipedia.org/wiki/Erd%C5%91s%E2%80%93Gallai_theorem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b){return a>b;}

int main () {
	while(true) {
		int n;
		cin>>n;
		if (n==0) break;
		vector<int> degrees(n);
		for (int i=0;i<n;++i) cin>>degrees[i];
		sort(degrees.begin(), degrees.end(), comp);
		int sum = 0;
		for (int i=0;i<n;++i) sum+=degrees[i];
		bool possible = false;
		if (sum%2==0) {
			possible = true;
			sum = 0;
			for (int k=0;k<n;++k) {
				sum+=degrees[k];
				int sum2 = 0;
				for (int i=k+1;i<n;++i) {
					sum2+=min(degrees[i], k+1);
				}
				if (sum>(k+1)*k +sum2) {
					possible=false; 
					break;}
			}
		}

		if (possible) cout<<"Possible"<<endl;
		else cout<<"Not possible"<<endl;
	}
	return 0;
}