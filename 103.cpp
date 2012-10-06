#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE=35;
const int MAX_DIM=15;
struct Box{
	int dim[MAX_DIM];
	bool to[MAX_SIZE];
	int d;
	bool visited;
	Box* next;
	int index;
};

Box boxes[MAX_SIZE];
int k,n;

int dp(int index){
	Box& box=boxes[index];
	if(box.visited) return box.d;
	box.visited=true;
	int d=0;
	int maxb;
	for(int i=0;i<k;++i){
		if(!box.to[i]) continue;
		int di=dp(i);
		if(di>d){
			d=di;
			maxb=i;
		}
	}

	if(d>0){
		box.d=d+1;
		box.next=boxes+maxb;
	}else{
		box.d=1;
		box.next=0;
	}
	return box.d;
}


int main(){
	while(cin>>k>>n){
		for(int i=0;i<k;++i){
			Box& box=boxes[i];
			for(int j=0;j<n;++j)
				cin>>box.dim[j];
			sort(box.dim,box.dim+n);
			box.visited=false;
			box.index=i+1;
			
			box.to[i]=false;
			for(int j=0;j<i;++j){
				bool smaller=true;
				for(int h=0;h<n;++h) 
					if(boxes[j].dim[h]>=box.dim[h]){
						smaller=false;
						break;
					}
				if(smaller){
					box.to[j]=true;
					boxes[j].to[i]=false;
				}else{
					bool smaller=true;
					for(int h=0;h<n;++h) 
						if(boxes[j].dim[h]<=box.dim[h]){
							smaller=false;
							break;
					}
					if(smaller){
						box.to[j]=false;
						boxes[j].to[i]=true;
					}
					else{
						box.to[j]=false;
						boxes[j].to[i]=false;
					}
				}
			}
		}
		for(int i=0;i<k;++i){
			dp(i);
		}
		int maxd=boxes[0].d;
		Box* maxb=boxes;
		for( int i=0;i<k;++i){
			if(boxes[i].d>maxd){
				maxb=boxes+i;
				maxd=maxb->d;
			}
		}
		int rev_result[MAX_SIZE];
		for(int i=0;i<maxd;++i){
			rev_result[i]=maxb->index;
			maxb=maxb->next;
		}
		cout<<maxd<<endl;
		bool first=true;
		for(int i=maxd-1;i>=0;--i){
			if(!first) cout<<' '; else first=false;
			cout<<rev_result[i];
		}
		cout<<endl;

	}
	return 0;
}
