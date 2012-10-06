#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> Vec;

Vec marble;
int main(){
	int cases=0;
	while(1){
		int n,q;
		cin>>n>>q;
		if(n==0) break;
		++cases;
		cout<<"CASE# "<<cases<<":"<<endl;
		marble.clear();
		int k;
		for(int i=0;i<n;++i) {cin>>k;marble.push_back(k);}
		sort(marble.begin(),marble.end());
		for(int i=0;i<q;i++){
			cin>>k;
			Vec::iterator it=lower_bound(marble.begin(),marble.end(), k);
			if(it!=marble.end() && *it==k){
				cout<<k<<" found at "<<it-marble.begin()+1<<endl;
			}else{
				cout<<k<<" not found"<<endl;

			}
		}
	}
	return 0;	
}
