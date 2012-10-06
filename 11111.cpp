#include <iostream>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

struct Matrioshkas{
	int capacity;
	int space;
	Matrioshkas(int capacity):capacity(capacity),space(capacity){}
};

typedef deque<Matrioshkas> Stack;

int main(){
	string buffer;
	Stack stack_matrioshkas;
	while(getline(cin,buffer)){
		stack_matrioshkas.clear();
		istringstream iss(buffer);
		int matrio;
		bool fit=true;
		bool first=true;
		while(iss>>matrio){
			//cout<<matrio<<endl;
			if(matrio<0){
				if(!stack_matrioshkas.empty()){
					Matrioshkas& m=stack_matrioshkas.back();
					if(-matrio>=m.space){fit=false; break;}
					m.space-=-matrio;
				}else{
					if(!first){fit=false;break;}
				}
			   	stack_matrioshkas.push_back(Matrioshkas(-matrio));
			}else{
				if(stack_matrioshkas.empty() ||
				   stack_matrioshkas.back().capacity!=matrio){
					fit=false;
					break;
				}
				stack_matrioshkas.pop_back();
			}
			first=false;
		}
		if(fit && stack_matrioshkas.empty()) cout<<":-) Matrioshka!"<<endl;
		else cout<<":-( Try again."<<endl;		
	}	
	return 0;
}
