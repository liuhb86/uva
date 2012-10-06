#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXLEN=100+10;
char matrix[MAXLEN][MAXLEN];
int len[MAXLEN];
int slen[MAXLEN];
int main(){
	int lines=0;
	while(fgets(matrix[lines],MAXLEN,stdin)){
		len[lines]=strlen(matrix[lines]);
		if(matrix[lines][len[lines]-1]=='\n') len[lines]--;
		//for (int q=0;q<len[lines];q++) cout<<(int)matrix[lines][q]<<" ";
		//cout<<endl;
		if(lines==0 ||len[lines]>slen[lines-1]) slen[lines]=len[lines];
		else slen[lines]=slen[lines-1];
		lines++;
	}
	//for (int p=0;p<lines;p++){cout<<len[p]<<","<<slen[p]<<endl;}
	for(int i=0;i<slen[lines-1];i++){
		for(int j=lines-1;j>=0;j--){
			if(i<len[j]) cout<<matrix[j][i];
			else if (i<slen[j]) cout<<" ";
			else break;
		}
		cout<<endl;
	}
	return 0;
}