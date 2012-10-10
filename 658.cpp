//658 - It's not a Bug, it's a Feature!
//graph, shortest path, djikstra, bitset
#include <iostream>
#include <set>
#include <queue>
#include <cstring>
using namespace std;

int get(int b, int i){ return (b & (1<<i))>>i; }
int setb(int b, int i){ return b | (1<<i);}
int clear(int b, int i){ return b & ~(1<<i);}
int flip(int b, int i){ return b ^ (1<<i);}

char buffer[100];
int nBugs;

struct Cond{
	int zero;
	int sign;
	void read(char* s) {
		zero = sign =0;
		for(int i=0;s[i]!=0; ++i){
			if (s[i]=='0') {
				zero = clear(zero,i);
				sign = clear(sign,i);
			}else{
				zero = setb(zero,i);
				if (s[i]=='+')
					sign = setb(sign, i);
				else
					sign = clear(sign,i);
			}
		}
	}
};
struct Patch{
	Cond preCond;
	Cond fix;
	int cost;
};
struct State{
	int state;
	int cost;
	bool operator <  (State b) const {return cost>b.cost;}
	State patch(Patch p) const {
		State s;	
		//check precondition;
		if ( ((p.preCond.sign ^ state) & p.preCond.zero) !=0) {
			//not valid
			s.cost = -1;
			return s;
		}
		/*for(int i=0;i<nBugs; ++i){
			if (get(p.preCond.zero,i)==1) continue;
			if (get(p.preCond.sign,i) == get(state,i)) continue;}
		*/

		//patch
		s.state = (state & (~p.fix.zero)) | p.fix.sign;                                        
		/*for(int i=0;i<nBugs; ++i){
			if(get(p.fix.zero,i)==1) continue;
			if(get(p.fix.sign, i) == 1)
				s.state = setb(s.state, i);
			else
				s.state = clear(s.state, i);
		}*/
		s.cost= cost + p.cost;
		return s;
	}
};


Patch patches[100+10];
int d[1<<22];

int main(){
	int kase =0;
	while (true){
		int n,m;
		cin>>n>>m;
		if(n==0) break;
		++kase;
		priority_queue<State> que;
		//set<int> visited;
		memset(d,-1, ((1<<n)+10)*sizeof(*d));
		nBugs = n;
		for(int i=0;i<m;++i){
			cin>>patches[i].cost;
			cin>>buffer;
			patches[i].preCond.read(buffer);
			cin>>buffer;
			patches[i].fix.read(buffer);
		}
		State s;
		s.state = (1<<n) -1;
		s.cost = 0;
		que.push(s);
		State result = s;
		while (!que.empty()){
			State s = que.top();
			que.pop();
			//if (visited.count(s.state)>0) continue;
			if (d[s.state]>=0 && s.cost > d[s.state]) continue;
			//visited.insert(s.state);
			if (s.state ==0) {result = s; break;}
			for (int i=0;i<m; ++i){
				State t = s.patch(patches[i]);
				if (t.cost>=0 && (d[t.state]<0 || t.cost<d[t.state])){
					d[t.state]=t.cost;
					que.push(t);
				}
			}
		}
		cout<<"Product "<<kase<<endl;
		if (result.state ==0)
			cout<<"Fastest sequence takes "<<result.cost<<" seconds."<<endl;
		else 
			cout<<"Bugs cannot be fixed."<<endl;
		cout<<endl;
	}
	return 0;
}