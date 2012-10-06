/*
BADLY DONE.
Better implentation: see 133sol
Summary:
	use STL if possible.
	Discuss with case, instead of making a univeral manipulation.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int person[20+10];


void delPerson(int &p1,int &p2,int &n){
	//Tricky, bad code
	int a=p1,b=p2;
	int i=0,j=0;
	while(j!=n){
		if(j==a || j==b){
			if(a>=j) p1--;
			if(b>=j) p2--;
			j++;
		}else{
			person[i++]=person[j++];	
		}
	}
	n=i;
	if(n==0) return;
	p1=(p1+1+n+n)%n;
	p2=(p2+n+n)%n;
}
int main(){
	while(1){
		int n,k,m;
		cin>>n>>k>>m;
		if(n==0)break;
		for(int i=0;i<n;i++) person[i]=i+1;
		k--;m--;
		int p1=0,p2=n-1;
		bool first=true;
		while(n>0){
			if(first) first=false; else cout<<",";
			p1=(p1+k)%n;
			p2=p2-m;
			if(p2<0) p2=(n-(-p2)%n);
			p2=p2%n;
			cout<<setw(3)<<person[p1];
			if(p2!=p1) cout<<setw(3)<<person[p2];
			delPerson(p1,p2,n);	
			//cout<<" ::: ";for(int i=0;i<n;i++) cout<<person[i]; cout<<"::"<<p1<<"::"<<p2<<"::"<<n<<endl;
		}
		cout<<endl;
	}
	return 0;	
}
