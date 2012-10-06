#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
const int MAX_SIZE=25+5;
const int N_COLORS=5;

struct VisitInfo{
	char visited[4][N_COLORS];
	void init(char c){
		memset(visited,c,sizeof(visited));
	}
};
VisitInfo map[MAX_SIZE][MAX_SIZE];

struct State{
	int x;
	int y;
	int dir;
	int time;
	int color;
	bool visited() const{ return map[x][y].visited[dir][color];}
	void visit() const{map[x][y].visited[dir][color]=1;}
	void turnLeft(){
		dir=(dir==0)?3:dir-1;
		++time;
	}
	void turnRight(){
		dir=(dir==3)?0:dir+1;
		++time;
	}
	void go(){
		static const int ox[]={-1,0,1,0};
		static const int oy[]={0,1,0,-1};
		x+=ox[dir];
		y+=oy[dir];
		++time;
		color=(color+1)%N_COLORS;
	}
	
};
typedef deque<State> Queue;

int main(){
	int kase=0;
	bool first=true;
	while(1){
		int m,n;
		cin>>m>>n;
		if(m==0 && n==0) break;
		++kase;
		int destX,destY;
		Queue states;
		State state;
		for(int j=0;j<=n+1;++j){map[0][j].init(1); map[m+1][j].init(1);}
		for(int i=1;i<=m;++i){
			map[i][0].init(1); map[i][n+1].init(1);
			for(int j=1;j<=n;++j){
				char c; cin>>c;
				switch(c){
				case '#':
					map[i][j].init(1);
				break;
				case '.':
					map[i][j].init(0); 
				break;
				case 'S':
					map[i][j].init(0);
					state.x=i; state.y=j; state.dir=0; state.time=0; state.color=0;
					states.push_back(state);
				break;
				case 'T':
					map[i][j].init(0);
					destX=i; destY=j;
				break;
				}
			}
		}
		bool reachable=false;
		while(!states.empty()){
			State& state=states.front();
			//cout<<state.time<<":"<<state.x<<" "<<state.y<<" "<<state.dir<<" "<<state.color<<" # "<<state.visited()<<endl;

			if(!state.visited()){
				if(state.x==destX && state.y==destY && state.color==0){
					reachable=true;
					break;
				}
				state.visit();
				State state2;
				state2=state; state2.go(); states.push_back(state2);
				state2=state; state2.turnLeft(); states.push_back(state2);
				state2=state; state2.turnRight(); states.push_back(state2);
			}
			states.pop_front();
		}
		if(first) first=false; else cout<<endl;
		cout<<"Case #"<<kase<<endl;
		if(reachable) cout<<"minimum time = "<<states.front().time<<" sec"<<endl;
		else cout<<"destination not reachable"<<endl;

	}
	return 0;
}
