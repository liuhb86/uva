#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int h,k;
int value[15];
int contiVal[15][15];
int maxValue[15];
//int val;
int maxVal;

void solve(int index){
	if(index==k){
		int val=contiVal[index-1][h];
		for(int i=0;i<k;++i) cout<<setw(3)<<value[i];
		cout<<" ->"<<setw(3)<<val<<endl;
		for(int i=0;i<k;++i){
			for(int j=0;j<=h;++j) cout<<contiVal[i][j]<<" ";
			cout<<endl;
		}
		if(val>maxVal){
			maxVal=val;
			memcpy(maxValue,value,sizeof(int)*k);
		}
		return ;
	}
	int start=value[index-1]+1;
	int end=contiVal[index-1][h]+1+1;
	for(int i=start;i<end;++i){
		value[index]=i;
		for(int j=0;j<=h;++j){
			int v=contiVal[index-1][j];
			for(int p=1;p<=j;++p){
				if(p*i<=v+1) v=p*i+contiVal[index-1][j-p];
				else break;
			}
			contiVal[index][j]=v;
		}
		solve(index+1);
	}
}
int main(){
	cout.setf(ios::right);
	while(1){
		cin>>h>>k;
		if(h==0 && k==0) break;
		value[0]=1;
		for(int i=0;i<=h;++i) contiVal[0][i]=i;
		//val=h;
		maxVal=0;
		solve(1);
		for(int i=0;i<k;++i) cout<<setw(3)<<maxValue[i];
		cout<<" ->"<<setw(3)<<maxVal<<endl;	
	}
	return 0;
}
