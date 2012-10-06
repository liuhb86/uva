#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int p[10000+10];

int main(){
	int k;
	string s;
	while(cin>>k){
		getline(cin,s);
		getline(cin,s);
		istringstream iss(s);
		int n=0,a;
		while(iss>>a) p[n++]=a;
		for(int i=1;i<n;i++) p[i]+=k*p[i-1];
		cout<<"q(x):";
		for(int i=0;i<n-1;i++) cout<<' '<<p[i];
		cout<<endl<<"r = "<<p[n-1]<<endl<<endl;
	}
}
