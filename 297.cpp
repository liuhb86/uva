#include <iostream>
//#include <iomanip>
using namespace std;

struct QuadTree{
	QuadTree* children[4];
	char type;
	friend void delQuadTree(QuadTree* qt){
		if(qt->type=='p') for(int i=0;i<4;++i) delQuadTree(qt->children[i]);
		delete qt;
	}
	/*void print(int indent){
		cout<<setw(indent+1)<<type<<endl;
		if(type=='p') for(int i=0;i<4;++i) children[i]->print(indent+1);
	}*/
};

QuadTree* build(){
	QuadTree* qt=new QuadTree();
	cin>>qt->type;
	if(qt->type=='p')
		for(int i=0;i<4;++i) qt->children[i]=build();
	return qt;
}

int count(QuadTree* qt,int allBlack){
	if(qt->type=='e') return 0;
	if(qt->type=='f') return allBlack;
	int sum=0;
	for(int i=0;i<4;++i) sum+=count(qt->children[i],allBlack/4);
	return sum;
}
int  count(QuadTree* qt1,QuadTree* qt2,int allBlack){
	if(qt1->type=='f' || qt2->type=='f') return allBlack;
	if(qt1->type=='e') return count(qt2,allBlack);
	if(qt2->type=='e') return count(qt1,allBlack);
	//assume(qt1->type=='p' && qt2->type=='p');
	int sum=0;
	for(int i=0;i<4;++i) sum+=count(qt1->children[i],qt2->children[i],allBlack/4);
	return sum;
}
const int ALL_BLACK=32*32;
int main(){
	int kase;
	cin>>kase;
	for(int i=0;i<kase;++i){
		//alloc=0;
		QuadTree* qt1=build();
		//qt1->print(0);
		//cout<<count(qt1,ALL_BLACK)<<endl;
		QuadTree* qt2=build();
		//cout<<count(qt2,ALL_BLACK)<<endl;
		//qt2->print(0);
		int black=count(qt1,qt2,ALL_BLACK);
		cout<<"There are "<<black<<" black pixels."<<endl;
		delQuadTree(qt1);
		delQuadTree(qt2);
	}
	return 0;
}

