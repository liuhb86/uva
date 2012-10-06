#include <iostream>
#include <cstring>
//#include <deque>
using namespace std;

int mcount[200]={0};
const int BASE=100;
int mmin;
int mmax;

void fall(int loc){
	int num;
	cin>>num;
	if(num<0) return ;
	if(loc<mmin) mmin=loc;
	if(loc>mmax) mmax=loc;
	mcount[loc]+=num;
	fall(loc-1);
	fall(loc+1);
	return ;
}
int main(){
	int kase=0;
	while(1){
		mmin=200;mmax=0;
		fall(BASE);
		if(mmin>mmax) break;
		++kase;
		cout<<"Case "<<kase<<":"<<endl;
		bool first=true;
		for(int i=mmin;i<=mmax;++i){
			if(first) first=false; else cout<<" ";
			cout<<mcount[i];
		}
		cout<<endl<<endl;
		memset(mcount+mmin,0,sizeof(int)*(mmax-mmin+1));
	}

	return 0;
}
