#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=100+10;
int morning_route[MAXN];
int evening_route[MAXN];

inline bool cmp(int a, int b){
	return a>b;
}
int main(){
	while(true){
		int n,d,r;
		cin>>n>>d>>r;
		if(n==0 && d==0 && r==0) break;
		for(int i=0;i<n;++i) cin>>morning_route[i];
		for(int i=0;i<n;++i) cin>>evening_route[i];
		sort(morning_route,morning_route+n);
		sort(evening_route,evening_route+n,cmp);
		int extra=0;
		for(int i=0;i<n;++i) {
			int diff=morning_route[i]+evening_route[i]-d;
			if(diff>0) extra+=diff;
		}
		cout<<extra*r<<endl;
	}
	return 0;
}