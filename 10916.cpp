#include <iostream>
//#include <cmath>
using namespace std;
/*
//Generator
int main(){
	int k=4;
	int s=1;
	double d1=0.0,d2;
	while(k<(1<<30)){
		d2=k*log(2);
		while(1){
			if(d1>=d2) {
				//cout<<k<<" "<<s-2<<endl;
				cout<<s-2<<",";
				k*=2;
				break;
			}
			else d1+=log(s++);
		}
	}
}*/


int factstone[40]={3,5,8,12,20,34,57,98,170,300,536,966,
1754,3210,5910,10944,20366,38064,71421,134480,254016,481176,
913846,1739680,3318996,6344666,12150874,23310032
};

int main(){
	while(1){
		int n;
		cin>>n;
		if (n==0) break;
		n=(n-1960)/10;
		cout<<factstone[n]<<endl;	
	}
	return 0;	
}

