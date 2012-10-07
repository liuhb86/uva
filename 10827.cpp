#include <iostream>
using namespace std;

const int MAX = 100;
int torus[MAX][MAX];
int sum[MAX][MAX];
int verticalSum[MAX];
int leftMax[MAX];
int rightMax[MAX];

int n;
inline int prev(int k){return (k+n-1)%n;}
inline int next(int k){return (k+1)%n;}

int main(){
	int nkase;
	cin>>nkase;
	for(int kase =0 ;kase<nkase;++kase){
		cin>>n;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				cin>>torus[i][j];
		for(int i=0;i<n;++i) sum[0][i]=torus[0][i];
		for(int i=1;i<n;++i)
			for(int j=0;j<n;++j)
				sum[i][j]=sum[i-1][j]+torus[i][j];
		int finalMax=0;
		for(int start = 0; start <n; ++ start){
			for(int end =0; end<n; ++end){
				if(start ==0){
					for(int i=0;i<n;++i) verticalSum[i]=0;
				} else{
					for(int i=0;i<n;++i) verticalSum[i]= -sum[start-1][i];
				}
				if (end>=start){
					for(int i=0;i<n;++i) verticalSum[i]+=sum[end][i];
				} else{
					for(int i=0;i<n;++i) verticalSum[i]+=sum[n-1][i]+sum[end][i];
				}
			
				int max = 0, tmax=0;
				for(int i=0;i<n;++i){
					tmax+=verticalSum[i];
					if (tmax<0) tmax =0;
					else if(tmax>max) max=tmax;
				}
	
				int tsum =0;
				tmax =0;
				for(int i=0;i<n;++i){
					tsum+=verticalSum[i];
					if(tsum>tmax) tmax = tsum;
					leftMax[i]=tmax;
				}
				tsum =0;
				tmax = 0;
				for(int i=n-1;i>=0; --i){
					tsum+=verticalSum[i];
					if(tsum>tmax) tmax = tsum;
					rightMax[i]=tmax;
				}
				tmax =0;
				for(int i=0;i<n-1;++i){
					tsum = leftMax[i]+rightMax[i+1];
					if(tsum>tmax) tmax = tsum;
				}
				if(tmax>max) max = tmax;
				if(max>finalMax) finalMax =max;
			}
		}
		cout<<finalMax<<endl;
	}
}