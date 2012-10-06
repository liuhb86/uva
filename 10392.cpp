#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

vector<int> prime;
void primeGen(){
	prime.reserve(79000);
	bitset<1000000+10> b;
	b.reset();
	b.set(0);b.set(1);
	for(int i=2;i<1000000;i++){
		if(b.test(i)) continue;
		prime.push_back(i);
		for(int j=i+i;j<1000000;j+=i) b.set(j);
	}
	//cout<<prime.size()<<endl;
}

int main(){
	primeGen();
	while(1){
		long long n;
		cin>>n;
		if(n<=0) break;	
		for(vector<int>::iterator it=prime.begin();it!=prime.end();it++){
			if(n==1) break;
			int p=*it;
			while(n%p==0){ cout<<"    "<<p<<endl; n=n/p;}
		}
		if(n>1) cout<<"    "<<n<<endl;
		cout<<endl;
	}
	return 0;	
}
