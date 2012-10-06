//Euler path
//Look out for the connectivity!
//Euler path<-> base graph is connected & degree property.
#include <iostream>
#include <cstring>
using namespace std;

int degree[26+10];
int connected[26+10];
bool used[26+10];

char buf[2000];
int main(){
	int kase;
	cin>>kase;
	for(int i=0;i<kase;++i){
		int n_words;
		cin>>n_words;
		memset(degree,0,sizeof(degree));
		memset(used,0,sizeof(used));
		for(int j=0;j<26;++j) connected[j]=j;
		for(int j=0;j<n_words;++j){
			cin>>buf;
			int from=buf[0]-'a', to=buf[strlen(buf)-1]-'a';
			++degree[from];
			--degree[to];
			used[from]=true; used[to]=true;
			if(connected[from]!=connected[to]){
				int small=connected[from],large=connected[to];
				if(small>large) {small=to;large=from;}
				for(int k=0;k<26;++k) {if(connected[k]==large) connected[k]=small;}
			}
		}
		//for(int j=0;j<26;++j) cout<<static_cast<char>((used[j]?'A':'a')+connected[j]); 
		bool plusOne=false,minusOne=false,possible=true;
		int tag=-1;
		for(int j=0;j<26;++j){
			if(used[j]){
				if(tag==-1) tag=connected[j];
				else if(tag!=connected[j]){possible=false;break;}
			}
			if(degree[j]==0) continue;
			if(degree[j]==1 && !plusOne){plusOne=true; continue;}
			if(degree[j]==-1 && !minusOne){minusOne=true; continue;}
			possible=false;
			break;
		}
		if(possible) cout<<"Ordering is possible."<<endl;
		else cout<<"The door cannot be opened."<<endl; 
	}
	return 0;
}
