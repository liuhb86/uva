#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

typedef vector<int> Vec;

int bin[10+5];
int main(){
	Vec x,y,z;
	int ix,iy,iz;
	while(true){
		cin>>ix>>iy>>iz;
		if(ix==0 && iy==0 & iz==0) break;
		x.push_back(ix);y.push_back(iy);z.push_back(iz);
	}
	memset(bin,0,sizeof(bin));
	for(size_t i=0;i<x.size();++i){
		int minD=300*300*300;
		for(size_t j=0;j<x.size();++j){
				if(j==i) continue;
				int distance=	 (x[i]-x[j])*(x[i]-x[j]) +
								(y[i]-y[j])*(y[i]-y[j])+
								(z[i]-z[j])*(z[i]-z[j]) ;
				if( distance<minD) minD=distance;
		}
		int distance= static_cast<int> (sqrt(minD));
		if(distance<10) ++bin[distance];
	}
	for(int i=0;i<10;i++) cout<<setw(4)<<bin[i];
	cout<<endl;
	return 0;	
}
