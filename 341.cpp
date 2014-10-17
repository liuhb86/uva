#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct E {
	int cost;
	int node;
	E(int c, int n):cost(c),node(n) {}
	bool operator<(const E& that) const {
		if (cost<0 && that.cost<0) return node<that.node;
		if (cost<0) return false;
		if (that.cost<0) return true;
		if (cost<that.cost) return true;
		if (cost>that.cost) return false;
		return node<that.node;
	}
};
int main() {
	int kase=0;
	int n;
	while(true) {
		cin>>n;
		if (n==0) break;
		++kase;
		vector<vector<int> > to(n);
		vector<vector<int> > delay(n);
		for (int i=0;i<n;++i) {
			int m;
			cin>>m;
			for (int j=0;j<m;++j) {
				int t,d;
				cin>>t>>d;
				to[i].push_back(t-1);
				delay[i].push_back(d);
			}
		}
		int src, dest;
		cin>>src>>dest;
		--src;--dest;
		vector<int> cost(n);
		vector<int> prev(n);
		for (int i=0;i<n;++i) cost[i]= -1;
		cost[src]=0;
		set<E> unvisited;
		for (int i=0;i<n;++i) unvisited.insert(E(cost[i], i));

		while(!unvisited.empty()) {
			int k = unvisited.begin()->node;
			unvisited.erase(E(cost[k],k));
			if (k==dest) break;
			if (cost[k]<0) break;
			for (int i=0;i<to[k].size();++i) {
				int t = to[k][i];
				if (cost[t] <0 || cost[t] > cost[k]+delay[k][i]) {
					unvisited.erase(E(cost[t],t));
					cost[t] = cost[k] + delay[k][i];
					prev[t] = k;
					unvisited.insert(E(cost[t], t));
				}
			}
		}

		vector<int> path;
		for (int k=dest; k!=src; k=prev[k]) path.push_back(k);
		path.push_back(src);
		reverse(path.begin(), path.end());

		cout<<"Case "<<kase<<": Path =";
		for (int i=0;i<path.size();++i) cout<<" "<<path[i]+1;
		cout<<"; "<<cost[dest]<<" second delay"<<endl;
	}
	return 0;
}
