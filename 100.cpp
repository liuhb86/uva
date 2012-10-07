#include <iostream>
using namespace std;

int main(){
	int aa,bb;
	while(cin>>aa>>bb){
		int a,b;
		if (aa<bb){
			a=aa;b=bb;
		}else {
			a=bb; b=aa;
		}
		int max = 0;
		for(int k=a;k<=b;++k){
			int c=0;
			int n=k;
			while(true){
				++c;
				if (n==1) break;
				if ((n&1)==0) n>>=1;
				else n=3*n+1;
			}
			if (c>max) max=c;
		}
		cout<<aa<<' '<<bb<<' '<<max<<endl;
	
	}
	return 0;
}