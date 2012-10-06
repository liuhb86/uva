#include <iostream>
#include <map>
#include <set>
using namespace std;

typedef set<string> Set;
typedef map<string,Set>  Map;
int main(){
	int n;
	cin>>n;
	Map list;
	string country,name;
	for(int i=0;i<n;i++){
		cin>>country;
		char c;
		cin>>c;
		getline(cin,name);
		name.insert(name.begin(),c);
		Map::iterator it=list.find( country);
		if(it==list.end())
			it=list.insert(make_pair( country,Set())).first;
		it->second.insert(name);	
	}
	for(Map::iterator it=list.begin();it!=list.end();++it){
		cout<<it->first<<" "<<it->second.size()<<endl;
	}
	return 0;	
}
