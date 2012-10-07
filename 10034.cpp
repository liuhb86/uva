#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const int MAX = 100+10;

struct Edge{
	int from;
	int to;
	double distance;
};

struct Node{
	double x;
	double y;
	Node* parent;
	int count;
};

Node nodes[MAX];
Edge edges[MAX*MAX];

double distance2(Node a, Node b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool cmp(Edge a, Edge b){
	return a.distance < b.distance;
}

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

int main(){
	int nkase;
	cin>>nkase;
	for (int kase = 0; kase<nkase; ++kase){
		if(kase>0) cout<<endl;
		int n;
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>nodes[i].x>>nodes[i].y;
			nodes[i].parent = nodes + i;
			nodes[i].count = 1;
		}
		
		int nEdge = 0;
		for(int i=0;i<n;++i){
			for(int j=i+1; j<n; ++j){
				Edge& e = edges[nEdge];
				e.from = i;
				e.to = j;
				e.distance = distance2(nodes[i], nodes[j]);
				++nEdge;
			}
		}
		sort(edges, edges +nEdge, cmp);
		
		double length = 0;
		for(int i=0, count=0; count<n-1; ++i){
			int s = edges[i].from, t = edges[i].to;
			Node *rs = getRoot(s), *rt = getRoot(t);
			if(rs == rt) continue;
			length += sqrt(edges[i].distance);
			if (rs->count > rt->count){
				rt->parent = rs;
				rs->count+=rt->count;
			} else {
				rs->parent = rt;
				rt->count += rs->count;
			}
			++count;
		}
		printf("%.2lf\n", length);
	
	}
	return 0;
}