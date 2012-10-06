#include <iostream>
#include <map>
#include <cstring>

using namespace std;
typedef map<string,int> Map;
char remap[]="11112ABC3DEF4GHI5JKL6MNO7PRS8TUV9WXY0000";
char table[200];
char buf[10];
int main(){
	for(int i=0;i<40;i++){
		table[remap[i]]=remap[i/4*4];	
	}
	string s;
	Map numbers;
	int cases;
	cin>>cases;
	bool first=true;
	for(int i=0;i<cases;i++){
		if(first) first=false; else cout<<endl;
		numbers.clear();
		int n;
		cin>>n;
		getline(cin,s);
		for(int j=0;j<n;j++){
			int k=0;
			while(k<7){
				char c;
				cin>>c;
				if(c=='-') continue;
				buf[k++]=table[c];
			}
			getline(cin,s);
			buf[k]=0;
			s.assign(buf); 
			Map::iterator it=numbers.find(s);
			if(it==numbers.end()) it=numbers.insert(make_pair(s,0)).first;
			it->second++;
		}
		bool empty=true;
		for(Map::iterator it=numbers.begin();it!=numbers.end();++it){
			if(it->second>1){
				for(int i=0;i<3;i++) cout<<it->first[i];
				cout<<'-';
				for(int i=3;i<7;i++)cout<<it->first[i];	
				cout<<' '<<it->second<<endl;
				empty=false;
			}
		}
		if(empty) cout<<"No duplicates."<<endl;
	}
	
	return 0;	
}
