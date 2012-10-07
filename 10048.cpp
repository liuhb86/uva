#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
	int from;
	int to;
	int weight;
	bool operator < (Edge b) const {
		return weight<b.weight;
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

struct CalcResult{
	bool reached;
	int value;
};

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

CalcResult calc(int s, int t, int p){
	CalcResult r;
	r.reached = false;
	if (s == t) {
		r.reached = true;
		r.value = 0;
		return r;
	}
	for (Vec::iterator it=nodes[s].edges.begin(); it!=nodes[s].edges.end(); ++it){
		if (it->to == p) continue;
		r = calc(it->to, t, s);
		if (r.reached) {
			if (it->weight>r.value) r.value= it->weight;
			return r;
		}
	}
	return r;
}

int main(){
	int kase =0;
	while(true){
		int c,s,q;
		cin>>c>>s>>q;
		if (c==0) break;
		++kase;
		edges.clear();
		for(int i=0;i<s;++i){
			Edge e;
			cin>>e.from>>e.to>>e.weight;
			edges.push_back(e);
		}
		sort(edges.begin(), edges.end());
		for(int i=1;i<=c;++i){
			nodes[i].parent = nodes+i;
			nodes[i].count = 0;
			nodes[i].edges.clear();
		}
		int count =0;
		for(Vec::iterator it = edges.begin(); count< c-1 && it!= edges.end(); ++it){
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
		if (kase >1) cout<<endl;
		cout<<"Case #"<<kase<<endl;
		for(int i=0;i<q; ++i){
			int s,t;
			cin>>s>>t;
			CalcResult result = calc(s,t,0);
			if (result.reached) {
				cout<<result.value<<endl;
			} else {
				cout<<"no path"<<endl;
			}
		}
	}
	return 0;
}