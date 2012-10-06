#include <iostream>
using namespace std;

char buffer[10000];
int factor[100];
int main(){
	int kase=0;
	while(1){
		int n;
		cin>>n;
		if(n==0) break;
		++kase;
		cout<<"S-Tree #"<<kase<<":"<<endl;
		for(int i=0;i<n;++i){
			char c;
			cin>>c;
			int p;
			cin>>p;
			factor[p-1]=1<<(n-i-1);
		}
		cin.getline(buffer,sizeof(buffer));
		cin.getline(buffer,sizeof(buffer));
		int n_vva;
		cin>>n_vva;
		for(int i=0;i<n_vva;++i){
			int index=0;
			for(int j=0;j<n;++j){
				char c;
				cin>>c;
				index+=(c-'0')*factor[j];
			}
			cout<<buffer[index];
		}
		cout<<endl<<endl;
	}
}
