#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef string::iterator It;

string fstr[10+5];
string rstr[10+5];
int main(){
	while(true){
		int n;
		cin>>n;
		if(n==0) break;
		string text;
		getline(cin,text);
		for(int i=0;i<n;i++){
			getline(cin,fstr[i]);	
			getline(cin,rstr[i]);
		}
		
		getline(cin,text);
		for(int i=0;i<n;i++){
			while(true){
				It f=search(text.begin(),text.end(),fstr[i].begin(),fstr[i].end());
				if(f==text.end()) break;
				//cout<<text<<"--"<<fstr[i]<<"--"<<rstr[i]<<"--"<<i<<endl;
				f=text.erase(f,f+fstr[i].length());
				text.insert(f,rstr[i].begin(),rstr[i].end());
				//cout<<text;return 0;
			}
		}
		cout<<text<<endl;
	}
	return 0;	
}
