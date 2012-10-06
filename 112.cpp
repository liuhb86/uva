#include <iostream>
#include <deque>
#include <cctype>
using namespace std;

typedef deque<int> Stack;
int main(){
	Stack s;
	int sum;
	char c;
	while(cin>>sum){
		bool found=false;
		int success=0;
		bool enter=false;
		bool minus=false;
		int buffer=0;
		//cin>>c;  //assert(c=='(');
		//s.push_back(0);
		
		while(true){
			cin>>c;
			if(isdigit(c)){
				success=0;
				enter=true;
				buffer=buffer*10+c-'0';
			}
			else if(c=='+'){
				success=0;
				enter=true;
			}else if(c=='-'){
				success=0;
				enter=true;
				minus=true;			
			}else if(c=='('){
				if(success==2) success=3; else success=0;
				if(enter){
					s.back()=minus?-buffer:buffer;
					enter=false;
					buffer=0;
					minus=false;
					sum-=s.back();
					if(sum==0) success=1;
				}
				s.push_back(0);
			}else if(c==')'){
				if(success==1) success=2;
				else if(success==3){ success=4;break;}
				else success=0;
				sum+=s.back();
				s.pop_back();
				if(s.empty()) break;
			}
			/*cout<<"--------"<<endl<<c<<" S="<<success<<" E="<<enter<<" M="<<minus<<" B="<<buffer<<endl<<
				"sum="<<sum<<" Stack:";
			for(Stack::iterator it=s.begin();it!=s.end();++it) cout<<" "<<*it;
			cout<<endl;*/
		}
		if(success==4) {
			cout<<"yes"<<endl;
			//clean up
			int bracket=s.size()-1;
			s.clear();
			if(bracket>0) while(1){
				cin>>c;
				if(c=='(') ++bracket;
				else if(c==')'){
					--bracket;
					if(bracket==0) break;
				}
			}	
		}
		else cout<<"no"<<endl;
	}
	return 0;	
}
