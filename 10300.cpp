#include <iostream>
using namespace std;

int main(){
	long long sq,animal,ef;
	int n,f,i,j;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>f;
		long sum=0;
		for(j=0;j<f;j++){
			cin>>sq>>animal>>ef;
			sum+=sq*ef;
		}
		cout<<sum<<endl;
	}
	return 0;
}