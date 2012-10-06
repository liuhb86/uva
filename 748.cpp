#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int MAXLEN=200;
struct BigInt{
	int digit[MAXLEN];
	int len;
	void clear(){memset(digit,0,sizeof(digit));len=1;}
	void operator=(char* const s){
		clear();
		len=strlen(s);
		for(int i=len-1,k=0;i>=0;i--,k++) digit[k]=s[i]-'0';
	}
	void operator+=(BigInt& b){
		int mlen=(len>b.len)?len:b.len;
		int c=0;
		for(int i=0;i<mlen;i++){
				int r=c;
				if(i<len) r+=digit[i];
				if(i<b.len) r+=b.digit[i];
				digit[i]=r%10;
				c=r/10;
		}
		len=mlen;
		if(c) digit[len++]=c;
		//print();cout<<endl;
	}
	void shift(BigInt&b, int k){clear();memcpy(digit+k,b.digit,sizeof(int)*b.len);len=b.len+k;}
	void mul(int k){
		int c=0;
		for(int i=0;i<len;i++){
			int r=digit[i]*k+c;
			digit[i]=r%10;
			c=r/10;
		}
		if(c) digit[len++]=c;
	}
	void operator*=(BigInt& b){
		BigInt a,c;
		a.shift(*this,0);
		clear();
		for(int i=0;i<b.len;i++){
				c.shift(a,i);
				c.mul(b.digit[i]);
				(*this)+=c;
		}
	}
	void print(int point=0){
		for(int i=len-1;i>=point;i--) cout<<digit[i];
		if(point==0) return;
		cout<<'.';
		if(len<point) {for(int i=len;i<point;i++) cout<<'0';point=len;}
		for(int i=point-1;i>=0;i--) cout<<digit[i];
	}
	int parse(char* const s){
		//cout<<s<<endl;
		char* p_begin,*p_end;
		for(p_end=s+strlen(s);p_end>s;p_end--)if (*(p_end-1)!='0') break;
		//cout<<(p_end-s)<<" "<<(int)*p_end<<p_end;
		*p_end=0;
		//for(int i=0;i<20;i++) cout<<(int)s[i]<<" ";
		//cout<<s<<"[";
		int point=0;
		for(p_begin=s;p_begin!=p_end;p_begin++) if(*p_begin=='.') break;
		if(p_begin==p_end) point=0; 
		else{
			 point=p_end-p_begin-1;
			 for(int i=0;i<=point;i++) p_begin[i]=p_begin[i+1];
			 p_end--;*p_end=0;
		}
		//cout<<point<<"]"<<s<<"#";
		for(p_begin=s;p_begin!=p_end;p_begin++) if(*p_begin!='0') break;
		//if(p_begin==p_end) cout<<"0"; else	cout<<p_begin;
		if(p_begin==p_end) *this="0"; else	*this=p_begin;
		return point;
	}
};

int main(){
	//goto test;
	char buf[100];
	int n;
	BigInt r;
	BigInt result;
	while(cin>>buf>>n){
		//cout<<buf<<" "<<n<<endl;
		int f=r.parse(buf)*n;
		//r.print(); cout<<endl;
		char one[10]="1";
		result.parse(one);
		//result.print(); cout<<endl;
		for(int i=0;i<n;i++){
				result*=r;
				//result.print(); cout<<endl;
		}
		result.print(f);
		cout<<endl;
		cin.getline(buf,sizeof(buf));
	}
	
	//test

/*test:
	BigInt a;
	char temp[100];
	char s[9][20]={"0","00.0","0.618",".618","01.25","1.3450",".000","3.14","0045.02300"};
	for(int i=0;i<9;i++){
		strcpy(temp,s[i]);
		cout<<temp<<"=";
		a.parse(temp);
		a.print();
		cout<<endl;
	}
	
	a.parse(strcpy(temp,"95.123"));
	a.print(2);
	cout<<endl;

	BigInt b;
	b="18";
	b.print();
	cout<<endl;
	a*=b;
	a.print(); cout<<endl;
	a.print(3);cout<<endl;
	a.print(20);cout<<endl;*/
	//end test 
	
	
	return 0;	
}
