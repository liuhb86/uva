#include <iostream>
#include <vector>
using namespace std;

int* bsearch(int* begin, int* end, int val){
	if(end<=begin) return begin;
	int* mid=begin+(end-begin)/2;
	if (val<=*mid) return bsearch(begin,mid,val);
	else return bsearch(mid+1,end,val);	
}

int main(){
	vector<int> numbers;
	int num;
	while(cin>>num) numbers.push_back(num);
	int n=numbers.size();
	int* minval=new int[n+10];
	int* maxlen=new int[n+10];
	int len=0;
	for(int i=0;i<n;++i){
		int loc = bsearch(minval,minval+len,numbers[i])-minval;
		if(loc>=len) ++len;
		minval[loc]=numbers[i];
		maxlen[i]=loc+1;
	}
	cout<<len<<endl<<'-'<<endl;
	int *output=new int[n+10];
	int i=n-1;
	int j=len;
	while(j>0){
		if(maxlen[i]==j) {
			output[j]=numbers[i];	
			--j;
		}
		--i;
	}
	for(int i=1;i<=len;++i){
		cout<<output[i]<<endl;	
	}
	return 0;	
}
