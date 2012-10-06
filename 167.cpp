#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE=8;
int number[10][10];
bool col[10];
bool diag[20];
bool back_diag[20];
int loc[10];
//int score;
int maxScore;
//int count;

void solve(int row){
	if(row==SIZE){
		//++count;
		int score=0;
		for(int i=0;i<SIZE;++i) score+=number[i][loc[i]];
		if(score>maxScore) maxScore=score;
		return ;
	}
	for(int i=0;i<SIZE;++i){
		if(col[i]) continue;
		if(diag[10+row-i]) continue;
		if(back_diag[row+i]) continue;
		loc[row]=i;
		col[i]=true;
		diag[10+row-i]=true;
		back_diag[row+i]=true;
		solve(row+1);
		col[i]=false;
		diag[10+row-i]=false;
		back_diag[row+i]=false;
	}
}

int main(){
	//count=0;
	cout.setf(ios::right);
	int kase;
	cin>>kase;
	for(int i=0;i<SIZE;++i)
		col[i]=false;
	for(int i=0;i<20;++i){
		diag[i]=false;
		back_diag[i]=false;
	}
	for(int i=0;i<kase;++i){
		for(int j=0;j<SIZE;++j){
			for(int k=0;k<SIZE;++k){
				cin>>number[j][k];
			}
		}
		maxScore=0;
		solve(0);
		//cout<<count<<endl;
		cout<<setw(5)<<maxScore<<endl;
	}
	return 0;
}

