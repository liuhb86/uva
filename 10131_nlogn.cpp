#include <iostream>
#include <algorithm>
using namespace std;

struct Elephant{
	int index;
	int w;
	int iq;	
};

Elephant e[1000+50];
Elephant max_e[1000+50];
int max_lens[1000+50];
int output[1000+50];

bool cmp(Elephant a, Elephant b){
	if(a.w<b.w) return true;
	if(a.w==b.w) return a.iq<=b.iq;
	return false;	
}

Elephant* bsearch(Elephant* begin, Elephant* end, Elephant& e){
	if (end<=begin) return begin;
	Elephant* mid=begin+(end-begin)/2;
	if (e.iq>=mid->iq) return bsearch(begin,mid,e);
	else return bsearch(mid+1,end,e);
}

int main(){
//	Elephant test[5];
//	Elephant te;
//	te.iq=5;
//	cout<<bsearch(test,test,te)-test<<endl;
//	test[0].iq=3;
//	cout<<bsearch(test,test+1,te)-test<<endl;
//	test[0].iq=5;
//	cout<<bsearch(test,test+1,te)-test<<endl;
//	test[0].iq=7;
//	cout<<bsearch(test,test+1,te)-test<<endl;
//	test[1].iq=4;
//	cout<<bsearch(test,test+2,te)-test<<endl;		
	int w,iq;
	int count=0;
	while(cin>>w>>iq){
		e[count].index=count;
		e[count].w=w;
		e[count].iq=iq;
		++count;
	}
	sort(e,e+count,cmp);
	
	int len=0;
	for(int i=1;i<count;++i){
		int loc=bsearch(max_e,max_e+len,e[i])-max_e+1;
		max_e[loc-1]=e[i];
		max_lens[i]=loc;
		if(loc>len) len=loc;
	}
	cout<<len<<endl;
	int i=count-1, j=len;
	while(j>0){
		if(max_lens[i]==j){
			output[j]=e[i].index+1;
			--j;
		}
		--i;	
	}
	for(int j=1;j<=len;++j) cout<<output[j]<<endl;
	
	return 0;	
}
