#include <iostream>
using namespace std;

const double  EPS=1e-6;
typedef int T;
T area2(T x1,T y1,T x2,T y2,T x3,T y3){
	return (y3-y1)*(x2-x1)-(y2-y1)*(x3-x1);
}


T x[40];
T y[40];
T area2b(int i,int j,int k){
	//cout<<"AERA("<<i<<","<<j<<","<<k<<")="<<area2(x[i],y[i],x[j],y[j],x[k],y[k])<<endl;
	return abs(area2(x[i],y[i],x[j],y[j],x[k],y[k]));
}
char C(int i){return 'A'+i;}
int main(){
	while(1){
		int n;
		cin>>n;
		if(n==0) break;
		char c;
		for(int i=0;i<n;i++) cin>>c>>x[i]>>y[i];
		//for(int i=0;i<n;i++) cout<<x[i]<<y[i]<<endl;
		T max=0;
		int mi=0,mj=0,mk=0;
		for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
		for(int k=j+1;k<n;k++){
			bool inside=false;
			T area=area2b(i,j,k);
			if(area<=max) continue;
			for(int m=0;m<n;m++){
				if(m==i || m==j ||m==k) continue;
				if(area2b(m,i,j)+area2b(m,j,k)+area2b(m,k,i)==area) {
					//cout<<m<<" in "<<i<<","<<j<<","<<k<<endl;
					inside=true;
					break;	
				} 
			}
			if(!inside){max=area;mi=i;mj=j;mk=k;}		
		}}}
		cout<<C(mi)<<C(mj)<<C(mk)<<endl;
	}
	return 0;	
}
