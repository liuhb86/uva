#include <iostream>
#include <cstring>
using namespace std;

char buf[10000];
int main(){
	int cases;
	cin>>cases;
	cin.getline(buf,10000);
	for(int k=1;k<=cases;k++){
		//if(k!=1) cout<<endl;
		int given=7;
		double P,U,I,value;
		char prefix;
		cin.getline(buf,10000);
		char* p=buf;
		for(int i=0;i<2;i++){
			p=strchr(p,'=');
			sscanf(p+1,"%lf%c",&value,&prefix);
			switch(prefix){
				case 'm':value/=1000;break;
				case 'k':value*=1000;break;
				case 'M':value*=1e6;break;
			}
			switch(*(p-1)){
				case 'P': given-=4; P=value;break;
				case 'U': given-=2; U=value;break;
				case 'I': given-=1; I=value;break;
			}
			p+=1;
		}
		char format[30]="Problem #%d\n%c=%.2lf%c\n";
		//cout<<given<<endl;
		switch(given){
			case 1:printf(format,k,'I',P/U,'A');break;
			case 2:printf(format,k,'U',P/I,'V');break;
			case 4:printf(format,k,'P',U*I,'W');break;
		}
		cout<<endl;
	}
}
