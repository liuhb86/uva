#include <cstring>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

const int HASH_SIZE=99991;

struct HashItem{
	int from;
	int to;
	int count;
};
struct HashEntry{
	//HashItem* p;
	deque<HashItem>* p;
	int round;
};
class HashTable{
protected:
	int round;
	int count;
	HashEntry* table;
	int a[4];
public:
	HashTable();
	void clear();
	int size(){return count;}
	bool update(HashItem& item);

	int hashKey(HashItem& item);
	
};

HashTable::HashTable(){
	table=new HashEntry[HASH_SIZE];
	memset(table,0,sizeof(table)*HASH_SIZE);
	round=1;
	count=0;
	srand(time(0));
	for(int i=0;i<4;++i){
		a[i]=(rand() / ((double)RAND_MAX+1))*HASH_SIZE;
	}
}

void HashTable::clear(){
	++round;
	count=0;
}

int HashTable::hashKey(HashItem& item){
	int sum=0;
	sum=(item.from>>16)*a[0]%HASH_SIZE;
	sum+=(item.from &((1<<16) -1))*a[1]%HASH_SIZE;
	sum%=HASH_SIZE;
	sum=(item.to>>16)*a[2]%HASH_SIZE;
	sum%=HASH_SIZE;
	sum+=(item.to &((1<<16) -1))*a[3]%HASH_SIZE;
	sum%=HASH_SIZE;
	return sum;
}

bool HashTable::update(HashItem& item){
	int key=hashKey(item);
	//bool found=false;
	HashEntry& e=table[key];
	if(!e.p) {
		e.p=new deque<HashItem>();
		e.round=round;
	}
	else if(e.round!=round){
		e.p->clear();
		e.round=round;
	}
	
	deque<HashItem> & list=*(e.p);
	for(deque<HashItem>::iterator it=list.begin();it!=list.end();++it){
		if(it->from==item.from && it->to==item.to){
			it->count+=item.count;
			if (it->count==0){
				it->from=list.back().from;
				it->to=list.back().to;
				it->count=list.back().count;
				list.pop_back();
				--count;
			}
			return true;
		}
	}
	list.push_back(item);
	++count;
	return false;
}

int main(){
	while(1){
		int n;
		HashItem hi;
		int t;
		HashTable ht;
		cin>>n;
		if(n==0) break;
		for(int i=0;i<n;++i){
			cin>>hi.from>>hi.to;
			if(hi.from>hi.to){
				t=hi.from; hi.from=hi.to; hi.to=t; 
				hi.count=-1;
			}
			else
				hi.count=1;
			ht.update(hi);
		}
		if(ht.size()==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		ht.clear();
	}	
	return 0;
}
