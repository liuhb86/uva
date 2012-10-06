#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Status{
	int v[3];
	int poured;
};
bool lt(Status& v1, Status& v2){return v1.poured>v2.poured;}

const int MAX_SIZE=256;
const int MAX_SIZE2=MAX_SIZE*MAX_SIZE;
int bestVolume;
int minPour;
int cap[3];
int d;
set<int> visited;
vector<Status> heap;
int main(){
	int kase;
	cin>>kase;
	for(int i=0;i<kase;++i){
		visited.clear();
		heap.clear();
		bestVolume=-1;
		minPour=INT_MAX;
		cin>>cap[0]>>cap[1]>>cap[2]>>d;
		Status s0;
		s0.v[0]=0;s0.v[1]=0;s0.v[2]=cap[2];s0.poured=0;
		visited.insert(cap[2]);
		heap.push_back(s0);
		while(!heap.empty()){
			Status s,s_new;
			s=heap.front();
			pop_heap(heap.begin(),heap.end(),lt);
			heap.pop_back();
			//cout<<s.v[0]<<' '<<s.v[1]<<' '<<s.v[2]<<' '<<s.poured<<endl;
			for(int j=0;j<3;++j){
				if(s.v[j]==d){
					bestVolume=d;
					minPour=s.poured;
					goto exit1;
				}
				if(s.v[j]<d && s.v[j]>bestVolume){
					bestVolume=s.v[j];
					minPour=s.poured;
				}
			}
			for(int j=0;j<3;++j){
				for(int k=0;k<3;++k){
					if (j==k) continue;
					if(s.v[j]>0 && s.v[k]<cap[k]){
						s_new=s;
						int d=cap[k]-s.v[k];
						if(s.v[j]>d){
							s_new.v[j]-=d;
							s_new.v[k]=cap[k];
						}else{
							d=s.v[j];
							s_new.v[j]=0;
							s_new.v[k]+=d;
						}
						if(visited.insert(s_new.v[0]*MAX_SIZE2+s_new.v[1]*MAX_SIZE+s_new.v[2]).second){		
							s_new.poured+=d;
							heap.push_back(s_new);
							push_heap(heap.begin(),heap.end(),lt);
						}
					}
				}
			}
		}
exit1:
		cout<<minPour<<' '<<bestVolume<<endl;
	}
	return 0;
}
