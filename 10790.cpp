#include <iostream>
using namespace std;

int main(){
	int kase=0;
	while(1){
		unsigned long long  a,b;
		cin>>a>>b;
		if(a==0) break;
		kase++;	
		//too slow;
		/*for(unsigned long long i=0;i<a;i++){
			for( int j=0;j<b;j++){
				sum+=i*(b-1-j)+j*(a-1-i);	
			}
		}
		sum/=2
		*/   
		unsigned long long sum=b*(b-1)/2*a*(a-1)/2;
		cout<<"Case "<<kase<<": "<<sum<<endl;
	}
	
	return 0;	
}
