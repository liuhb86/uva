#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;
const int MAXLEN=1000000+10;
char buffer[MAXLEN];
int main(){
	while(fgets(buffer,MAXLEN,stdin)!=NULL){
		char *p=buffer;
		int count=0;
		while (*p && !isalpha(*p)) p++;
		while (*p){
			while(*p && isalpha(*p)) p++;
			count ++;
			while (*p && !isalpha(*p)) p++;
		}
		cout<<count<<endl;
	}
	return 0;
}