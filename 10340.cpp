#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while(cin>>s) {
		string t;
		cin>>t;
		int i=0, j=0;
		while(i<s.size() && j<t.size()) {
			if (s[i]==t[j]) {++i;++j;}
			else {++j;}
		}
		if (i==s.size()) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
