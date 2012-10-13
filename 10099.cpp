//10099 - The Tourist Guide
//graph, MST
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
	int from;
	int to;
	int weight;
	bool operator < (Edge b) const {
		return weight > b.weight;
	}
};

typedef vector<Edge> Vec;

struct Node{
	Node* parent;
	int count;
	Vec edges;
};

Node nodes[100+10];
Vec edges;

Node* getRoot(int i){
	Node* p = nodes[i].parent;
	Node* q;
	while(p!=p->parent){
		q = p->parent;
		p->parent = q->parent;
		p = q;
	}
	nodes[i].parent = p;
	return p;
}

struct CalcResult{
	bool reached;
	int value;
};

CalcResult calc(int s, int t, int p){
	CalcResult r;
	r.reached = false;
	if (s == t) {
		r.reached = true;
		r.value = -1;
		return r;
	}
	for (Vec::iterator it=nodes[s].edges.begin(); it!=nodes[s].edges.end(); ++it){
		if (it->to == p) continue;
		r = calc(it->to, t, s);
		if (r.reached) {
			if (it->weight<r.value || r.value<0) r.value= it->weight;
			return r;
		}
	}
	return r;
}


int main(){
	int kase =0;
	while(true){
		int n,r;
		cin>>n>>r;
		if (n==0) break;
		++kase;
		edges.clear();
		for(int i=0;i<r;++i){
			Edge e;
			cin>>e.from>>e.to>>e.weight;
			edges.push_back(e);
		}
		sort(edges.begin(), edges.end());
		for(int i=1;i<=n;++i){
			nodes[i].parent = nodes+i;
			nodes[i].count = 1;
			nodes[i].edges.clear();
		}
		int count =0;
		for(Vec::iterator it = edges.begin(); count< n-1 && it!= edges.end(); ++it){
			Node *rs = getRoot(it->from), *rt = getRoot(it->to);
			if(rs == rt) continue;
			if (rs->count > rt->count){
				rt->parent = rs;
				rs->count+=rt->count;
			} else {
				rs->parent = rt;
				rt->count += rs->count;
			}
			++count;

			nodes[it->from].edges.push_back(*it);
			int tmp = it->to;
			it->to = it->from; it->from =tmp;
			nodes[it->from].edges.push_back(*it);
		}
		int s,d,t;
		cin>>s>>d>>t;
		cout<<"Scenario #"<<kase<<endl;		
		CalcResult result = calc(s,d,0);
		int nTrips;
		if (result.value<0){ //s==d
			nTrips = 1;
		} else {
			result.value -=1;
			nTrips = t/result.value;
			if (t%result.value !=0) nTrips +=1;
		}
		cout<<"Minimum Number of Trips = "<<nTrips<<endl;
		cout<<endl;
	}
	return 0;
}