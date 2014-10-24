#include <iostream>
#include <queue>
using namespace std;

int main() {
	while(true) {
		priority_queue<int> heap;
		int n;
		cin>>n;
		if (n==0) break;
		for (int i=0;i<n;++i) {
			int k;
			cin>>k;
			heap.push(-k);
		}
		int cost = 0;
		while(heap.size() > 1) {
			int a = heap.top(); heap.pop();
			int b = heap.top(); heap.pop();
			int c=a+b;
			cost -=c;
			heap.push(c);
		}
		cout<<cost<<endl;
	}
	return 0;
}