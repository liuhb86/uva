#include <iostream>
#include <cstring>
using namespace std;

char buf[1000];
char re[10]="+-*?";
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int result=0;
		cin>>buf;
		int len=strlen(buf);
		if(strcmp(buf,"1")==0) result=0;
		else if(strcmp(buf,"4")==0) result=0;
		else if(strcmp(buf,"78")==0) result=0;
		else if(len>=2 && strcmp(buf+len-2,"35")==0) result=1;
		else if(len>=2 && buf[0]=='9'&& buf[len-1]=='4') result=2;
		else if(len>=3 && buf[0]=='1' && buf[1]=='9' && buf[2]=='0') result=3;
		cout<<re[result]<<endl;
	}
	
	return 0;	
}
