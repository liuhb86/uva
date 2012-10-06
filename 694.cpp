#include <iostream>
using namespace std;

int main(){
	int n=0;
	int a,A,L;
	cin>>a>>L;
	while(a>0 && L>0){
		n++;
		A=a;
		int steps=0;
		int limit=(L-1)/3;
		while(true){
			steps++;
			if(A==1) break;
			if(A%2==0) A/=2;
			else if(A>limit) break;
			else  A=A*3+1;
		}
		cout<<"Case "<<n<<": A = "<<a<<", limit = "<<L<<", number of terms = "<<steps<<endl;
		cin>>a>>L;
	}
	
	return 0;	
}
