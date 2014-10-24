#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Job {
	double r;
	int index;
	bool operator<(const Job& that){ return r>that.r; }
};

int main() {
	int nkase;
	cin>>nkase;
	for (int kase=0;kase<nkase;++kase) {
		int n;
		cin>>n;
		vector<Job> jobs;
		for (int i=0;i<n;++i) {
			int t, p;
			cin>>t>>p;
			jobs.push_back(Job());
			jobs.back().r=static_cast<double>(p)/t;
			jobs.back().index = i+1;
		}
		sort(jobs.begin(), jobs.end());
		if (kase>0) cout<<endl;
		for (int i=0;i<n;++i) {
			if (i>0) cout<<" ";
			cout<<jobs[i].index;
		}
		cout<<endl;
	}
}