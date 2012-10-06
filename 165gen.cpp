#include <iostream>
using namespace std;

int n[15][15];
int value[15][15][15];

int main(){
	for(int i=1;i<9;++i){
		for(int j=1;j<10-i;++j)
			cout<<i<<" "<<j<<endl;
	}
	cout<<"0 0"<<endl;
	return 0;
}
