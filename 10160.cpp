#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

const int MAX_SIZE=40;
typedef long long Bitset;
struct Node;
typedef vector<Node*> Vector;
struct Node{
	int index;
	Bitset	 indexMask;
	int visited;
	bool connected;
	Vector adj;
	Bitset adjMask;
	bool potential;
	int nCover;
};

Node nodes[MAX_SIZE];
vector<Vector> graph;
Bitset fullMask;
int curMinDom;
clock_t deadline;

bool gt(Node* n1, Node* n2){return n1->nCover>n2->nCover;}
bool findDomSet(Node** begin, Node** end,Bitset coveredMask,int curNode){
	//cout<<curMinDom<<' '<<curNode<<'a'<<endl;
	Bitset uncoveredMask=fullMask-coveredMask;
	Bitset b=uncoveredMask;
	int numUncovered=0;
	int canCover=0;
	//cout<<fullMask<<' '<<coveredMask<<' '<<uncoveredMask<<endl;
	while(b!=0){
		//cout<<b<<endl;
		if(b&1) ++numUncovered;
		b>>=1;
	}
	for(Node** p=begin;p!=end;++p){
		(*p)->nCover=0;
		b=uncoveredMask&(*p)->adjMask;
			//cout<<fullMask<<endl;
		if(b==uncoveredMask) {curMinDom=curNode+1; /*cout<<"min="<<curMinDom<<endl;*/ return true;}
		while(b!=0){
			if(b&1) ++((*p)->nCover);
			b>>=1;
		}
	}
	if(curNode>=curMinDom-2) return true;
	//if(clock()>deadline) return false;
	Node* candidate[MAX_SIZE];
	copy(begin,end,candidate);
	Node** cend=candidate+(end-begin);
	sort(candidate,cend,gt);
	int nCover[MAX_SIZE];
	int k=0;
	for(Node**p=candidate;p!=cend;++p) nCover[k++]=(*p)->nCover;
	nCover[k]=-1;
	k=0;
	for(Node** p=candidate;p!=cend;++p){
		canCover=0;
		for(int i=0;i<curMinDom-curNode-1;++i) canCover+=nCover[k+i];
		if(canCover<numUncovered) return true;
		++k;
		//cout<<(*p)->index<<' '<<curNode<<"  "<<curMinDom<<endl;
		//cout<<(*p)->index<<' '<<(*p)->adjMask<<' '<<(coveredMask|(*p)->adjMask)<<endl;
		if (!findDomSet(p,cend,coveredMask|(*p)->adjMask,curNode+1)) return false;
	}
	return true;
}

//bool resultLt(Result r1, Result r2){return r1.size<r2.size;}
int calcMinDom(Vector& subgraph){
	//pSubgraph=&subgraph;
	if(subgraph.size()==1 || subgraph.size()==2) return 1;
	//then, the size of the subgraph is >=3. So no two nodes with d=1 are directly connected.
	//Under this condition, the nodes with d=1 are never part of the smallest dominating set.
	int impotential=0;
	fullMask=0;
	for(Vector::iterator it=subgraph.begin();it!=subgraph.end();++it){
		Node* p1=*it;
		fullMask|=p1->indexMask;
		//cout<<p1->index<<' ';
		//cout<<fullMask<<' '<<p1->indexMask<<' '<<p1->index<<endl;
		if (!p1->potential) continue;
		if (p1->adj.size()<=2) {p1->potential=false;++impotential; continue;}
		//if(p1->adj.adjMask==fullMask) return 1;
		Vector::iterator it2=it;
		++it2;
		for(;it2!=subgraph.end();++it2){
			Node* p2=*it2;
			//cout<<p1->index<<' '<<p2->index<<endl;
			if(!p2->potential) continue;
			if((p1->adjMask|p2->adjMask)==p1->adjMask){p2->potential=false;++impotential; continue;}
			if((p1->adjMask|p2->adjMask)==p2->adjMask){p1->potential=false;++impotential; break;}
		}
	}
	curMinDom=subgraph.size()-max(impotential,1);
	Node* candidate[MAX_SIZE];
	unsigned int k=0;
	for(Vector::iterator it=subgraph.begin();k<subgraph.size()-impotential;++it){
		if((*it)->potential){
			if((*it)->adjMask==fullMask) return 1;
			candidate[k++]=*it;
		}
	}
	//deadline=clock()+3*CLOCKS_PER_SEC;
	findDomSet(candidate,candidate+subgraph.size()-impotential,0,0);
	return curMinDom;
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
		graph.clear();
		fullMask=0;
		Bitset mask=1;
		for(int i=1;i<=n;++i){
			nodes[i].index=i;
			//nodes[i].indexMask=1<<i;
			nodes[i].indexMask=mask;
			mask<<=1;
			//fullMask|=nodes[i].indexMask;
			nodes[i].visited=0;
			nodes[i].connected=false;
			nodes[i].potential=true;
			nodes[i].adj.clear();
			nodes[i].adj.push_back(nodes+i);
			nodes[i].adjMask=nodes[i].indexMask;
		}
		for(int i=0;i<m;++i){
			int s,t;
			cin>>s>>t;
			nodes[s].adj.push_back(nodes+t);
			nodes[s].adjMask|=nodes[t].indexMask;
			nodes[t].adj.push_back(nodes+s);
			nodes[t].adjMask|=nodes[s].indexMask;
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
