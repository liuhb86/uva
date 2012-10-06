#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_SIZE=65536+10;
int count[MAX_SIZE];


int main(){
	int n;
	while(cin>>n){
		memset(count,0,sizeof(count));
		//unsigned long long rsum=0;
		//unsigned long long lsum=0;
		//unsigned long long sum;
		//int min=MAX_SIZE;
		for(int i=0;i<n;++i){
			int number;
			scanf("%d",&number);
			//rsum+=number;
			++(count[number]);
		}
		int rcount=n;
		int lcount=0;
		for(int i=0;;++i){
			if(count[i]==0) continue;
			lcount+=count[i];
			rcount-=count[i];
			if(lcount>rcount){
				cout<<i<<" "<<count[i]<<" "<<1<<endl;
				break;
			}else if(lcount==rcount){
				int j;
				for(j=i+1;count[j]==0;++j) ;
				cout<<i<<" "<<count[i]+count[j]<<" "<<j-i+1<<endl;
				break;
			}
		}
	}
	return 0;
}
