#include <iostream>
using namespace std;

const int MAX=300;
struct BigInt{
	int digit[300];
	int len;
	void clear(){memset(digit,0,sizeof(digit));len=1;}
	void operator+= (BigInt& a){
		len=(len>a.len)?len:a.len;
		int c=0;
		for(int i=0;i<len;i++){
			digit[i]+=a.digit[i]+c;
			if(digit[i]>=10) {digit[i]-=10;c=1;} else c=0;
		}
		if(c==1){digit[len++]=1;}
	}
	void print(){for(int i=len-1;i>=0;i--) cout<<digit[i];}
};

BigInt a,sum;
int main(){
	sum.clear();
	char buffer[200];
	while(true){
		cin.getline(buffer,200);
		int len=strlen(buffer);
		//assert(buffer[len-1]!='\n');
		if(len==1 && *buffer=='0') break;
		a.clear();
		int j=0,k=0;
		while(j<len && buffer[j]=='0') j++;
		for(int i=len-1;i>=j;i--){
			a.digit[k++]=buffer[i]-'0';
		}
		a.len=len-j;
		//sum.print();cout<<endl;
		//a.print();cout<<endl;
		sum+=a;
	}
	sum.print();
	cout<<endl;
	return 0;
}
