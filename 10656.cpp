#include <iostream>
using namespace std;

int main(){
	while(true){
		int n;
		cin>>n;
		if(n==0) break;
		bool first=true;
		for(int i=0;i<n;++i){
			int num;
			cin>>num;
			if(num>0){
				if(first) first=false; else cout<<' ';
				cout<<num;
			}
		}
		if (first) cout<<'0';
		cout<<endl;
	}
	return 0;
}