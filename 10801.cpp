//10801 - Lift Hopping
//graph, SSSP, dijkstra

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

struct State{
	int floor;
	int value;
	bool operator < (State s) const{
		return value > s.value;
	}
};

struct Edge{
	int to;
	int value;
};
struct Floor{
	int d;
	//bool visited;
	vector<Edge> edges;
};

int elevator[10];
int stops[100+10];

int main(){
	int n,k;
	while(cin>>n>>k){
		Floor floors[100+10];
		priority_queue<State> pq;
		floors[0].d=0;
		for(int i=1;i<100;++i) floors[i].d=-1;
//		for(int i=0;i<100;++i) floors[i].visited = false;
		for(int i=0;i<n;++i) cin>>elevator[i];
		string ss;
		getline(cin,ss);
		for (int i=0;i<n;++i){
			getline(cin,ss);
			istringstream iss(ss);
			int nStops =0;
			while(iss>>stops[nStops]) nStops++;
			for(int x=0;x<nStops; ++x){
				for(int y=0;y<nStops; ++y){
					if (x==y) continue;
					Edge e;
					e.to = stops[y];
					e.value = abs(stops[y]- stops[x])*elevator[i]+60;
					floors[stops[x]].edges.push_back(e);
				}
			}
		}
		State s;
		s.floor =0; s.value = floors[0].d;
		pq.push(s);
		while(!pq.empty()){
			s = pq.top(); pq.pop();
			if (s.floor ==k) break;
			if (floors[s.floor].d<s.value) continue;
			//floors[s.floor].d = s.value;
			//floors[s.floor].visited= true;
			for (vector<Edge>::iterator it = floors[s.floor].edges.begin(); it!= floors[s.floor].edges.end(); ++it){
				State t;
				t.floor = it->to;
				t.value = s.value + it->value;
				if (floors[it->to].d <0 || t.value<floors[it->to].d) {
					pq.push(t);
					floors[it->to].d = t.value;
				}
			}
		}
		if (s.floor==k)
			cout<<((s.value==0)? 0:s.value-60)<<endl;
		else
			cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}