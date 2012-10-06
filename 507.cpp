#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=20000+10;
int stops[MAXN];

int main(){
	int nkase;
	cin>>nkase;
	for(int kase=1;kase<=nkase;++kase){
		int nstops;
		cin>>nstops;
		--nstops;
		for(int i=0;i<nstops;++i) cin>>stops[i];
		int maxval=0, maxvalc=0;
		int start=0,end=0, startc=0;
		for(int i=0;i<nstops;++i){
			int endc=i+1;
			maxvalc+=stops[i];
			if(maxvalc<0){
				maxvalc=0;
				startc=endc;
			}
			if(maxvalc>maxval){
				maxval=maxvalc;
				start=startc;
				end=endc;
			}else if (maxvalc==maxval){
				if(endc-startc>end-start){
					start=startc;
					end=endc;
				}else if(endc-startc==end-start){
					if(startc<start){
						start=startc;
						end=endc;
					}
				}
			}
		}
		if(maxval<=0)
			printf("Route %d has no nice parts\n",kase);
		else
			printf("The nicest part of route %d is between stops %d and %d\n",kase,start+1,end+1);
	}
	return 0;
}