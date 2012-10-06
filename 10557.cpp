#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct Room{
	int energy;
	int maxEnergy;
	bool reachable;
	vector<int>adjacent;
	vector<int>reverseAdj;
};
struct State{
	int energy;
	int room;
};
int main(){
	while(1){
		int n_rooms;
		cin>>n_rooms;
		if(n_rooms<0) break;
		int dest=n_rooms-1;
		vector<Room> rooms;
		for(int i=0;i<n_rooms;++i) rooms.push_back(Room());
		for(vector<Room>::iterator it=rooms.begin();it!=rooms.end();++it){
			int buf;
			cin>>buf;
			it->energy=buf;
			it->maxEnergy=-1;
			it->reachable=false;
			int n_adjacents;
			cin>>n_adjacents;
			for(int j=0;j<n_adjacents;++j){
				cin>>buf;
				--buf;
				it->adjacent.push_back(buf);
				rooms[buf].reverseAdj.push_back(it-rooms.begin());
			}
		}
		deque<int> backtrace;
		backtrace.push_back(dest);
		while(!backtrace.empty()){
			int i=backtrace.front();
			backtrace.pop_front();
			if(rooms[i].reachable) continue;
			rooms[i].reachable=true;
			for(vector<int>::iterator it=rooms[i].reverseAdj.begin(); it!=rooms[i].reverseAdj.end();++it)
				backtrace.push_back(*it);
		}
		/*for(vector<Room>::iterator it=rooms.begin();it!=rooms.end();++it){
			cout<<it->energy<<" "<<it->maxEnergy<<" "<<it->reachable<<endl<<"    ";
			for(vector<int>::iterator it2=it->adjacent.begin();it2!=it->adjacent.end();++it2)
				cout<<*it2<<" ";
			cout<<" #### ";
			for(vector<int>::iterator it2=it->reverseAdj.begin();it2!=it->reverseAdj.end();++it2)
				cout<<*it2<<" ";
			cout<<endl;
		}*/
		deque<State> states;
		State state;
		state.energy=100;
		state.room=0;
		states.push_back(state);
		bool winnable=false;
		while(!states.empty()){
			state=states.front();
			states.pop_front();
			state.energy+=rooms[state.room].energy;
			//cout<<state.room<<" "<<state.energy<<" ##"<<rooms[state.room].maxEnergy<<" "<<rooms[state.room].reachable<<endl;
			if(!rooms[state.room].reachable) continue;
			if(state.energy<=0) continue;
			if(state.energy<=rooms[state.room].maxEnergy) continue;
			rooms[state.room].maxEnergy=state.energy;
			if(state.room==dest){
				winnable=true;
				break;
			}
			for(vector<int>::iterator it=rooms[state.room].adjacent.begin();
				it!=rooms[state.room].adjacent.end(); ++it){
				State state2;
				state2.energy=state.energy;
				state2.room=*it;
				states.push_back(state2);
			}
		}
		if(winnable) cout<<"winnable"<<endl;
		else cout<<"hopeless"<<endl;
	}
	return 0;
}
