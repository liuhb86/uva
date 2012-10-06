#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long long  W,I;
	while(1){
		cin>>I>>W;
		if(I==0) break;
		int d;
		long long N1,N;
		for(d=1;d<40;d++){
			N1=(exp(log(I)/d)+.5);
			if(abs(pow((double)N1,d)-I)<0.1 && abs(pow((double)(N1-1),d)-W)<0.1) break;	
		}
		N=N1-1;
		//cout<<N1<<" "<<d<<endl;
		long long  total=0,sum=0,n=1;
		for(int i=1;i<=d+1;i++){
			total+=n;
			sum+=n*I;
			n*=N;
			I/=N1;
		}
		cout<<total-W<<" "<<sum<<endl;
	}
	return 0;	
}
