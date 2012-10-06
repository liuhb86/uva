#include <iostream>
#include <list>
#include <map>
using namespace std;

typedef list<int> List;
typedef List::iterator It;
typedef map<int,int> Map;

const int MAX_TEAM=1000;

It location[MAX_TEAM+20];
char buffer[30];

int main(){
	Map teams;
	List teamQueue;
	int kase=0;
	while(1){
		int n_teams;
		cin>>n_teams;
		if(n_teams==0) break;
		++kase;
		teams.clear();
		teamQueue.clear();
		for(int i=0;i<n_teams;++i){
			location[i]=teamQueue.end();
			int n_members;
			cin>>n_members;
			for(int j=0;j<n_members;++j){
				int member;
				cin>>member;
				teams.insert(make_pair(member,i));	
			}
		}
		cout<<"Scenario #"<<kase<<endl;
		while(1){
			cin>>buffer;
			if(buffer[0]=='S') break;		//STOP
			if(buffer[0]=='E'){		//ENQUEUE
				int member;
				cin>>member;
				int team=teams[member];
				if(location[team]==teamQueue.end()) {
					teamQueue.push_back(member);
					--location[team];
				}else{
					++location[team];
					location[team]=teamQueue.insert(location[team],member);
				}
			}else{		//DEQUEUE
				int member=teamQueue.front();
				int team=teams[member];
				if(*(location[team])==member) location[team]=teamQueue.end();
				cout<<member<<endl;
				teamQueue.pop_front();
			}
		}
		cout<<endl;
	}
	return 0;
}
