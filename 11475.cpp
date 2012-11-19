//10298 - Power Strings
//string, kmp

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXLEN=100000+10;
int k[MAXLEN];
char input[MAXLEN];
char reversed[MAXLEN];
int main(){
	while(cin.getline(input,MAXLEN)){
		int len=strlen(input);
		reverse_copy(input,input+len,reversed);
		reversed[len]=0;
		int q=k[0]=-1;
		for(int i=1;i<len;++i){
			while(q!=-1 && reversed[q+1]!=reversed[i])
				q=k[q];
			if (reversed[q+1]==reversed[i]) ++q;
			k[i]=q;
		}
		q=-1;
		for (int i=0;i<len;++i){
			while(q!=-1 && reversed[q+1]!=input[i])
				q=k[q];
			if (reversed[q+1]==input[i]) ++q;
		}
		cout<<input<<(reversed+q+1)<<endl;
	}

}