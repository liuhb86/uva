#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
using namespace std;

struct ichar_traits :char_traits<char>{
	static int comp(char c1,char c2){return toupper(c1)-toupper(c2);}
	static bool eq(char c1,char c2){return comp(c1,c2)==0;}
	static bool ne(char c1,char c2){return !eq(c1,c2);}
	static bool lt(char c1,char c2){return comp(c1,c2)<0;}
	static int compare(const char* s1,const char* s2,size_t n){
		for(size_t i=0;i<n;i++){
			if(*s1==0) return -1;
			if(*s2==0) return 1;
			if(ne(*s1,*s2)) return comp(*s1,*s2);
			++s1;++s2;	
		}
		return 0;
	}
	static const char* find(const char* s,size_t n,char c){
		for(size_t i=0;i<n;i++){
			if(*s==0) return 0;
			if(*s==c) return s;
			++s;	
		}
		return 0;
	}
};


typedef basic_string<char,ichar_traits> IString;
typedef set<string> Set;
typedef map<IString,string> Map;
int main(){
	Map list;
	string word;
	while(1){
		cin>>word;
		if(word=="#") break;
		IString key(word.c_str());
		//transform(key.begin(),key.end(),key.begin(),ptr_fun(toupper));
		sort(key.begin(),key.end(),ptr_fun(ichar_traits::lt));
		Map::iterator it=list.find(key);
		if(it== list.end()) list.insert(make_pair(key,word));
		else it->second="#";
	}
	Set ananagram;
	for(Map::iterator it=list.begin();it!=list.end();++it){
		if(it->second!="#") ananagram.insert(it->second);
	}
	for(Set::iterator it=ananagram.begin();it!=ananagram.end();++it){
		cout<<*it<<endl;
	}
	return 0;	
}
