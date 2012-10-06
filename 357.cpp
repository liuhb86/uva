#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
using namespace std;

const int NNOTES=5;
unsigned long long counts[30010][NNOTES+3];
int notes[NNOTES]={1,5,10,25,50};

char inbuf[100];

inline void print64(unsigned long long val){
	ostringstream oss;
	oss<<val;
	strcpy(inbuf, oss.str().c_str());
}

void compute(int n, int note){
	if (counts[n][note]) return;
	if (note==0) {
		counts[n][0]=1;
		return;
	}
	int max=n/notes[note];
	for(int i=0; i<=max; ++i){
		compute(n-i*notes[note], note-1);
		counts[n][note]+= counts[n-i*notes[note]][note-1];
	}
}

int main(){
	memset(counts, 0, sizeof(counts));
	int n;
	unsigned long long result;
	while(cin>>n){
		compute(n,NNOTES-1);
		result=counts[n][NNOTES-1];
		print64(result);
		if (result==1){
			printf("There is only 1 way to produce %d cents change.\n",n);
		}else{
			printf("There are %s ways to produce %d cents change.\n",inbuf,n);
		}
	}
	return 0;	
}
