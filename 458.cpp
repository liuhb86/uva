#include <iostream>
#include <string>
using namespace std;

int main(){
	const int offset='C'-'J';
	string s;
	while(cin>>s){
		int len=s.length();
		const char * s2=s.c_str();
		for(int i=0;i<len;i++){
			cout<<((char)(s2[i]+offset));
		}
		cout<<endl;
	}
	return 0;
}