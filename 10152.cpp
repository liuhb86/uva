#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

typedef list<string> List;
typedef List::iterator It;
typedef map<string,string*> Map;
typedef List::reverse_iterator RIt;

int main(){
	List orig, dest;
	Map index;
	string buffer;
	int kase;
	cin>>kase;
	for(int i=0;i<kase;i++){
		int n;
		cin>>n;
		getline(cin,buffer);
		for(int i=0;i<n;i++){
			getline(cin,buffer);
			orig.push_back(buffer);
			index.insert(make_pair(buffer,&(orig.back())));
		}
		for(int i=0;i<n;i++){
			getline(cin,buffer);
			dest.push_back(buffer);
		}
		It it,oit;
		it=dest.begin();
		oit=orig.begin();
		while(it!=dest.end()){
			It dit=it;
			bool match=true;
			while(dit!=dest.end()){
				while(*oit=="*") ++oit;
				if(*dit!=*oit) {match=false; break;}
				++dit; ++oit;
			}
			if(match) break;
			*(index[*dit])="*";
			it=dit; ++it;
		}
		for(RIt rit=RIt(it);rit!=dest.rend();++rit){
			cout<<(*rit)<<endl;
		}
		cout<<endl;

		orig.clear();
		dest.clear();
		index.clear();
	}
	return 0;
}
