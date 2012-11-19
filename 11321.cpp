//11321 - Sort! Sort!! and Sort!!!
//sort, mod

#include <iostream>
#include <algorithm>
using namespace std;

struct Number {
	int num;
	int remainder;
	bool isOdd;
};

bool cmp(Number a, Number b){
	if (a.remainder < b.remainder) return true;
	if (a.remainder > b.remainder) return false;
	if (a.isOdd){
		if (b.isOdd) return a.num>b.num;
		else return true;
	} else {
		if (b.isOdd) return false;
		else return a.num<b.num;
	}
}

Number numbers[10000+10];

int main() {
	while(true){
		int n, m;
		cin>>n>>m;
		cout<<n<<' '<<m<<endl;
		if (n==0) break;
		for (int i=0;i<n;++i){
			int num;
			cin>>num;
			numbers[i].num=num;
			numbers[i].remainder = num%m;
			numbers[i].isOdd = (num & 1);
		}
		sort(numbers, numbers+n, cmp);
		for(int i=0;i<n;++i)
			cout<<numbers[i].num<<endl;
	}	
	return 0;
}