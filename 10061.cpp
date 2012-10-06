#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/*
//prime generator
int p[850];
int main(){
	memset(p,0,sizeof(p));
	for(int i=2;i<=800;i++){
		if(p[i]==1) continue;
		cout<<i<<",";
		for(int j=i+i;j<=800;j+=i) p[j]=1; 
	}
}*/

const int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797};
const int numPrime=sizeof(prime)/sizeof(int);
int pk[numPrime+10];
int bpk[numPrime+10];
int p[numPrime+10];
int defactor(int b){
	//b must >1.
	int num=0;
	for( int i=0;i<numPrime;i++){
		if (prime[i]>b) break;
		if(b%prime[i]==0){
			p[num]=prime[i]; bpk[num]=0;
			while(b%prime[i]==0) {b/=prime[i];bpk[num]++;}
			num++;	
		}
	}
	return num;	
}
int main(){
	int n,b;
	while(cin>>n>>b){
		if(n<2) {cout<<"0 1"<<endl; continue;}
		int nump=defactor(b);
		//for(int i=0;i<nump;i++) cout<<p[i]<<"^"<<bpk[i]<<" "; cout<<endl;
		for(int i=0;i<nump;i++){
			pk[i]=0;
			for(int j=p[i];j<=n;j*=p[i]) pk[i]+=n/j;
		}
		//for(int i=0;i<nump;i++) cout<<p[i]<<"^"<<pk[i]<<" "; cout<<endl;
		int min=INT_MAX;
		for(int i=0;i<nump;i++){
			int k=pk[i]/bpk[i];
			if(k<min) min=k;	
		}
		//min is the # of tailing zero.
		
		double sum=0.0;
		for(int i=2;i<=n;i++) sum+=log(i);
		int len=ceil(sum/log(b)+1e-3);
		
		cout<<min<<" "<<len<<endl;
		
	}
	return 0;
}
