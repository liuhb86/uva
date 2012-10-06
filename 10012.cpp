#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_CIRCLES=8+2;
double circles[MAX_CIRCLES];
int n;
double position[MAX_CIRCLES];

int main(){
	cout.setf(ios::fixed);
	cout.precision(3);
	int kase;
	cin>>kase;
	for(int i=0;i<kase;++i){
		cin>>n;
		for(int j=0;j<n;++j) cin>>circles[j];
		sort(circles,circles+n);
		double height=1.0; //circles[n-1];
		double minWidth=circles[n-1]*n*2;
		while(1){
			for(int i=0;i<n;++i){
				double maxPos=circles[i];
				for(int j=i-1;j>=0;--j){
					double h1=circles[i]+circles[j];
					double h2=fabs(circles[i]-circles[j]);
					double pos=position[j]+sqrt(h1*h1-h2*h2);
					if(pos>maxPos) maxPos=pos;
					if(circles[i]<circles[j]) break;
				}
				position[i]=maxPos;
				//cout<<i<<" "<<circles[i]<<" "<<position[i]<<endl;
			}
			//for(int i=0;i<n;++i) cout<<position[i]<<" "; cout<<endl;
			double maxWidth=0.0;
			for(int j=0;j<n;++j){
				double width=position[j]+circles[j];
				if(width>maxWidth) maxWidth=width;
			}
			if(maxWidth<minWidth) minWidth=maxWidth;
			//cout<<minWidth<<endl;
			if(!next_permutation(circles,circles+n)) break;
		}
		cout<<height*minWidth<<endl;
	}
	return 0;
}
