#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

typedef deque<char> Stack;

char buffer[300];

char front(char c){
	return c==')'?'(':'[';
}
int main(){
	int kase;
	Stack pstack;
	cin>>kase;
	cin.getline(buffer,sizeof(buffer));
	
	for(int i=0;i<kase;++i){
		cin.getline(buffer,sizeof(buffer));
		bool valid=true;
		int len=strlen(buffer);
		for(int j=0;j<len;j++){
			if(buffer[j]=='(' || buffer[j]=='[') {pstack.push_back(buffer[j]); continue;}
			if(!pstack.empty() && front(buffer[j])==pstack.back()){pstack.pop_back();continue;}
			valid=false; break;
		}
		if(valid && pstack.empty()) cout<<"Yes"<<endl; else cout<<"No"<<endl;
		
		pstack.clear();
	}
}
