#include <iostream>
using namespace std;
int x[100+10];
int y[100+10];
int main(){
	while(1){
		int n;
		int n2;
		cin>>n;
		if(n==0) break;
		n2=n*2;
		for(int i=0;i<n2;++i) cin>>x[i]>>y[i];
		int a,b;
		//bool success=false;
		for(a=-500;a<=500;++a){
			for(b=-500;b<=500;++b){
				int count_p=0,count_n=0;
				for(int k=0;k<n2;++k){
					int result=a*x[k]+b*y[k];
					if(result==0) goto continue1;
					if(result>0) {
						++count_p;
						if(count_p>n) goto continue1;
					}else{
					   	++count_n;
						if(count_n>n) goto continue1;
					}
				}
				if(count_p==n) {
					//success=true;
					goto break1;
				}
continue1:
				;
			}
		}
break1:
		cout<<a<<" "<<b<<endl;
	}	

	return 0;
}
