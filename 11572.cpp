#include <iostream>
#include <unordered_set>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	int nkase;
	cin>>nkase;
	for (int kase=0;kase<nkase;++kase) {
		int n;
		cin>>n;
		int start = 0;
		int longest = 0;
		unordered_set<long long> hash;
		deque<long long> numbers;
		for (int i=0;i<n;++i) {
			long long k;
			cin>>k;
			numbers.push_back(k);
			if (hash.find(k)==hash.end()) {
				longest = max(longest, static_cast<int>(numbers.size()));
				hash.insert(k);
			} else {
				while(true) {
					if (numbers.front()==k) {
						numbers.pop_front();
						break;
					}
					hash.erase(numbers.front());
					numbers.pop_front();
				}
			}
		}
		cout<<longest<<endl;
	}
	return 0;
}