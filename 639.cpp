#include <iostream>
#include <cstring>
using namespace std;

int max_r,num_r;
int n,size,n2;
const char SPACE='.';
const char WALL='X';
void solve(const char* const p, int loc){
	if(loc==n2){
		if(num_r>max_r) max_r=num_r;
		return ;
	}
	solve(p,loc+1);
	if(p[loc]==SPACE){
		char* pnew=new char[size];
		memcpy(pnew,p,size);
		pnew[loc]=WALL;
		for(int i=loc+1;i%n!=0;++i){
			if(pnew[i]==WALL) break;
			pnew[i]=WALL;
		}
		for(int i=loc+n;i<n2;i+=n){
			if(pnew[i]==WALL) break;
			pnew[i]=WALL;
		}
		++num_r;
		solve(pnew,loc+1);
		--num_r;
		delete[] pnew;
	}
} 
int main(){
	while(1){
		cin>>n;
		if(n==0) break;
		n2=n*n;
		size=n2+5;
		char *p=new char[size];
		cin.getline(p,n);
		for(int i=0;i<n;++i) cin.getline(p+i*n,n+1);
		max_r=0;
		num_r=0;
		solve(p,0);
		cout<<max_r<<endl;
		delete[] p;
	}
	return 0;
}
