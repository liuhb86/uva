#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Seg{
	double start;
	double end;
	bool operator<(const Seg& that) const {
		return end<that.end;
	}
};

bool operator<(Seg& s, double d) {
	return s.end<d;
}

int main() {
	int n;
	while(cin>>n) {
		double l, w;
		cin>>l>>w;
		w/=2;
		vector<Seg> sprinklers;
		for (int i=0;i<n;++i) {
			double p, r;
			cin>>p>>r;
			if (r<w) continue;
			double d=sqrt(r*r-w*w);
			sprinklers.push_back(Seg());
			sprinklers.back().start = p-d;
			sprinklers.back().end = p + d;
		}
		sort(sprinklers.begin(), sprinklers.end());
		int count = 0;
		bool possible = true;
		while (l>0) {
			vector<Seg>::iterator begin = lower_bound(sprinklers.begin(), sprinklers.end(), l);
			if (begin==sprinklers.end()) {possible = false; break;}
			++count;
			double furthest = l;
			for (vector<Seg>::iterator it=begin; it!=sprinklers.end(); ++it) {
				furthest = min(furthest, it->start);
			}
			l = furthest;
			sprinklers.resize(begin-sprinklers.begin());
		}
		if (possible)
			cout<<count<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}