#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 200;

char buffer[200];

bool check(){
	int x=0,y=0, z=0;
	int len = strlen(buffer);
	int i=0;
	for(;i<len && buffer[i]=='?'; ++i) ++x;
	if (i==len || buffer[i++]!='M' || x==0) return false;
	for(;i<len && buffer[i]=='?'; ++i) ++y;
	if (i==len || buffer[i++]!='E' || y==0) return false;
	for(;i<len && buffer[i]=='?'; ++i) ++z;
	if (z==x+y && i==len) return true;
	else return false;
}

int main(){
	int kase;
	cin>>kase;
	cin.getline(buffer, MAX);
	for(int i=0;i<kase; ++i){
		cin.getline(buffer, MAX);
		if(check())
			cout<<"theorem"<<endl;
		else
			cout<<"no-theorem"<<endl;
	}
	return 0;
}