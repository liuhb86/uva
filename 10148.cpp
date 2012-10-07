#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct Interval{
	int start;
	int end;
};

bool cmp(Interval a, Interval b){
	return a.end<b.end;
}

Interval joggers[1000+10];
int adcount[1000+10];
set<int> ads;

int main() {
	int nkase;
	cin>>nkase;
	for (int kase = 0; kase<nkase; ++kase){
		ads.clear();
		int k,n;
		cin>>k>>n;
		for(int i=0;i<n;++i){
			int t1,t2;
			cin>>t1>>t2;
			if(t1<=t2) {
				joggers[i].start=t1;
				joggers[i].end=t2;
			} else {
				joggers[i].start = t2;
				joggers[i].end = t1;
			}
			adcount[i]=0;
		}
		sort(joggers,joggers+n,cmp);

		for(int i=0;i<n;++i){
			//cout<<endl<<i<<" "<<joggers[i].start<<" "<<joggers[i].end<<" "<<adcount[i]<<endl;
			int remaining = k-adcount[i];
			for(int j = joggers[i].end; remaining>0 && j>=joggers[i].start; --j){
				if(ads.count(j)>0){
					continue;
				} else {
					ads.insert(j);
					//cout<<j<<" ";
					--remaining;
					for(int z = i+1; z<n; ++z){
						if (!(j<=joggers[z].end)) break;
						if (j>=joggers[z].start) adcount[z]++;
					}
				}
			}
		}
		if(kase !=0) cout<<endl;
		cout<<ads.size()<<endl;
		for(set<int>::iterator it = ads.begin(); it!=ads.end(); ++it)
			cout<<*it<<endl;
	} 
	return 0;
}