#include <iostream>
#include <algorithm>
using namespace std;

char vowel[]="AUEOI";
char consonant[]="JSBKTCLDMVNWFXGPYHQZR";
char buf1[1000];
char buf2[1000];
int main(){
	int cases;
	cin>>cases;
	for(int i=1;i<=cases;i++){
		int n;
		cin>>n;
		int numV=(n+1)/2;
		int numC=n/2;
		int k=0,left=21,index=0;
		for(;k<numV;k++){
			if(left==0) {index++;left=21;}
			buf1[k]=vowel[index];
			left--;
		}
		k=0;left=5;index=0;
		for(;k<numC;k++){
			if(left==0) {index++;left=5;}
			buf2[k]=consonant[index];
			left--	;
		}
		sort(buf1,buf1+numV);
		sort(buf2,buf2+numC);
		char* buf[2]={buf1,buf2};
		k=0;
		cout<<"Case "<<i<<": ";
		for(int j=0;j<n;j++){
			cout<<buf[j%2][k];
			k+=j%2;
		}
		cout<<endl;
	}
	return 0;
}
