#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXB=10+5;

struct Point{
	int x;
	int y;
};

Point beeper[MAXB];
int dist[MAXB][MAXB];
int value[MAXB][2500];
int nbeeper;

inline int point_distance(Point a, Point b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}

int compute(int start, int mask){
	if(value[start][mask]>=0) return value[start][mask];
	if(mask==0){
		value[start][mask]=dist[start][nbeeper];
	} else {
		bool first=true;
		int minval;
		int next=0;
		for(int i=0;i<nbeeper;++i){
			if((mask & (1<<i))==0) continue;
			int val=dist[start][i]+compute(i,mask-(1<<i));
			if (first || val<minval){minval=val; first=false;}
		}
		value[start][mask]=minval;
	}
	return value[start][mask];
}

int main(){
	int nkase;
	cin>>nkase;
	for(int kase=0; kase<nkase;++kase){
		memset(value,-1,sizeof(value));
		int m,n;
		cin>>m>>n;
		Point start_point;
		cin>>start_point.x>>start_point.y;
		cin>>nbeeper;
		for(int i=0;i<nbeeper;++i) cin>>beeper[i].x>>beeper[i].y;
		beeper[nbeeper]=start_point;
		for(int i=0;i<=nbeeper;++i){
			for(int j=0;j<=nbeeper;++j){
				dist[i][j]=point_distance(beeper[i], beeper[j]);
			}
		}
		int mask=(1<<nbeeper)-1;
		int minval=compute(nbeeper,mask);
		cout<<"The shortest path has length "<<minval<<endl;
	}
	return 0;
}