#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
using namespace std;

const int NNOTES=11;
unsigned long long counts[6010][NNOTES+3];
int notes[NNOTES]={5,10,20,50,100,200,500,1000,2000,5000,10000};

char inbuf[100];
char outbuf[100];

void padding(int col){
	int len=strlen(inbuf);
	int spaces=col-len;
	for(int i=0;i<spaces;++i) outbuf[i]=' ';
	strcpy(outbuf+spaces,inbuf);	
}

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
	for(int i=0;i<NNOTES;++i) notes[i]/=5;
	memset(counts, 0, sizeof(counts));

	int n,v;
	float f;
	unsigned long long result;
	while(true){
		cin>>f;
		v=static_cast<int>(f*100+.5);
		if(v==0) break;
		if (v%5==0){
			n=v/5;
			compute(n,NNOTES-1);
			result=counts[n][NNOTES-1];
		}else
			result = 0;
		sprintf(inbuf,"%d.%d%d",v/100,(v%100)/10,v%10);
		padding(6);
		cout<<outbuf;
		print64(result);
		padding(17);
		cout<<outbuf<<endl;
	}
	return 0;	
}
