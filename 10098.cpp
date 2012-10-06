#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	int kase;
	cin>>kase;
	for(int i=0;i<kase;++i){
		char str[15];
		cin>>str;
		int len=strlen(str);
		char *pend=str+len;
		sort(str,pend);
		bool success;
		do{
			cout<<str<<endl;
			success=next_permutation(str,pend);
		}while(success);
		cout<<endl;
	}
	return 0;
}
