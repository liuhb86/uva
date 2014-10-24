#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int nkase;
	cin>>nkase;
	for (int kase=0; kase<nkase;++kase){
		int len, n;
		cin>>len>>n;
		int minTime = 0;
		int maxTime = 0;
		for (int i=0;i<n;++i) {
			int pos;
			cin>>pos;
			int tMin = min(pos, len-pos);
			int tMax = max(pos, len-pos);
			minTime=max(minTime, tMin);
			maxTime=max(maxTime, tMax);
		}
		cout<<minTime<<" "<<maxTime<<endl;
	}
	return 0;
}