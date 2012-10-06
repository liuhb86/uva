#include <iostream>
#include <map>
#include <deque>
#include <algorithm>
using namespace std;

int mask[9];
typedef pair<int,char> ParentInfo;
map<int,ParentInfo> visited;
deque<int> queue;
deque<int> loc;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
const char dir[5]="UDLR";
char path[2000];

int main(){
	int p=1;
	for(int i=0;i<9;++i){mask[i]=p;p*=10;}
	int n_kase;
	cin>>n_kase;
	for(int kase=1;kase<=n_kase;++kase){
		queue.clear();
		loc.clear();
		visited.clear();
		int digit,bloc;
		int initial=0;
		for(int i=0;i<9;++i){
			cin>>digit;
			initial+=digit*mask[i];
			if(digit==0) bloc=i;
		}
		queue.push_back(initial);
		loc.push_back(bloc);
		visited.insert(make_pair(initial,make_pair(0,0)));
		int map;
		while(!queue.empty()){
			int nmap,nx,ny,nloc;
			int x,y,lloc;
			int move_digit;
			map=queue.front(); queue.pop_front();
			lloc=loc.front(); loc.pop_front();
			x=lloc/3; y=lloc%3;	
			for(int i=0;i<4;++i){
				nx=x+dx[i]; ny=y+dy[i];
				if(nx<0 || nx>2 || ny<0 || ny>2) continue;
				nloc=nx*3+ny;
				move_digit=(map/mask[nloc])%10;
				nmap=map-move_digit*mask[nloc]+move_digit*mask[lloc];
				if(visited.insert(make_pair(nmap,make_pair(map,dir[i]))).second){
					queue.push_back(nmap);
					loc.push_back(nloc);
				}
			}
		}
		cout<<"Puzzle #"<<kase<<endl;
		for(int i=0;i<9;++i){
			cout<<(map/mask[i])%10;
			if(i%3==2) cout<<endl; else cout<<' ';
		}
		char* cp=path;
		do{
			ParentInfo pi=visited.find(map)->second;
			*(cp++)=pi.second;
			map=pi.first;
		}while(map!=0);
		--cp;
		reverse(path,cp);
		cout<<path<<endl<<endl;
	}

	return 0;
}
