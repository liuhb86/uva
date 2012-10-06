//correct, but too slow (several minutes). 
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int h,k;
int value[15];
int count[10000];
int maxValue[15];
int val;
int inc;
int maxVal;

void calc(int index){
	if(index==h){
		count[val]+=inc;
		return;
	}
	count[val]+=inc;
	for(int i=0;i<k;++i){
		val+=value[i];
		calc(index+1);
		val-=value[i];
	}
}
void solve(int index){
	if(index==k){
		val=0;
		inc=1;
		calc(0);
		int conti;
		for(conti=1;conti<10000;++conti){
			if(count[conti]==0) break;
		}
		--conti;
		//for(int i=0;i<k;++i) cout<<setw(3)<<value[i];
		//cout<<" ->"<<setw(3)<<conti<<endl;	
		if(conti>maxVal){
			maxVal=conti;
			memcpy(maxValue,value,sizeof(int)*k);
		}
		inc=-1;
		calc(0);
		return;
	}
	int start=value[index-1]+1;
	int end=start*h+1+1;
	for(int i=start;i<end;++i){
		value[index]=i;
		solve(index+1);
	}
}
int main(){
	cout.setf(ios::right);
	memset(count,0,sizeof(count));
	while(1){
		cin>>h>>k;
		if(h==0 && k==0) break;
		value[0]=1;
		maxVal=0;
		solve(1);
		for(int i=0;i<k;++i) cout<<setw(3)<<maxValue[i];
		cout<<" ->"<<setw(3)<<maxVal<<endl;	
	}
	return 0;
}
