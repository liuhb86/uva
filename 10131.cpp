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

int main(){
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
		int loc;
		for(loc=1;loc<=len;++loc){
			if(e[i].iq>=max_e[loc].iq) break;
		}
		max_e[loc]=e[i];
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
