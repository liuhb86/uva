#include <iostream>
#include <set>
#include <string>
#include <cctype>
//#include <cstdio>
using namespace std;

char buf[1000];

int getword(){
	bool processed=true;
	char b;
	int k=0;
	if(cin.eof()) return 0;
	while(1){
		cin.read(&b,1);
		if(cin.eof()) b=0;
		if(cin.eof()) b=0;
		if(isalpha(b)) {buf[k++]=tolower(b);processed=false;}
		else{
			if(!processed){
				buf[k]=0;
				//cout<<buf<<endl;
				return 1;
			}
			if(cin.eof()) return 0;
		}
	}
}
int main(){
	set<string> dic;
	string s;
	while(getword()){
		s.assign( buf);
		dic.insert(s);
	}
	for(set<string>::iterator it=dic.begin();it!=dic.end();it++){
		cout<<*it<<endl;
	}
	return 0;
}
