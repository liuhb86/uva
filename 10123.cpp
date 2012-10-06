#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int LEFT=0;
const int RIGHT=1;
struct Package{
	int loc;
	int weight;
	int aggressive;
	int  defensive;
	bool visited;
	int side;
};
vector<Package> package;
vector<Package> middle;
Package* order[40];
int aggressive[2];
int defensive[2];
Package** round;
int taken;

typedef set<int> Set;
Set impossible;

bool gt(Package pk1,Package pk2){return pk1.aggressive>pk2.aggressive;}
bool take(){
	if(static_cast<unsigned int>(round-order)>=package.size()) return true;
	if(impossible.find(taken)!=impossible.end()) return false;
	int i=1;
	for(vector<Package>::iterator it=package.begin();it!=package.end();++it,i<<=1){
		if(it->visited) continue;
		if(defensive[it->side]-it->defensive>=aggressive[1-it->side]){
			defensive[it->side]-=it->defensive;
			aggressive[it->side]-=it->aggressive;
			it->visited=true;
			*(round++)=&(*it);
			taken+=i;
			if(take()) return true;
			taken-=i;
			it->visited=false;
			defensive[it->side]+=it->defensive;
			aggressive[it->side]+=it->aggressive;
			--round;
		}
	}
	impossible.insert(taken);
	return false;
}
int main(){
	int kase=0;
	Package temp;
	while(1){
		int length0,weight0,n;
		cin>>length0>>weight0>>n;
		if(length0==0 && weight0==0 && n==0) break;
		++kase;
		defensive[LEFT]=weight0*3;
		defensive[RIGHT]=weight0*3;
		aggressive[LEFT]=aggressive[RIGHT]=0;
		package.clear();
		middle.clear();
		impossible.clear();
		temp.visited=false;
		for(int i=0;i<n;++i){
			cin>>temp.loc>>temp.weight;
			temp.loc*=2;
			if(temp.loc<-3){
				temp.aggressive=temp.weight*(-3-temp.loc);
				temp.defensive=temp.weight*(3-temp.loc);
				aggressive[LEFT]+=temp.aggressive;
				defensive[LEFT]+=temp.defensive;
				temp.side=LEFT;
				package.push_back(temp);
			}else if (temp.loc>3){
				temp.aggressive=temp.weight*(temp.loc-3);
				temp.defensive=temp.weight*(temp.loc+3);
				aggressive[RIGHT]+=temp.aggressive;
				defensive[RIGHT]+=temp.defensive;
				temp.side=RIGHT;		
				package.push_back(temp);	
			}else{
				defensive[LEFT]+=temp.weight*(3-temp.loc);
				defensive[RIGHT]+=temp.weight*(temp.loc+3);
				middle.push_back(temp);
			}
		}
		sort(package.begin(),package.end(), gt);
		round=order;
		taken=0;
		bool success=take();
		cout<<"Case "<<kase<<':'<<endl;
		//cout<<round-order;
		if(success){
			for(Package** p=order;p!=round;++p)
				cout<<(*p)->loc/2<<' '<<(*p)->weight<<endl;
			for(vector<Package>::iterator p=middle.begin();p!=middle.end();++p)
				cout<<p->loc/2<<' '<<p->weight<<endl;
		}else
			cout<<"Impossible"<<endl;	
	}
	return 0;
}

