#include <iostream>
#include <cstring>
using namespace std;

const int MAX=500+10;
int num[MAX];
int buffer[MAX];
int tmp[MAX];

/*int calcReverse(int* begin, int* end){
	size_t length = end - begin;
	if (length <=1) return 0;
	int* mid = begin+length/2;
	int ro = calcReverse(begin, mid) + calcReverse(mid, end);
	int nLeft = (int) (mid - begin);
	int *p1, *p2, *dest;
	for(p1=begin, p2=mid, dest = tmp; p1!=mid && p2!=end; ++dest){
		if (*p1<=*p2){
			*dest = *(p1++);
			nLeft--;
		} else {
			*dest = *(p2++);
			ro+=nLeft;
		}
	}
	for (;p1!=mid;++dest, ++p1) *dest = *p1;
	for (;p2!=end;++dest, ++p2) *dest = *p2;
	memcpy(begin, tmp, length*sizeof(int));

	return ro;
}*/

int calcSwap(int* begin, int* end){
	int i=1;
	int swap = 0;
	int *p = begin;
	for (p=begin; p!=end; ++p, ++i) {
		while (*p!=i){
			++swap;
			int t=*p;
			*p = begin[t-1];
			begin[t-1] =t;
		}
	}
	return swap;
}
int main (){
	while(true){
		int n;
		cin>>n;
		if (n==0) break;
		for(int i=0;i<n;++i) cin>>num[i];
		int min = (n-1)*n/2;

		int *end = num+n, *destEnd = buffer+n;
		for (int i=0;i<n; ++i){
			for(int *src=num, *dest=buffer+i; src!=end; ++src){
				*dest = *src;
				++dest;
				if(dest ==destEnd) dest = buffer;
			}
			int ron = calcSwap(buffer, buffer + n);
			if (ron<min) min=ron;
			for(int *src=num, *dest=buffer+i; src!=end; ++src){
				*dest = n - (*src) +1;
				++dest;
				if(dest ==destEnd) dest = buffer;
			}
			ron = calcSwap(buffer, buffer + n);
			if (ron<min) min=ron;
			
		}
		cout<<min<<endl;

	}
	return 0;
}