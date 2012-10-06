#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

typedef list<char> List;
typedef List::iterator It;
typedef List::reverse_iterator Rit;

int n;
List order;

inline char var(int i){return static_cast<char>('a'+i);}
void generateCode(int index){
	if(index<n){
		It it=order.end();
		while(1){
			cout<<setw(2*index)<<' ';
			if(it!=order.end()) cout<<"else";
			if(it!=order.begin()){
				if(it!=order.end()) cout<<' ';
				It a=it; --a;
				cout<<"if "<<*a<<" < "<<var(index)<<" then";
			}
			cout<<endl;
			It inserted=order.insert(it,var(index));
			generateCode(index+1);
			order.erase(inserted);
			if(it==order.begin()) break;
			--it;
		}
	}else{
		cout<<setw(2*index)<<' ';
		cout<<"writeln(";
		bool first=true;
		for(It it=order.begin();it!=order.end();++it){
			if(first) first=false; else cout<<',';
			cout<<*it;
		}
		cout<<')'<<endl;
	}
}
int main(){
	int kase;
	bool first;
	cin>>kase;
	for(int i=0;i<kase;++i){
		if(i!=0) cout<<endl;
		cin>>n;
		cout<<"program sort(input,output);"<<endl<<"var"<<endl;
		first=true;
		for(int j=0;j<n;++j){
			if(first)first=false; else cout<<',';
			cout<<var(j);
		}
		cout<<" : integer;"<<endl<<"begin"<<endl<<"  readln(";
		first=true;
		for(int j=0;j<n;++j){
			if(first)first=false; else cout<<',';
			cout<<var(j);
		}
		cout<<");"<<endl;
		order.clear();
		order.push_back('a');
		generateCode(1);
		cout<<"end."<<endl;
	}
	return 0;
}

