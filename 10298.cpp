//10298 - Power Strings
//string, kmp

#include <iostream>
#include <string>
using namespace std;

int k[1000000+10];
int main(){
	string s;
	while(true){
		getline(cin,s);
		if (s==".") break;
		const char* p =s.c_str();
		size_t len = s.size();
		k[0]=-1;
		int q=-1;
		for(size_t i=1;i<len; ++i){
			while(q!=-1 && p[q+1]!=p[i])
				q=k[q];
			if (p[q+1]==p[i]) q=q+1;
			k[i]=q;
		}
		//for(size_t i=0;i<len;++i) cout<<k[i]<<' ';
		cout<<len/(len-q-1)<<endl;
	}

}