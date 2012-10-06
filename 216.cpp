#include <iostream>
#include <algorithm>
#include <limits>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX_COMPUTER=8+2;
const float EXTRA_LEN=16.0;

int main(){
	int x[MAX_COMPUTER];
	int y[MAX_COMPUTER];
	int permu[MAX_COMPUTER];
	int min_permu[MAX_COMPUTER];
	float min_len;
	int kase=0;
	cout.setf(ios::fixed);
	cout.precision(2);
	while(1){
		int n;
		cin>>n;
		if(n==0) break;
		++kase;
		for(int i=0;i<n;++i){
			cin>>x[i]>>y[i];
			permu[i]=i;
		}
		min_len=numeric_limits<float>::infinity();
		while(1){
			float len=0.0;
			for(int i=0;i<n-1;++i){ 
				int &x1=x[permu[i]], &y1=y[permu[i]], &x2=x[permu[i+1]], &y2=y[permu[i+1]];
				len+=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
			}
			if(len<min_len){
				min_len=len;
				memcpy(min_permu,permu,n*sizeof(int));
			}
			if(!next_permutation(permu,permu+n)) break;
		}
		cout<<"**********************************************************"<<endl<<
			"Network #"<<kase<<endl;	
		for(int i=0;i<n-1;++i){
			int &x1=x[min_permu[i]], &y1=y[min_permu[i]], &x2=x[min_permu[i+1]], &y2=y[min_permu[i+1]];
			cout<<"Cable requirement to connect ("<<x1<<","<<y1<<") to ("<<x2<<","<<y2<<
				") is "<<sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))+EXTRA_LEN<<" feet."<<endl;
		}
		cout<<"Number of feet of cable required is "<<min_len+(n-1)*EXTRA_LEN<<"."<<endl;

	}
	return 0;
}
