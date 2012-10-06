#include <iostream>
using namespace std;

const int MAXN=100+10;
int matrix[MAXN][MAXN];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>matrix[i][j];
		}
	}
	//compute column prefix sum
	for(int i=0;i<=n;++i) matrix[i][0]=matrix[0][i]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			matrix[i][j]+=matrix[i-1][j];
		}
	}

	int maxv=0;
	for(int rs=1;rs<=n;++rs){
		for(int re=rs;re<=n;++re){
			int curmax=0;
			for(int col=1;col<=n;++col){
				int colsum=matrix[re][col]-matrix[rs-1][col];
				curmax+=colsum;
				if(curmax<0) curmax=0;
				if(curmax>maxv) maxv=curmax;
				if(maxv==70){
					int a=1;
				}
			}
		}
	}
	cout<<maxv<<endl;
	return 0;
}