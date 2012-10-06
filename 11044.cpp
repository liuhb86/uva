#include <iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int m,n;
		cin>>m>>n;
		m-=2;n-=2;
		int x=(m-1)/3+1,y=(n-1)/3+1;
		cout<<x*y<<endl;
	}	
}
