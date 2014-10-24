#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Seg {
	int start;
	int end;
	bool operator<(const Seg& that) const {
		return end<that.end;
	}
};

bool comp(const Seg& seg, const int m){
	return seg.end<m;
}

int main() {
	int nkase;
	cin>>nkase;
	for (int kase=0;kase<nkase;++kase) {
		int m;
		cin>>m;
		vector<Seg> segments;
		while(true) {
			segments.push_back(Seg());
			cin>>segments.back().start>>segments.back().end;
			if (segments.back().start==0 && segments.back().end==0) {
				segments.pop_back();
				break;
			}
		}
		sort(segments.begin(), segments.end());

		bool covered = true;
		vector<Seg> result;
		while(m>0) {
			vector<Seg>::iterator it = lower_bound(segments.begin(), segments.end(), m, comp);
			if (it==segments.end()) {
				covered = false;
				break;
			}
			int k=it-segments.begin();
			Seg minStart = segments[k];
			for (int i=k+1;i<segments.size();++i) {
				if (segments[i].start < minStart.start) minStart = segments[i];
			}
			segments.resize(k);
			m=minStart.start;
			result.push_back(minStart);
		}

		if (kase>0) cout<<endl;
		if (!covered) cout<<0<<endl;
		else {
			cout<<result.size()<<endl;
			for (vector<Seg>::reverse_iterator it = result.rbegin(); it!=result.rend();++it) cout<<it->start<<" "<<it->end<<endl;
		}
	}
}