#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=200+10;
const int MAXQ=10+5;
const int MAXD=20+5;
const int MAXM=10+5;

struct Query{
	int index;
	int d;
	int m;
};

int numbers[MAXN];
Query query[MAXQ];
unsigned long long query_result[MAXQ];
unsigned long long value[MAXM][MAXD];

bool cmp_query(Query a, Query b){
	if (a.d<b.d) return true;
	if (a.d==b.d) return a.m>=b.m;
	return false;
}
int main(){
	int kase=0;
	while(true){
		int n,q;
		cin>>n>>q;
		if(n==0 && q==0) break;
		++kase;
		for(int i=0;i<n;++i) cin>>numbers[i];
		for(int i=0;i<q;++i){
			query[i].index=i;
			cin>>query[i].d>>query[i].m;
		}
	
		sort(query,query+q,cmp_query);
		int lastd=-1;
		for(int i=0;i<q;++i){
			if (query[i].d!=lastd){
				int d=query[i].d, m=query[i].m;
				memset(value,0,sizeof(value));
				value[0][0]=1;
				for(int j=0;j<n;++j){
					int mlimit=(j+1>m)?m:j+1;
					int remain=(numbers[j]%d+d)%d;
					int sep=d-remain;
					for(int k=mlimit;k>=1;--k){
						for(int r=0;r<sep;++r) value[k][r+remain]+=value[k-1][r];
						for(int r=sep;r<d;++r) value[k][r+remain-d]+=value[k-1][r];
					}
				}
				query_result[query[i].index]=value[m][0];
			}
			
		}
		cout<<"SET "<<kase<<':'<<endl;
		for(int i=0;i<q;++i)
			cout<<"QUERY "<<i+1<<": "<<query_result[i]<<endl;
	}
	return 0;
}