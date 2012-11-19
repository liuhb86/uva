//624 - CD
//DP, packing
#include <iostream>
#include <map>
using namespace std;

int tracks[20+5];

struct Key{
	Key(int n, int size):n(n),size(size){}
	int n;
	int size;
	bool operator< (const Key k) const {
		return n<k.n || (n==k.n && size<k.size);
	}
};

struct Value{
	Value(int max, bool chosen):max(max),chosen(chosen){}
	int max;
	bool chosen;
};

map<Key,Value> table;

int solve(int limit, int n){
	if (n<0){
		return 0;
	}
	map<Key,Value>::iterator it = table.find(Key(limit,n));
	if (it!=table.end()){
		return it->second.max;
	}
	bool chosen = false;
	int m=solve(limit,n-1);
	if (limit>=tracks[n]){
		int b=solve(limit-tracks[n],n-1)+tracks[n];
		if(b>m) {m=b; chosen = true;}
	}
	table.insert(make_pair(Key(limit,n),Value(m,chosen)));
	return m;
	
}

void print(int m, int index){
	if (index<0) return;
	map<Key,Value>::iterator it = table.find(Key(m,index));
	if (it->second.chosen){
		print(m-tracks[index],index-1);
		cout<<tracks[index]<<' ';
	} else {
		print(m,index-1);
	}
}

int main(){
	int n;
	while (cin>>n){
		int nTracks;
		cin>>nTracks;
		for(int i=0;i<nTracks; ++i){
			cin>>tracks[i];
		}
		table.clear();
		int m=solve(n, nTracks-1);
		print(n,nTracks-1);
		cout<<"sum:"<<m<<endl;
	}
}