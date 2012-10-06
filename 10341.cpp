#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;

const double eps=1e-9;

int p,q,r,s,t,u;

double f0(double x){
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double f(int xx){
	return f0((double)xx/10000);
}

int main(){
	while(cin>>p>>q>>r>>s>>t>>u){
		int lower,upper;
		int x=0;
		if(f(0)<0) {x=-1;goto print;}
		lower=1;
		upper=10000;
		if(f0(1)>0){x=-1;goto print;}
		while(upper-lower>2){
			x=lower+(upper-lower)/2;
			if(f(x)>0) lower=x;
			else upper=x+1;
		}
print:
		if(x<0){
			cout<<"No solution"<<endl;
			continue;
		}
		if(upper-lower==2){
			double fu=f(upper-1);
			double fl=f(lower);
			if(fu>0){++lower;}
			else if(fl<0){--upper;}
			else{
				if(f0(((double)(lower)+.5)/10000)<0)
					x=lower;
				else
					x=lower+1;
			}
		}
		if(upper-lower==1){
			if(f(lower)<0){
				//cout<<((double)(lower)-.5)/10000<<" "<<f0(((double)(lower)-.5)/10000)<<endl;
				if(f0(((double)(lower)-.5)/10000)<0)
					x=lower-1;
				else
					x=lower;
			}else{
				if(f0(((double)(lower)+.5)/10000)<0)
					x=lower;
				else
					x=lower+1;
			}
		}
		printf("%0.4f\n",(double)x/10000);
	}
	return 0;
}
