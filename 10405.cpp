#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_SIZE=1000+10;

int d[MAX_SIZE][MAX_SIZE];

int main(){
	while(1){
		char s1[MAX_SIZE];
		char s2[MAX_SIZE];
		cin.getline(s1,MAX_SIZE);
		cin.getline(s2,MAX_SIZE);
		if(cin.eof()) break;
		int m=strlen(s1);
		int n=strlen(s2);
		for(int i=0;i<=m;++i){
			for(int j=0;j<=n;++j){
				if(i==0) {d[i][j]=0; continue;}
				if(j==0) {d[i][j]=0; continue;}
				int maxd=max(d[i][j-1],d[i-1][j]);
				if(s1[i-1]==s2[j-1]){
					maxd=max(maxd,d[i-1][j-1]+1);
				}
				d[i][j]=maxd;
			}
		}
		cout<<d[m][n]<<endl;
	}
	return 0;
}
