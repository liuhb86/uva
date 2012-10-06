#include <iostream>
#include <cstring>
using namespace std;

const char ABSENCE='*';
const char POCKET='@';

int m,n;
int m2,n2;
char* grids;
int mcount;

inline char& grid(int x,int y){
	return grids[n2*x+y];
}
void detect(int i,int j){
	if(grid(i,j)==ABSENCE) return;
	grid(i,j)=ABSENCE;
	for(int oi=-1;oi<=1;++oi)
		for(int oj=-1;oj<=1;++oj)
			detect(i+oi,j+oj);
}

int main(){
	while(1){
		cin>>m>>n;
		if(m==0) break;
		m2=m+2;
		n2=n+2;
		grids=new char[m2*n2+10];
		cin.getline(grids,n2);
		memset(grids,ABSENCE,n2);
		for(int i=1;i<=m;++i){
			grid(i,0)=ABSENCE;
			cin.getline(&grid(i,1),n+1);
			grid(i,n+1)=ABSENCE;
		}
		memset(&grid(m+1,0),ABSENCE,n2);
		//grids[m2*n2+1]=0;
		//cout<<m<<" "<<n<<" "<<grids<<endl;
		mcount=0;
		for(int i=1;i<=m;++i){
			for(int j=1;j<=n;++j){
				if(grid(i,j)==ABSENCE) continue;
				++mcount;
				detect(i,j);
			}
		}
		cout<<mcount<<endl;
		delete[] grids;
	}
	return 0;
}
