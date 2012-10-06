#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	while(1){
		char code[100];
		cin>>code;
		if(code[0]=='#') break;
		int len=strlen(code);
		bool success=next_permutation(code,code+len);
		if(success) cout<<code<<endl;
		else cout<<"No Successor"<<endl;
	}
}
