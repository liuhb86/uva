#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Agency {
	int cost;
	string name;
	bool operator<(const Agency& that) const {
		if (cost < that.cost) return true;
		if (cost > that.cost) return false;
		return name < that.name;
	}
};

int main() {
	int nkase;
	cin>>nkase;
	for (int kase = 1; kase<=nkase;++kase) {
		int n, m, l;
		cin>>n>>m>>l;
		string t;
		std::getline(cin, t);
		vector<Agency> agencies(l);
		for (int i=0;i<l;++i) {
			string name;
			int a,b;
			std::getline(cin, name, ':');
			cin>>a;

			std::getline(cin,t, ',');
			cin>>b;
			std::getline(cin, t);
			int r = n;
			int cost = 0;
			while(r!=m) {
				int h = r/2;
				if (h>=m && b < (r-h)*a) {
					cost += b;
					r = h;
				} else {
					cost += (r-m)*a;
					break;
				}
			}
			agencies[i].cost = cost;
			agencies[i].name=name;
		}
		sort(agencies.begin(), agencies.end());
		cout<<"Case "<<kase<<endl;
		for (int i=0;i<agencies.size();++i) {
			cout<<agencies[i].name<<" "<<agencies[i].cost<<endl;
		}
	}
	return 0;
}