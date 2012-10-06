#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const char valid[]="AEHIJLMOSTUVWXYZ12358";
const char rever[]="A3HILJMO2TUVWXY51SEZ8";


char output[][100]={
" -- is not a palindrome.",
" -- is a regular palindrome.",
" -- is a mirrored string.",
" -- is a mirrored palindrome."	
};

char reverse2[256];

int main(){
	int num_valid=strlen(valid);
	memset(reverse2,0,sizeof(reverse2));
	for(int i=0;i<num_valid;i++) reverse2[valid[i]]=rever[i];
	char buf[40];
	while(cin.getline(buf,40)){
		int len=strlen(buf);
		if(buf[len-1]=='\n') {buf[--len]==0;}
		//for (int i=0;i<len;i++) cout<<buf[i]+0<<" ";
		int palindrome=1;
		int mirror=1;
		for(int i=0;i<len;i++){
			if(buf[i]!=buf[len-1-i]) palindrome=0;
			//cout<<mirror<<" ";
			if(buf[i]!=reverse2[buf[len-1-i]]) mirror=0;
			//cout<<palindrome<<" ";
		}

		cout<<buf<<output[mirror*2+palindrome]<<endl<<endl;
	}
	return 0;
}
