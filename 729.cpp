#include <iostream>
#include <cstring>
using namespace std;

char str[100];
int N,H;

void generate(int start,int remain){
	if(remain>0){
		for(int i=start;i<=N-remain;++i){
			str[i]='0';
			generate(i+1,remain-1);
			str[i]='1';
		}
	}else{
		cout<<str<<endl;
	}
}
int main(){
	int kase;
	bool first=true;
	cin>>kase;
	for(int i=0;i<kase;++i){
		if(first) first=false; else cout<<endl;
		cin>>N>>H;
		H=N-H;
		memset(str,'1',N);
		str[N]=0;
		generate(0,H);
		
	}
	return 0;
}
