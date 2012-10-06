#include <iostream>
#include <deque>
using namespace std;

const int MAX_SIZE=30+5;
char dungeon[MAX_SIZE][MAX_SIZE][MAX_SIZE];

const char EMPTY='.';
const char ROCK='#';
const char START='S';
const char EXIT='E';
const char FOOTPRINT='*';

const int N_DIRS=6;
const char ox[]={1,-1,0,0,0,0};
const char oy[]={0,0,1,-1,0,0};
const char oz[]={0,0,0,0,1,-1};

struct State{
	int x;
	int y;
	int z;
	int time;
	char getChar()const {return dungeon[x][y][z];}
	void putChar(char c)const {dungeon[x][y][z]=c;}
	State& moveFrom(const State& state,int dir){
		x=state.x+ox[dir]; y=state.y+oy[dir]; z=state.z+oz[dir];
		time=state.time+1;
		return *this;
	}
};

typedef deque<State> Queue;
Queue stateQueue;
int main(){
	State state;
	while(1){
		int m,n,p;
		cin>>m>>n>>p;
		if(m==0 && n==0 && p==0) break;
		for(int j=0;j<=n+1;++j) for(int k=0;k<=p+1;++k){dungeon[0][j][k]=ROCK;dungeon[m+1][j][k]=ROCK;}
		for(int i=1;i<=m;++i){
			for(int k=0;k<=p+1;++k) {dungeon[i][0][k]=ROCK; dungeon[i][n+1][k]=ROCK;}
			for(int j=1;j<=n;++j){
				dungeon[i][j][0]=ROCK; dungeon[i][j][p+1]=ROCK;
				for(int k=1;k<=p;++k){
					cin>>dungeon[i][j][k];
					//cout<<i<<j<<k<<dungeon[i][j][k];
				}
			}
		}
		stateQueue.clear();
		for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) for(int k=1;k<=p;++k){
			if(dungeon[i][j][k]==START){
				dungeon[i][j][k]=EMPTY;
				state.x=i; state.y=j; state.z=k; state.time=0;
				stateQueue.push_back(state);
				goto break1;
			}
		}
break1:
		bool escaped=false;
		while(!stateQueue.empty()){
			char c=stateQueue.front().getChar();
			if(c==ROCK || c==FOOTPRINT) {
			}else if(c==EMPTY){
				stateQueue.front().putChar(FOOTPRINT);
				for(int i=0;i<N_DIRS;++i)
					stateQueue.push_back(state.moveFrom(stateQueue.front(),i));
			}else if(c==EXIT){
				escaped=true;
				break;
			}
			stateQueue.pop_front();
		}
		if(escaped) cout<<"Escaped in "<<stateQueue.front().time<<" minute(s)."<<endl;
		else cout<<"Trapped!"<<endl;

	}
	return 0;
}
