#include <iostream>
#include <list>
#include <string>
using namespace std;

typedef list<int> List;
typedef List::iterator It;

const int MAXLEN=25;
int location[MAXLEN+10];
It iter[MAXLEN+10];
List blocks[MAXLEN+10];

void clear(int i){
	int p=location[i];
	while(true){
		It itb=blocks[p].end(); --itb;
		if(itb==iter[i]) break;
		int b=*itb;
		blocks[b].splice(blocks[b].end(),blocks[p],itb);
		location[b]=b;	
	}
}
int main(){
	while(1){
	int num;
	cin>>num;
	for(int i=0;i<num;i++){
		blocks[i].push_back(i);
		location[i]=i;
		iter[i]=blocks[i].begin();
	}
	
	while(1){
		string command,method;
		int src,dest;
		cin>>command;
		if(cin.eof()) return 0;
		if(command=="quit") break;
		cin>>src>>method>>dest;
		//cout<<m_index.find(src)->second<<m_index.find(dest)->second<<endl;
		if(location[src]==location[dest]) continue;
		if(command=="move") clear(src);
		if(method=="onto") clear(dest);
		//Pair &psrc=m_index.find(src)->second, &pdest=m_index.find(dest)->second;
		blocks[location[dest]].splice(blocks[location[dest]].end(),blocks[location[src]],iter[src],blocks[location[src]].end());
		for(It it=iter[src];it!=blocks[location[dest]].end();++it){
			location[*it]=location[dest];	
		}
		/*for (int i=0;i<num;i++){
		cout<<i<<":";
		for(It it=blocks[i].begin();it!=blocks[i].end();++it) cout<<" "<<*it;
		cout<<endl;	
		}*/
	}
	for (int i=0;i<num;i++){
		cout<<i<<":";
		for(It it=blocks[i].begin();it!=blocks[i].end();++it) cout<<" "<<*it;
		cout<<endl;	
		blocks[i].clear();
	}
	}
	return 0;	
}
