#include <iostream>
#include <queue>
using namespace std;

struct Frac {
	int h;
	int k;
	Frac() {}
	Frac(int h, int k) :h(h),k(k) {}
	bool operator>(const Frac& that) const {
		return h* that.k > that.h*k;
	}
};

int gcd(int a, int b) {
	while(a!=0) {
		int r=b%a;
		b = a;
		a = r;
	}
	return b;
}

int main() {
	while(true) {
		int n, k;
		if (!(cin>>n>>k)) break;
		priority_queue<Frac, vector<Frac>, greater<Frac> > heap;
		for (int i=1;i<=n;++i) heap.push(Frac(1,i));
		Frac f;
		for (int i=1;i<=k;++i) {
			f = heap.top();
			heap.pop();
			int den = f.k;
			for (int j=f.h+1;j<den;++j) {
				if (gcd(j, den)==1) {
					heap.push(Frac(j, den));
					break;
				}
			}
		}
		cout<<f.h<<"/"<<f.k<<endl;
	}
	return 0;
}