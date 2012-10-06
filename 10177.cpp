#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		unsigned long long s0,s1,s2,s3,s4,ps;
		unsigned long long r1,r2,r3,r4;
		s0=n+1;
		ps=s0*s0;
		s1=(ps-s0)/2;
		ps*=s0;
		s2=(ps-3*s1-s0)/3;
		ps*=s0;
		s3=(ps-6*s2-4*s1-s0)/4;
		ps*=s0;
		s4=(ps-10*s3-10*s2-5*s1-s0)/5;
		r1=s0*n/2;
		r2=r1*r1;
		r3=r2*r1;
		r4=r3*r1;
		r2-=s2;
		r3-=s3;
		r4-=s4;
		cout<<s2<<" "<<r2<<" "<<s3<<" "<<r3<<" "<<s4<<" "<<r4<<endl;
	}
	return 0;	
}
