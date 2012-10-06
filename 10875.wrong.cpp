#include <iostream>
#include <deque>
using namespace std;

typedef pair<char,int> Pair;
typedef deque<Pair> Deque;
char vowel[]="AUEOI";
char consonant[]="JSKTLMVNWXPYQZR";
char buf[1000];

int main(){
	Deque origV,origC,workV,workC;
	for(size_t i=0;i<strlen(vowel);i++) origV.push_back(make_pair(vowel[i],21));
	for(size_t i=0;i<strlen(consonant);i++) origC.push_back(make_pair(consonant[i],5));
	int cases;
	cin>>cases;
	for(int i=1;i<=cases;i++){
		workV=origV; workC=origC;
		int n;
		cin>>n;
		for(int j=0;j<n;j++){
			Deque* d;
			if(j%2==0) d=&workV; else d=&workC;
			if(d->front().second==0) d->pop_front();
			d->front().second--;
			buf[j]=d->front().first;
		}
		buf[n]=0;
		cout<<"Case "<<i<<": "<<buf<<endl;
	}
	return 0;	
}
