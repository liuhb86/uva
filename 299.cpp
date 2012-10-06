#include <iostream>
using namespace std;

const int MAXLEN=50+10;

int train[MAXLEN];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		int k;
		cin>>k;
		int reverse=0;
		for(int j=0;j<k;j++){
			int m;
			cin>>m;
			train[j]=m;
			for(int p=0;p<j;++p) if(m<train[p]) ++reverse;
		}
		cout<<"Optimal train swapping takes "<<reverse<<" swaps."<<endl;		
	}
}
