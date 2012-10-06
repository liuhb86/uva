#include <iostream>
#include <bitset>
using namespace std;

bitset<10000+50> bit;
int main(){
	int kase=0;
	while(1){
		int z,i,m,l;
		cin>>z>>i>>m>>l;
		if(z==0 && i==0 && m==0 && l==0) break;
		kase++;
		bit.reset();
		int loop=0;
		while(1){
			l=(z*l+i)%m;
			if(bit.test(l)) break;
			bit.set(l);
			loop++;	
		}
		cout<<"Case "<<kase<<": "<<loop<<endl;
	}
	return 0;	
}
