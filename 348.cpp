#include <iostream>
using namespace std;
struct Matrix{
	int m;
	int n;	
};

const int MAXN=10+5;
Matrix matrix[MAXN];
int value[MAXN][MAXN];
int note[MAXN][MAXN];

void print(int start,int len){
	if (len==1) {cout<<'A'<<start+1; return;}
	cout<<'(';
	int split=note[len][start];
	print(start,split);
	cout<<" x ";
	print(start+split,len-split);
	cout<<')';	
}

int main(){
	int kase=0;
	while(true){
		int n;
		cin>>n;
		if(n==0) break;
		++kase;
		for(int i=0;i<n;++i){
			cin>>matrix[i].m>>matrix[i].n;	
		}
		for(int i=0;i<n;++i){
			value[1][i]=0;
			note[1][i]=0;
		}
		for(int len=2;len<=n;++len){
			for(int start=0;start+len<=n;++start){
				bool first=true;
				for(int k=1; k<=len-1;++k){
					int curv=value[k][start]+value[len-k][start+k]
						+matrix[start].m*matrix[start+k].m*matrix[start+len-1].n;
					if(first || curv<value[len][start]) {
						value[len][start]=curv;
						note[len][start]=k;
						first = false;
					}
				}
			}	
		}
		//cout<<value[n][0]<<endl;
		cout<<"Case "<<kase<<": ";
		print(0,n);
		cout<<endl;
	}
	return 0;	
}
