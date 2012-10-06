#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAX_SIZE=75+5;
const int MAX_GRID=2*2*MAX_SIZE+1+10;
const char BOUNDARY='*';
const char WALL='X';
const char EMPTY=' ';
const char FOOTPRINT='#';
char grid[MAX_GRID][MAX_GRID];
int m,n;

int main(){
	int kase=0;
	while(1){
		cin>>n>>m;
		if(m==0 && n==0) break;
		++kase;
		//convert maze
		int gridSize=2*(m+n)+1;	
		memset(grid,EMPTY,sizeof(grid));
		for(int i=0;i<m;++i){ 
			for(int j=0;j<n;++j){
				char c;
				cin>>c;
				if(c=='/'){
					grid[2*(i+j)+2+1][2*(m-1-i+j)+1+1]=WALL;
					grid[2*(i+j)+2+1][2*(m-1-i+j)+3+1]=WALL;
					grid[2*(i+j)+2+1][2*(m-1-i+j)+2+1]=WALL;
					grid[2*(i+j)+2+1][2*(m-1-i+j)+0+1]=WALL;
					grid[2*(i+j)+2+1][2*(m-1-i+j)+4+1]=WALL;

				}else{ //c=='\\'
					grid[2*(i+j)+1+1][2*(m-1-i+j)+2+1]=WALL;
					grid[2*(i+j)+3+1][2*(m-1-i+j)+2+1]=WALL;
					grid[2*(i+j)+2+1][2*(m-1-i+j)+2+1]=WALL;
					grid[2*(i+j)+0+1][2*(m-1-i+j)+2+1]=WALL;
					grid[2*(i+j)+4+1][2*(m-1-i+j)+2+1]=WALL;
				}
			}
		}
		//set boundary
		for(int i=0;i<=gridSize+1;++i){
			grid[i][0]=BOUNDARY; grid[0][i]=BOUNDARY;
			grid[i][gridSize+1]=BOUNDARY; grid[gridSize+1][i]=BOUNDARY;
			grid[i][gridSize+2]=0;
		}
		//for(int i=0;i<=gridSize+1;++i) cout<<grid[i]<<endl;
		//convert DONE.
		//search loops
		int length=0,maxLength=-1,n_cycles=0;
		for(int i=2;i<=gridSize;i+=2){
			for(int j=2;j<=gridSize;j+=2){
				if(grid[i][j]!=EMPTY) continue;
				int x=i,y=j;
				length=0;
				while(1){
					++length;
					grid[x][y]=FOOTPRINT;
					int ox=1,oy=0;
					for(int k=0;k<4;++k){
						if(grid[x+ox][y+oy]!=WALL){
							char c=grid[x+ox*2][y+oy*2];
							if(c==EMPTY){
								x+=ox*2;
								y+=oy*2;
								goto continue_while;
							}
							if(c==BOUNDARY) goto break_while;
							if(c==FOOTPRINT && x+ox*2==i && y+oy*2==j){
								++n_cycles;
								if(length>maxLength) maxLength=length;
								goto break_while;
							}
						}
						oy=ox;ox=abs(ox)-1;
					}
					break;
continue_while:
					;
				}
break_while:
				;
			}
		}
		cout<<"Maze #"<<kase<<":"<<endl;
		if(n_cycles>0) cout<<n_cycles<<" Cycles; the longest has length "<<maxLength<<"."<<endl;
		else cout<<"There are no cycles."<<endl;
		cout<<endl;
	}	
	return 0;
}
