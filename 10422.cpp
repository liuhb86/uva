#include <iostream>
#include <cstdlib>
#include <deque>
#include <set>
using namespace std;

const int SZ=5;
const int SZ2=SZ*SZ;
const int MAP_MASK=(1<<SZ2)-1;
const int goal=403203039; //01100 00000 10000 110000 11110 11111
const int MAX_DEPTH=10;

deque<int> queue;
deque<int>depth;
set<int> visited;
int main(){
	int n_kase;
	char buf[10];
	cin>>n_kase;
	cin.getline(buf,10);
	for(int kase=0;kase<n_kase;++kase){
		int minStep=-1;
		queue.clear(); depth.clear();
		visited.clear();
		int initial=0;
		int bx,by;
		int p=1;
		for(int i=0;i<SZ;++i){
			cin.getline(buf,10);
			for(int j=0;j<SZ;++j){
				if(buf[j]=='1') initial+=p;
				else if(buf[j]==' '){bx=i;by=j;}
				p<<=1;
			}
		}
		initial=((bx*SZ+by)<<SZ2)+initial;
		queue.push_back(initial); depth.push_back(0);
		visited.insert(initial);
		int ndepth;
		while(!queue.empty()){
			int state;
			int bx,by,bloc;
			int map;
			state=queue.front();
			queue.pop_front();
			ndepth=depth.front();
			depth.pop_front();
			if(state==goal) {minStep=ndepth; break;}
			if(ndepth>=MAX_DEPTH) continue;
			++ndepth;
			bloc=state>>SZ2;
			by=bloc%SZ;
			bx=bloc/SZ;
			map=state&MAP_MASK;
			int nx,ny,nmap;
			//cout<<state<<' '<<bx<<' '<<by<<endl;
			for(int i=-2;i<=2;++i){
				if (i==0) continue;
				nx=bx+i;
				if (nx<0 || nx>=SZ) continue;
				int j=3-abs(i);
				for(int k=0;k<2;++k){
					ny=by+j;
					j=-j;
					if(ny<0 || ny>=SZ) continue;
					//cout<<' '<<nx<<' '<<ny<<endl;
					int nloc=nx*SZ+ny;
					if(map&(1<<nloc)) nmap=map-(1<<nloc)+(1<<bloc);
					else nmap=map;
					int nstate=(nloc<<SZ2)+nmap;
					if(visited.insert(nstate).second){
						queue.push_back(nstate);
						depth.push_back(ndepth);
					}
				}
			}
		}
		if(minStep<0) cout<<"Unsolvable in less than 11 move(s)."<<endl;
		else cout<<"Solvable in "<<minStep<<" move(s)."<<endl;
	}
	return 0;
}
