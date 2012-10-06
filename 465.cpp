#include <iostream>
#include <cstring>
#include <climits>
#include <cctype>
#include <sstream>
using namespace std;
char buffer[100000];
char str1[10000];
char str2[10000];

const int MAX_INT_LEN=10;

double toFloat(char* s){
	double f;
	int len =strlen(s);
	int i;
	for(i=0;i<len;i++) if(s[i]!='0') break;
	len-=i;
	if(len>MAX_INT_LEN) return -1.0;
	sscanf(s,"%lf",&f);
	//cout<<f<<endl;
	if(f>INT_MAX) return -1.0; else return f;
}

char resbig[]="result too big";

int main(){
	while(true){
		char c;
		double f1,f2;
		
		int k=0;
		cin.getline(buffer,sizeof(buffer));
		if(cin.eof()) break;
		istringstream iss(buffer);
		while(true){
			iss>>c;
			if(iss.eof()) return 0;
			if(isdigit(c)) str1[k++]=c;	else break;
		}
		str1[k]=0;
		iss>>str2;
		
		cout<<buffer<<endl;
		//cout<<str1<<","<<c<<","<<str2<<endl;
		f1=toFloat(str1);
		if(f1<0) cout<<"first number too big"<<endl;
		f2=toFloat(str2);
		if(f2<0) cout<<"second number too big"<<endl;
		if(f1<0 && (c!='*' || f2!=0.0)) {cout<<resbig<<endl;continue;}
		if(f2<0 && (c!='*' || f1!=0.0)) {cout<<resbig<<endl;continue;}
		if(c=='+') f1+=f2; else f1*=f2;
		//cout<<f1<<" "<<INT_MAX<<endl;
		if(f1>INT_MAX) cout<<resbig<<endl;
	}
	return 0;
}
