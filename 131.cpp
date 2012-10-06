#include <iostream>
#include <algorithm>
using namespace std;

struct Card{
	char suit;
	int rank;
	char c_rank;
};
ostream& operator<<(ostream& os,const Card& card){
	os<<card.c_rank<<card.suit;
	return os;
}
void getCard(Card& card){
	cin>>card.c_rank;
	switch(card.c_rank){
		case 'T': card.rank=10;break;
		case 'J': card.rank=11;break;
		case 'Q': card.rank=12;break;
		case 'K': card.rank=13; break;
		case 'A': card.rank=14; break;
		default: card.rank=card.c_rank-'0';
	}
	cin>>card.suit;
}
bool isNext(Card c1,Card c2){
	if(c1.rank==2 && c2.c_rank=='A') return true;
	return (c1.rank==c2.rank+1);
}
bool cardGT(Card c1,Card c2){
	return c1.rank>c2.rank;
}
int getCategory(Card* p){
	int rankCount[13+5]={0};
	int numberCount[5+5]={0};
	bool flush=true;
	for(int i=0;i<5;++i){
		++rankCount[p[i].rank];
		if(p[i].suit!=p[0].suit) flush=false;
	}
	for( int i=2;i<=14;++i) ++numberCount[rankCount[i]];
	sort(p,p+5,cardGT);
	p[5]=p[0];
	bool straight=true;
	for(int i=0;i<4;++i) if(!isNext(p[i],p[i+1])) {straight=false;break;}
	if(!straight){
		straight=true;
		for(int i=1;i<5;++i) if(!isNext(p[i],p[i+1])){straight=false; break;}
	}
	int rank=0;
	if(straight && flush) return rank; 	//straight flush
	++rank;
	if(numberCount[4]>0) return rank;	//four of a kind
	++rank;
	if(numberCount[3]>0 && numberCount[2]>0) return rank;	//full house
	++rank;
	if(flush) return rank;		//flush
	++rank;
	if(straight) return rank;		//straight
	++rank;
	if(numberCount[3]>0) return rank;	//three of a kind
	++rank;
	if(numberCount[2]==2) return rank;	//two pair;
	++rank;
	if(numberCount[2]==1) return rank;	//one pair;
	++rank;
	return rank;		//high card
}
char strCategory[][100]={"straight-flush","four-of-a-kind","full-house","flush","straight","three-of-a-kind","two-pairs","one-pair","highest-card"};

int main(){
	while(1){
		Card original[5+5];
		Card deck[5+5];
		Card hand[5+5];
		int cat=1000;
		for(int i=0;i<5;++i) getCard(original[i]);
		if(cin.eof()) break;
		for(int i=0;i<5;++i) getCard(deck[i]);
		for(int i=0;i<32;++i){
			int j=i;
			int curDeck=0;
			for(int k=0;k<5;++k){
				if(j%2==0) hand[k]=original[k]; else hand[k]=deck[curDeck++];
				j>>=1;
			}
			int temp_cat=getCategory(hand);
			if(temp_cat<cat) cat=temp_cat;
		}
		cout<<"Hand: ";
		for(int i=0;i<5;++i) cout<<original[i]<<' ';
		cout<<"Deck: ";
		for(int i=0;i<5;++i) cout<<deck[i]<<' ';
		cout<<"Best hand: "<<strCategory[cat]<<endl;

	}
	return 0;
}
