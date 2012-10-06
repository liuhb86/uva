#include <iostream>
#include <cstring>
#include<cstdlib>
using namespace std;
const int MAX=600;

struct BigInt;
ostream& operator<<(ostream& os,const BigInt& a);

struct BigInt{
	int digit[MAX];
	int len;
	void clear(){memset(digit,0,sizeof(digit));len=1;}

	BigInt& operator= (const char* s){
		clear();
		int slen=strlen(s);
		int j; for(j=0;j<slen;j++) if(s[j]!='0') break;
		len=slen-j;
		for (int i=j,k=len-1;i<slen;i++,k--) digit[k]=s[i]-'0';
		return *this;
	}
	void shift(const BigInt& b,int s){clear();memcpy(digit+s,b.digit,sizeof(int)*b.len);len=b.len+s;}
	BigInt& operator+= (const BigInt&b){
		int mlen=(len>b.len)?len:b.len;
		int c=0;
		//cout<<mlen;
		for(int i=0;i<mlen;i++){
			int r=c;
			if(i<len)r+=digit[i];
			if(i<b.len)r+=b.digit[i];
			//cout<<" "<<r;
			digit[i]=r%10;
			c=r/10;
		}
		len=mlen;
		if(c) digit[len++]=1;
		return *this;
	}
	void mul(int b){
		int c=0;
		for(int i=0;i<len;i++){
			int r=c+digit[i]*b;
			digit[i]=r%10;
			c=r/10;
		}
		if(c) digit[len++]=c;
	}
	BigInt& operator *=(const BigInt &b){

		BigInt a;
		a.shift(*this,0);
		//cout<<a<<endl<<b<<endl<<"------"<<endl;
		BigInt c;	
		clear();
		for(int i=0;i<b.len;i++){
				c.shift(a,i);
				//cout<<c<<"   |";
				c.mul(b.digit[i]);
				//cout<<c<<endl;
				(*this)+=c;
		}
		//cout<<*this<<endl;
		return *this;
	}
};

ostream& operator<<(ostream& os,const BigInt& a){for(int i=a.len-1;i>=0;i--) os<<a.digit[i];return os;}

char buf[MAX];
BigInt a,b;
int main(){
	while(true){
		cin>>buf;
		if(cin.eof()) break;
		a=buf;
		cin>>buf;
		b=buf;
		a*=b;
		cout<<a<<endl;
	}
	return 0;	
}	
