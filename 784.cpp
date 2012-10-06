#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

char maze[30+10][80+10];
const char PAINT='#';
const int ROOM_SIZE=4;
const int HALF_SIZE=ROOM_SIZE/2;
void paintRoom(int x,int y){
	if(maze[x][y]==PAINT) return ;	//already painted
	for(int i=-1;i<=1;++i) for(int j=-1;j<=1;++j) maze[x+i][y+j]=PAINT;
	int ox=1,oy=0;
	for(int i=0;i<4;++i){
		if(maze[x+ox*HALF_SIZE][y+oy*HALF_SIZE]==' '){
			maze[x+ox*HALF_SIZE][y+oy*HALF_SIZE]=PAINT;
			paintRoom(x+ox*ROOM_SIZE,y+oy*ROOM_SIZE);
		}
		oy=ox;
		ox=abs(ox)-1;
	}
}
int main(){
	int kase;
	cin>>kase;
	cin.getline(maze[0],80);
	for(int i=0;i<kase;++i){
		int height=0;
		while(1){
			cin.getline(maze[height],80+1);
			if(maze[height][0]=='_') break;
			++height;
		}
		if(height==0){	//empty maze
			cout<<maze[0];
			continue;
		}
		int startx=-1,starty=-1;
		for(int j=HALF_SIZE;j<height;j+=ROOM_SIZE){
			char*p=strchr(maze[j],'*');
			//cout<<maze[j]<<endl;
			if(p){startx=j;starty=p-maze[j];break;}
		}
		//cout<<height<<" "<<startx<<" "<<starty<<endl;
		if(startx>0){
			paintRoom(startx,starty);
		}
		for(int j=0;j<=height;++j) cout<<maze[j]<<endl;
	}
}
