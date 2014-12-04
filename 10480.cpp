#include <iostream>
#include <deque>
#include <vector>
#include <map>
using namespace std;

const int target = 2;
int main() {
	while(true) {
		int n, m;
		cin>>n>>m;
		if (n==0 && m==0) break;
		vector<map<int, int> > edges(n+1);
		for (int i=0;i<m;++i) {
			int s,t,c;
			cin>>s>>t>>c;
			edges[s][t]=c;
			edges[t][s]=c;
		}
		vector<int> prev(n+1);
		while (true) {
			prev.assign(n+1, -1);
			deque<int> que;
			que.push_back(1);
			prev[1]=1;
			while(!que.empty()) {
				int s = que.front();
				que.pop_front();
				for (map<int, int>::iterator it=edges[s].begin(); it!=edges[s].end();++it) {
					if (it->second >0 && prev[it->first]<0) {
						prev[it->first] = s;
						que.push_back(it->first);
						if (it->first ==target) goto breakBFS;
					}
				}
			}
breakBFS:
			if (prev[target]<0) break;
			int inc = -1;
			for (int p=target; p!=1;) {
				int s = prev[p];
				int c = edges[s][p];
				if (inc<0 || c<inc) inc=c;;
				p=s;
			}
			for (int p=target; p!=1;) {
				int s = prev[p];
				edges[s][p] -= inc;
				edges[p][s]+=inc;
				p=s;
			}
		}
		for (int i=1;i<=n;++i) {
			if (prev[i]<0) continue;
			for (map<int, int>::iterator it=edges[i].begin(); it!=edges[i].end(); ++it) {
				if (prev[it->first]<0) cout<<i<<" "<<it->first<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}