#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node;
typedef vector<Node*> Vector;
struct Node{
	int index;
	int indexMask;
	int visited;
	bool connected;
	Vector adj;

};
struct Result{
	long long dom;
	long long cover;
	//unsigned int size;
};

Node nodes[40];
vector<Vector> graph;
//Vector* pSubgraph;
vector<Result> result[2][40];
/*unsigned int covered;
bool findDomSet(Vector::iterator itBegin,int curNode, int maxNode){
	if(curNode>maxNode){
		if (covered==pSubgraph->size()) return true;
		else return false;
	}
	for(Vector::iterator it=itBegin;it!=pSubgraph->end() && (*it)->adj.size()>1;++it){
		Node* p=*it;
		++(p->visited);
		if(p->visited==1) ++covered;
		for(Vector::iterator it2=p->adj.begin();it2!=p->adj.end();++it2){
			++((*it2)->visited);
			if((*it2)->visited==1) ++covered;
		}
		//if(maxNode<3) cout<<p->index<<' '<<curNode<<' '<<maxNode<<':'<<covered<<endl;
		++it;
		if(findDomSet(it,curNode+1,maxNode)) return true;
		--it;
		--(p->visited);
		if(p->visited==0) --covered;
		for(Vector::iterator it2=p->adj.begin();it2!=p->adj.end();++it2){
			--((*it2)->visited);
			if((*it2)->visited==0) --covered;
		}
	}
	return false;
}*/

bool gt(Node* n1, Node* n2){return n1->adj.size()>n2->adj.size();}
//bool resultLt(Result r1, Result r2){return r1.size<r2.size;}
int calcMinDom(Vector& subgraph){
	//pSubgraph=&subgraph;
	if(subgraph.size()==1 || subgraph.size()==2) return 1;
	//then, the size of the subgraph is >=3. So no two nodes with d=1 are directly connected.
	//Under this condition, the nodes with d=1 are never part of the smallest dominating set.
	sort(subgraph.begin(),subgraph.end(),gt);
	int upperBound=subgraph.size()-1;
	vector<Result>* cur,*last,*temp;
	cur=result[0];last=result[1];
	for(unsigned int i=0;i<subgraph.size();++i){cur[i].clear();last[i].clear();}
	Result r,r2;
	r.dom=0; r.cover=0;// r.size=0;
	last->push_back(r);
	unsigned int lastMax=0,curMax=0;
	int deaaa=0;
	for (int k=1;k<upperBound;++k){
		//covered=0;
		//if(findDomSet(subgraph.begin(),1,k)) return k;
		cout<<k<<' '<<deaaa<<endl;
		deaaa=0;
		for(int i=lastMax;i>=0;--i){
		for(vector<Result>::iterator it0=last[i].begin();it0!=last[i].end();++it0){
			//while(!last[i].empty()){
			//r=last[i].back();
			//last->pop_back();
			//pop_heap(last->begin(),last->end(),resultGt);
			for(Vector::iterator it=subgraph.begin();it!=subgraph.end();++it){
				Node* p=*it;
				if (p->adj.size()<=1) break;
				if(r.dom & p->indexMask) continue;
				r2=*it0;
				unsigned int size=i;
				r2.dom|=p->indexMask;
				if(r2.cover&p->indexMask);else{r2.cover|=p->indexMask;++size;}
				for(Vector::iterator it2=p->adj.begin();it2!=p->adj.end();++it2){
					if(r2.cover&(*it2)->indexMask);else{r2.cover|=(*it2)->indexMask;++size;}
				}
				if(size==subgraph.size()) return k;
				cur[size].push_back(r2);
				++deaaa;
				if(size>curMax) curMax=size;
			}
		}}
		for(unsigned int i=0;i<=lastMax;++i) last[i].clear();
		lastMax=curMax;
		temp=cur;cur=last;last=temp;
	}
	return subgraph.size()-1;
	//return -1000;   //never reach here.
}

void transverse(Node* p){
	if (p->connected) return;
	p->connected=true;
	graph.back().push_back(p);
	for(Vector::iterator it=p->adj.begin();it!=p->adj.end();++it){
		transverse(*it);
	}
}
int main(){
	while(1){
		int minDom=0;
		int n,m;
		cin>>n>>m;
		if(n==0 && m==0) break;
		for(int i=1;i<=n;++i){
			nodes[i].index=i;
			nodes[i].indexMask=1<<i;
			nodes[i].visited=0;
			nodes[i].connected=false;
			nodes[i].adj.clear();
		}
		for(int i=0;i<m;++i){
			int s,t;
			cin>>s>>t;
			nodes[s].adj.push_back(nodes+t);
			nodes[t].adj.push_back(nodes+s);
		}
		
		for(int i=1;i<=n;++i){
			if(nodes[i].connected) continue;
			graph.push_back(Vector());
			transverse(nodes+i);
		}
		for(vector<Vector>::iterator it=graph.begin(); it!=graph.end(); ++it){
			minDom+=calcMinDom(*it);
			//cout<<"***"<<minDom<<endl;
		}
		cout<<minDom<<endl;
	}
	return 0;
}
