#include <iostream>
#include <cstdio>
using namespace std;

const int ROW=10+5;
const int COL=100+5;

struct Element{
	int value;
	int cost;
	int next;		
};

Element matrix[ROW][COL];

inline int PRE(int i, int m){
	return (i+m-1)%m;
}
inline int NEXT(int i, int m){
	return (i+1)%m;	
}

int main(){
	int m,n;
	while(cin>>m>>n){
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
				cin>>matrix[i][j].value;
		for(int row=0;row<m;++row)
			matrix[row][n-1].cost=matrix[row][n-1].value;
		for(int col=n-2;col>=0;--col){
			for(int row=0;row<m;++row){
				int row0,row1,row2;
				if (row==0)       {row0=row; row1=NEXT(row,m); row2=PRE(row,m);}
				else if (row==m-1){row0=NEXT(row,m); row1=PRE(row,m); row2=row;}
				else 		      {row0=PRE(row,m); row1=row; row2=NEXT(row,m);}
				int mincost=matrix[row0][col+1].cost;
				int next=row0;
				if(matrix[row1][col+1].cost<mincost) {mincost=matrix[row1][col+1].cost; next=row1;}
				if(matrix[row2][col+1].cost<mincost) {mincost=matrix[row2][col+1].cost; next=row2;}
				matrix[row][col].cost = matrix[row][col].value+mincost;
				matrix[row][col].next = next;
			}
		}
		int mincost=matrix[0][0].cost;
		int minrow=0;
		for(int row=1;row<m;++row){
			if(matrix[row][0].cost<mincost){
				mincost=matrix[row][0].cost;
				minrow=row;	
			}
		}
		cout<<minrow+1;
		for(int col=0;col<n-1;++col) {
			cout<<' '<<matrix[minrow][col].next+1;
			minrow=matrix[minrow][col].next;
		}
		cout<<endl<<mincost<<endl;
	}
	return 0;	
}
