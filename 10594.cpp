#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

struct Entry{
	long long d;
	int node;
	Entry(){}
	Entry(long long d, int node):d(d), node(node){}
	bool operator> (const Entry& that) const {
		return d>that.d;
	}
};

struct EdgeInfo {
	long long delay;
	int capacity;
	EdgeInfo() {}
	EdgeInfo(long long d, int c) : delay(d), capacity(c) {}
};

const long long INF = LONG_LONG_MAX;

int main() {
	while(true) {
		int n,m;
		if (!(cin>>n>>m)) break;
		vector<map<int, EdgeInfo> > edges(n+1);
		for (int i=0;i<m;++i) {
			int s,t;
			long long d;
			cin>>s>>t>>d;
			edges[s][t] = EdgeInfo(d,1);
			edges[t][s] = EdgeInfo(d,1);
		}
		int d,k;
		cin>>d>>k;
		long long time = 0;
		bool possible = true;
		while(d>0) {
			vector<long long> dis(n+1, INF);
			vector<int> prev(n+1);
			vector<bool> inqueue(n+1);
			dis[1] = 0;
			deque<int> que;
			que.push_back(1);
			while(!que.empty()) {
				int node = que.front();
				que.pop_front();
				inqueue[node] = false;
				map<int, EdgeInfo>& eg = edges[node];
				for (map<int, EdgeInfo>::iterator it =eg.begin(); it!=eg.end();++it) {
					if (it->second.capacity<=0) continue;
					int t=it->first;
					int delay = it->second.delay;
					if (dis[t]==INF || dis[node]+delay < dis[t]) {
						dis[t] = dis[node]+delay;
						prev[t] = node;
						if (!inqueue[t]) {
							que.push_back(t);
							inqueue[t] = true;
						}
					}
				}
			}
			if (dis[n]==INF) possible = false;
			if (!possible) break;
			int minCap = -1;
			for (int node=n;node!=1;) {
				int p=prev[node];
				int cap = edges[p][node].capacity;
				if (minCap<0 || cap<minCap) minCap=cap;
				node = p;
			}
			for (int node=n;node!=1;) {
				int p = prev[node];
				edges[node][p].capacity+=minCap;
				edges[p][node].capacity-=minCap;
				int c = edges[p][node].capacity;
				long long w = abs(edges[p][node].delay);
				edges[p][node].delay = (c<=1) ? w : -w;
				edges[node][p].delay = (c>=1) ? w : -w;
				node = p;
			}
			time += dis[n] *min(d,k*minCap);
			d-= k*minCap;
		}
		if (possible) cout<<time<<endl;
		else cout<<"Impossible."<<endl;
	}
	return 0;
}