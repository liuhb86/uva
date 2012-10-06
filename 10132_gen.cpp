#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	cout<<10<<endl;
	srand(time(0));
	for(int i=0;i<10;++i);{
		cout<<endl;
		char buf[30];
		
		for(int i=0;i<15;++i){
			buf[i]=rand()%2;
		}

		
	}
}
