#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int MAXN=250+10;
int freq[MAXN];
int freq_sum[MAXN];
int value[MAXN][MAXN];

inline int sum(int len,int start){
	return freq_sum[start+len]-freq_sum[start];
}

int main(){
	string input;
	while(getline(cin,input)){
		istringstream iss(input);
		int n;
		iss>>n;
		for(int i=0;i<n;++i) iss>>freq[i];
		freq_sum[1]=freq[0];
		for(int i=1;i<n;++i) freq_sum[i+1]=freq_sum[i]+freq[i];
		for(int i=0;i<=n;++i) value[0][i]=0;
		for(int len=1;len<n;++len){
			for(int start=0;start+len<=n;++start){
				bool first=true;
				int minval;
				for(int k=0;k<len;++k){
					int val=value[k][start]+value[len-k-1][start+k+1];
					if(first || val<minval) {minval=val; first=false;}
				}
				value[len][start]=minval+sum(len,start);
			}
		}

		bool first=true;
		int minval=0;
		for(int k=0;k<n;++k){
			int val=value[k][0]+value[n-k-1][k+1];
			if(first || val<minval) {minval=val; first=false;}
		}
		cout<<minval<<endl;
	}
	return 0;
}