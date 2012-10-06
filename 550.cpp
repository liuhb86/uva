#include <iostream>
using namespace std;

typedef int T;
int main(){
	T base,lsd,f2;
	while(cin>>base>>lsd>>f2){
		T f1=lsd;
		T digits=1;
		T c=0;
		while(true){
			T product=f1*f2+c;
			c=product/base;
			f1=product%base;
			if(c==0 && f1==lsd) break;
			digits++;
		}
		cout<<digits<<endl;
	}
	return 0;	
}
