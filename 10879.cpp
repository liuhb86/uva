#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

const int MAX_FACTOR=4000;

vector<int> prime;
void primeGen(){
	prime.reserve(600);
	bitset<MAX_FACTOR+30> b;
	b.reset();
	for(int i=2;i<=MAX_FACTOR;i++){
		if(b.test(i)) continue;
		prime.push_back(i);
		for(int j=i+i;j<=MAX_FACTOR;j+=i) b.set(j);		
	}
	//cout<<prime.size();
}

int main(){
	primeGen();	
	int kase;
	cin>>kase;
	for(int i=1;i<=kase;i++){
		int n0,n;
		bool found=false;
		cin>>n0;
		n=n0;
		cout<<"Case #"<<i<<": "<<n<<" = ";

		for(vector<int>::iterator it=prime.begin();it!=prime.end();it++){
			int p=*it;
			while(n%p==0){
				n/=p;
				cout<<n0/n<<" * "<<n;
				if(!found){
					cout<<" = ";
					found=true;
				}else{
					cout<<endl;
					goto break1;
				}
			}
		}
break1:
		;
	}
}
