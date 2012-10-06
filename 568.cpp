#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n;
	while(cin>>n){	
		int f=1;
		for(int i=2;i<=n;i++){
			f*=i;
			while(f%10==0) f/=10;
			f=f%100000;		
		}
		cout<<setw(5)<<n<<" -> "<<f%10<<endl;
	}
	return 0;	
}
