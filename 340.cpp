#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int numColor=9;
const int numN=1000+50;
int countColorSource[numColor+5];
int countColorDest[numColor+5];
int source[numN];
int dest[numN];

int main(){
	int n;
	int round=0;
	while(1){
		cin>>n;
		if(n==0) break;
		round++;
		cout<<"Game "<<round<<":"<<endl;
		memset(countColorSource,0,sizeof(countColorSource));
		for(int i=0;i<n;i++){
			cin>>source[i];	
			countColorSource[source[i]]++;
		}
		while(1){
			memset(countColorDest,0,sizeof(countColorDest));
			int A=0;
			for(int i=0;i<n;i++){
				cin>>dest[i];
				countColorDest[dest[i]]++;
				if(dest[i]==source[i]) A++;
			}
			if (dest[0]==0) break;
			int B=0;
			for(int i=1;i<=numColor;i++){
				B+=min(countColorDest[i],countColorSource[i]);
			}
			B-=A;
			cout<<"    ("<<A<<","<<B<<")"<<endl;
		}
	}	
	return 0;
}
