#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solve(vector<int>& books, int k,long long limit) {
	long long  sum = 0;
	for (int i=0;i<books.size() && k>0;++i) {
		if (sum+books[i]<=limit) {
			sum+=books[i];
		} else {
			--k; --i;
			sum = 0;
		}
	}
	return k>0;
}

int main() {
	int nkase;
	cin>>nkase;
	for (int kase=0;kase<nkase;++kase) {
		int m, k;
		cin>>m>>k;
		vector<int> books(m);

		long long begin=0, end=0;
		for (int i=0;i<m;++i) {
			cin>>books[i];
			if (books[i] > begin) begin=books[i];
			end+=books[i];
		}

		while (begin<end) {
			long long middle = begin + (end-begin)/2;
			if (solve(books, k, middle)) {
				end = middle;
			} else {
				begin= middle + 1;
			}
		}
		long long minT = begin;

		set<int> splits;
		int s=m-1;
		for (int i=k-1;i>0;--i) {
			long long sum = books[s--];
			while (s>=i && sum+books[s]<=minT) {sum+=books[s];--s;}
			splits.insert(s+1);
		}
		for (int i=0;i<m;++i) {
			if (splits.find(i)!=splits.end()) cout<<" /";
			if (i>0) cout<<" ";
			cout<<books[i];
		}
		cout<<endl;
	}
	return 0;
}