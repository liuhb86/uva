#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

typedef vector<int> Vec;

Vec pancake;

void print(){
	cout<<endl;
	for(Vec::iterator it=pancake.begin();it!=pancake.end();++it)
	cout<<*it<<' ';
	cout<<endl;
}
void flip(int i){
	cout<<pancake.size()-i<<" ";
	reverse(pancake.begin(),pancake.begin()+i+1);
	//print();	
}

int main(){
	string s;
	while(getline(cin,s)){
		cout<<s<<endl;
		istringstream iss(s);	
		pancake.clear();
		int k;
		while(iss>>k){
			pancake.push_back(k);
		}
		Vec dest(pancake);
		sort(dest.begin(),dest.end());
		for(int i=pancake.size()-1;i>=0;i--){
			if(pancake[i]==dest[i]) continue;
			int j;
			for(j=0; j<i;j++) if(pancake[j]==dest[i]) break;
			if(j!=0) flip(j);
			flip(i);
		}
		cout<<'0'<<endl;
	}
	return 0;	
}
