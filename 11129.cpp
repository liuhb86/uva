#include <iostream>
using namespace std;

int result[10000+10];
void fill(int* begin, int *end){
	size_t length = end-begin;
	if (length ==1) {
		*begin=0;
		return;
	}
	int* middle= begin+ (length+1)/2;
	fill(begin,middle);
	fill(middle,end);
	for(int* p=begin;p!=middle;++p) (*p) *= 2;
	for(int* p=middle;p!=end;++p) *p = (*p) *2+1;
}

int main(){
	while(true){
		int n;
		cin>>n;
		if(n==0) break;
		fill(result,result+n);
		cout<<n<<":";
		for(int i=0;i<n;++i){
			cout<<' '<<result[i];
		}
		cout<<endl;
	}
	return 0;
}