#include <iostream>
#include <cstring>
using namespace std;

const int NNOTES=5;
int counts[8000][NNOTES+3];
int notes[NNOTES]={1,5,10,25,50};

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
	int n,result;
	while(cin>>n){
		compute(n,NNOTES-1);
		result=counts[n][NNOTES-1];
		cout<<result<<endl;
	}
	return 0;	
}
