#include <iostream>
#include <set>
using namespace std;

int symbol[100+10];
int mask;
int P,N;

bool test(int start,int n_choose){
	if(n_choose>0){
		for(int i=start;i<=P-n_choose;++i){
			mask+=1<<i;
			if(test(i+1,n_choose-1))
				return true;
			mask-=1<<i;
		}
		return false;
	}else{
		//cout<<mask<<endl;
		set<int> seen;
		for(int i=0;i<N;++i){
			int real=symbol[i] & mask;
			//if(mask==124) cout<<i<<" "<<symbol[i]<<" "<<real<<endl;
			bool inserted=seen.insert(real).second;
			if(!inserted) return false;
		}
		return true;
	}
}

int main(){
	int kase;
	cin>>kase;
	for(int i=0;i<kase;++i){
		cin>>P>>N;
		for(int j=0;j<N;++j){
			symbol[j]=0;
			//cout<<"*****"<<j<<endl;
			for(int k=0;k<P;++k){
				int bit;
				cin>>bit;
				symbol[j]=symbol[j]*2+bit;
				//cout<<bit<<" "<<symbol[j]<<endl;
			}
		}
		bool success=false;
		int mmin;
		for(mmin=1;mmin<P;++mmin){
			//cout<<"*"<<mmin<<endl;
			mask=0;
			success=test(0,mmin);
			if(success) break;
		}
		if(!success) mmin=P;
		cout<<mmin<<endl;
	}
	return 0;
}
