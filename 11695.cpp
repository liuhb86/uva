#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	vector<Node*> children;
	int index;
};

struct Info {
	int depth;
	int diameter;
	Node* diaRoot;
	Node* dchild1;
	Node* dchild2;
};

void depth(Node* node, Node* parent, vector<Info>& infos) {
	for (int i=0;i<node->children.size();++i) {
		if (node->children[i]==parent) continue;
		depth(node->children[i], node, infos);
	}
	
	Info& info = infos[node->index];
	info.diaRoot = NULL;
	info.dchild1 = NULL;
	info.dchild2 = NULL;
	for (int i=0;i<node->children.size();++i) {
		Node* child = node->children[i];
		if (child==parent) continue;
		Info& cinfo = infos[child->index];
		if (info.diaRoot == NULL || cinfo.diameter > infos[info.diaRoot->index].diameter) {
			info.diaRoot = cinfo.diaRoot;
		}
		
		if (info.dchild1==NULL || cinfo.depth>infos[info.dchild1->index].depth) {
			info.dchild2 = info.dchild1;
			info.dchild1 = child;
		} else if (info.dchild2==NULL || cinfo.depth > infos[info.dchild2->index].depth) {
			info.dchild2 = child;
		}
	}
	
	info.depth = info.dchild1 ? infos[info.dchild1->index].depth + 1 : 0;
	int d = info.dchild1 ? infos[info.dchild1->index].depth + 1 : 0;
	if (info.dchild2) d+= infos[info.dchild2->index].depth + 1;
	if (info.diaRoot==NULL || d>infos[info.diaRoot->index].diameter) {
		info.diaRoot = node;
		info.diameter = d;
	} else {
		info.diameter = infos[info.diaRoot->index].diameter;
	}
}

void getLongestPath(Node* root, vector<Info>& infos, vector<Node*>& path) {
	Node* p = infos[root->index].dchild1;
	while(p) {
		path.push_back(p);
		p = infos[p->index].dchild1;
	}
	reverse(path.begin(), path.end());
	path.push_back(root);
	p = infos[root->index].dchild2;
	while(p) {
		path.push_back(p);
		p = infos[p->index].dchild1;
	}
}

int main() {
	int nkase;
	cin>>nkase;
	for (int kase = 0; kase < nkase; ++kase) {
		int n;
		cin>>n;
		vector<Node> nodes(n+1);
		for (int i=1;i<=n;++i) nodes[i].index = i;
		for (int i=0;i<n-1;++i) {
			int from, to;
			cin>>from>>to;
			nodes[from].children.push_back(&nodes[to]);
			nodes[to].children.push_back(&nodes[from]);
		}
		Node* root = &nodes[1];
		vector<Info> info(n+1);
		depth(root, NULL, info);
		vector<Node*> path;
		getLongestPath(info[1].diaRoot, info, path);
		vector<Info> info1(n+1);
		depth(path.back(), NULL, info1);
		vector<Info> info2(n+1);
		depth(path.front(), NULL, info2);
		int length = path.size();
		int bestCut;
		int minPath;
		for (int i=0;i<length -1; ++i) {
			int d1 = info1[path[i]->index].diameter;
			int d2 = info2[path[i+1]->index].diameter;
			int pathLength = 1+ (d1+1)/2 + (d2+1)/2;
			pathLength = max(pathLength, max(d1,d2));
			if (i==0 || pathLength<minPath) {
				minPath = pathLength;
				bestCut = i;
			}
		}
		cout<<minPath<<endl;
		cout<<path[bestCut]->index<<" "<<path[bestCut+1]->index<<endl;
		depth(path[bestCut], path[bestCut+1], info1);
		vector<Node*> path1;
		getLongestPath(path[bestCut], info1, path1);
		cout<<path1[path1.size()/2]->index<<" ";
		depth(path[bestCut+1], path[bestCut], info2);
		vector<Node*> path2;
		getLongestPath(path[bestCut+1], info2, path2);
		cout<<path2[path2.size()/2]->index<<endl;
	}
	return 0;
}