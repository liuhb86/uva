#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> Vector;
const char BKG='.';
const char DIE='*';
const char DOT='X';

char pic[50+10][50+10];
Vector dices;
int pointOfDie;

void searchDot(int x,int y){
	if(pic[x][y]!=DOT) return;
	pic[x][y]=DIE;
	searchDot(x,y-1);
	searchDot(x,y+1);
	searchDot(x-1,y);
	searchDot(x+1,y);
}
void searchDie(int x, int y){
	if(pic[x][y]==BKG) return;
	if(pic[x][y]==DOT) {
		++pointOfDie;
		searchDot(x,y);
	}
	pic[x][y]=BKG;
	searchDie(x,y-1);
	searchDie(x,y+1);
	searchDie(x-1,y);
	searchDie(x+1,y);
}

int main(){
	int kase=0;
	while(1){
		int m,n;
		cin>>n>>m;
		if(m==0 && n==0) break;
		++kase;
		dices.clear();
		cin.getline(pic[0],n);
		memset(pic[0],BKG,n+2);
		for(int i=1;i<=m;++i){
			pic[i][0]=BKG;
			cin.getline(pic[i]+1,n+1);
			pic[i][n+1]=BKG;
		}
		/*for(int i=0;i<m+3;++i){
			for(int j=0;j<n+2;++j) cout<<pic[i][j];
			cout<<endl;
		}*/
		memset(pic[m+1],BKG,n+2);
		for(int i=1;i<=m;++i){
			for(int j=1;j<=n;++j){
				if(pic[i][j]==BKG) continue;
				pointOfDie=0;
				searchDie(i,j);
				dices.push_back(pointOfDie);
		}}
		sort(dices.begin(),dices.end());
		cout<<"Throw "<<kase<<endl;
		bool first=true;
		for(Vector::iterator it=dices.begin();it<dices.end();++it){
		   	if(first) first=false; else cout<<" ";
			cout<<*it;
		}
		cout<<endl<<endl;
	}
	return 0;
}
