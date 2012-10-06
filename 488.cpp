#include <iostream>
using namespace std;

int main(){
	int cases;
	char buf[10];
	cin>>cases;

	for(int i=0;i<cases;i++){
		cin.getline(buf,10);
		cin.getline(buf,10);
		int amp,freq;
		cin>>amp>>freq;
		for(int j=0;j<freq;j++){
			for(int k=1;k<=amp;k++){
				for(int p=0;p<k;p++) cout<<k;
				cout<<endl;	
			}
			for(int k=amp-1;k>=1;k--){
				for(int p=0;p<k;p++) cout<<k;
				cout<<endl;						
			}
			if (i!=cases-1 || j!=freq-1) cout<<endl;	
		}
	}
	
	return 0;
}
