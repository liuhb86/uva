#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <functional>
using namespace std;

typedef set<string> Set;
typedef pair<string,string> Pair;
typedef vector<Pair> Vec;
char ctolower(char c){return static_cast<char>(tolower(c));}
char ctoupper(char c){return static_cast<char>(toupper(c));}

bool comp1(Pair p1, Pair p2){ return p1.first<p2.first;}

char buffer2[1000];

int main(){
	Set ignore;
	string s;
	Vec index;
	while(true){
		cin>>s;
		if(s=="::") break;
		ignore.insert(s);	
	}
	getline(cin,s);
	while(getline(cin,s)){
		string word;
		transform(s.begin(),s.end(),s.begin(),ptr_fun(ctolower));
		string lcase(s);
		istringstream iss(lcase);
		while(iss>>word){
			if(ignore.find(word)==ignore.end()){
					strcpy(buffer2,s.c_str());
					int wordEnd=iss.tellg(),wordBegin=wordEnd-word.length();
					transform(buffer2+wordBegin,buffer2+wordEnd,buffer2+wordBegin,ptr_fun(ctoupper));
					index.push_back(make_pair(word,string(buffer2)));
			}
		}
	}
	//sort(index.begin(),index,end(),comp2);
	stable_sort(index.begin(),index.end(),comp1);
	for(Vec::iterator it=index.begin();it!=index.end();++it)
		cout<<it->second<<endl;
	return 0;
}
