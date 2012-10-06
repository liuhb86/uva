#include<iostream>
using namespace std;
int stack[100];
int main(){
	int cases=0;
	while(true){
		int n;
		cin>>n;
		if(n==0) break;
		cases++;
		int sum=0;
		for(int i=0;i<n;i++){
			int h;
			cin>>h;
			stack[i]=h;
			sum+=h;
		}
		int height=sum/n;
		int move=0;
		for(int i=0;i<n;i++)
			if(stack[i]>height) move+=stack[i]-height;
		cout<<"Set #"<<cases<<endl<<"The minimum number of moves is "<<move<<"."<<endl<<endl;

	}
	
	return 0;	
}
