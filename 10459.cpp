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

void getNodesAtDepth(Node* node, Node* parent, int depth, int target, set<int>& result) {
	if (depth==target) {
		result.insert(node->index);
		return;
	}
	for (int i=0;i<node->children.size(); ++i) {
		if (node->children[i]==parent) continue;
		getNodesAtDepth(node->children[i], node, depth+1, target, result);
	}
}

int main() {
	int n;
	while(cin>>n) {
		vector<Node> nodes(n+1);
		for (int i=1;i<=n;++i) {
			nodes[i].index = i;
			int m;
			cin>>m;
			for (int j=0;j<m;++j) {
				int to;
				cin>>to;
				nodes[i].children.push_back(&nodes[to]);
			}
		}
		Node* root = &nodes[1];
		vector<Info> info(n+1);
		depth(root, NULL, info);
		vector<Node*> path;
		getLongestPath(info[1].diaRoot, info, path);
		int length = path.size();
		root = path[length/2];
		set<int> best;
		if (length%2==1) {
			best.insert(path[length/2]->index);
		} else {
			best.insert(path[length/2-1]->index);
			best.insert(path[length/2]->index);
		}
		cout<<"Best Roots  :";
		for (set<int>::iterator it= best.begin(); it!=best.end();++it) {
			cout<<" "<<(*it);
		}
		cout<<endl;
		depth(root, NULL, info);
		set<int> worst;
		for (int i=0;i<root->children.size();++i) {
			if (length%2==0 && info[root->children[i]->index].depth==length/2-1) {
				getNodesAtDepth(root->children[i], root, 1, length/2, worst);
			} else {
				getNodesAtDepth(root->children[i], root, 1, (length-1)/2, worst);
			}
		}
		cout<<"Worst Roots :";
		for (set<int>::iterator it= worst.begin(); it!=worst.end();++it) {
			cout<<" "<<(*it);
		}
		cout<<endl;
	}
	return 0;
}