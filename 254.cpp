#include <iostream>
#include <string>
using namespace std;

char remainder[100+10];
struct Int{
	char digits[100+10];
	int length;
	int div2(){
		if(length ==0) return 0;
		const int dec[2]={0,10};
		int higher = 0;
		for(char* p =digits+length-1; p>=digits; --p){
			int digit = (*p);
			digit += dec[higher];
			higher = digit & 1;
			*p = (digit>>1);
		}
		if (digits[length-1]==0) --length;
		return higher;
	}
	bool isZero(){return length==0;}

};


istream& operator>>(istream& is, Int& i){
	string s;
	is>>s;
	i.length = (int) s.size();
	for(int src=i.length-1, dest =0; src>=0; --src,++dest)
		i.digits[dest]=s[src]-'0';
	return is;
}

int main(){
	int pegs[3+3];
	while(true){
		int n;
		Int steps;
		cin>>n>>steps;
		if (n==0) break;
		pegs[0]=pegs[1]=pegs[2]=0;
		int finalPeg = (n%2==0) ? 2 : 1;
		int src =0, dest=finalPeg, immediate=3-src-dest;
		for(int i=0;i<n;++i) remainder[i] = steps.div2();
		for(int i=n-1;i>=0; --i){
			int r=remainder[i];
			if(r==1){
				pegs[dest]++;
				src = immediate;
				immediate = 3-src-dest;
			}else{
				pegs[src]++;
				dest = immediate;
				immediate = 3-src-dest;
			}
		}
		cout<<pegs[0]<<' '<<pegs[1]<<' '<<pegs[2]<<endl;
	}
	return 0;
}