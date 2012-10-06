#include <iostream>
#include <deque>
#include <list>
using namespace std;

typedef pair<char,char> Pair;
typedef deque<Pair> Stack;
typedef list<Stack> List;
typedef List::iterator It;

List pile;

bool canMove(const It& src, const It& dest){
	Pair& psrc=src->back(), &pdest=dest->back();
	//cout<<"Can Move"<<(psrc.first==pdest.first || pdest.second==pdest.second)<<endl;
	return (psrc.first==pdest.first || psrc.second==pdest.second) ;
}
It canMove(const It& src){
	if(src==pile.begin()) return pile.end();
	List::iterator it=src;
	--it;
	List::iterator it2=it;

	if(it2==pile.begin()) ;
	else{
		--it2;
		if(it2==pile.begin()) ;	
		else{
			--it2;
			if (canMove(src,it2)) return it2;	
		}
	}
	if(canMove(src,it)) return it;
	else return pile.end();
}
void moveCard(const Pair& card){
	pile.push_back(Stack());
	pile.back().push_back(card);
	It it=pile.end(); --it;
	bool moved;
	do{
		moved=false;
		It it3;
		for(It it2=it;it2!=pile.end();it2++){
			it3=canMove(it2);
			if(it3!=pile.end()){
				it3->push_back(it2->back());
				it2->pop_back();
				if(it2->empty()) pile.erase(it2);
				moved=true;
				it=it3;
				break;	
			}	
		}
	}while(moved);
}

int main(){
	char incard[10];
	while(1){
		pile.clear();
		for(int i=0;i<52;i++){
			cin>>incard;
			if(*incard=='#') return 0;
			moveCard(make_pair(incard[0],incard[1]));
			/*cout<<"*****New Card: "<<incard<<endl;
			for(It it=pile.begin();it!=pile.end();++it){
				for(Stack::iterator sit=it->begin();sit!=it->end();++sit)
					cout<<sit->first<<sit->second<<" ";
				cout<<endl;	
			}*/
		}
		cout<<pile.size()<<" pile"<<((pile.size()>1)?"s":"")<<" remaining:";
		for(List::iterator it=pile.begin();it!=pile.end();it++) cout<<" "<<it->size();
		cout<<endl;
	}
	return 0;
}
