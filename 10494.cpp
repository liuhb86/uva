#include <iostream>
#include <cstring>
using namespace std;

char p[10000];
int q[10000];
int main(){
	int n;
	char c;
	long long r;
	while(cin>>p>>c>>n){
			int len=strlen(p);
			r=0;
			for(int i=0;i<len;i++){
					r=10*r+p[i]-'0';
					int qq=r/n;
					int rr=r%n;
					q[i]=qq;
					r=rr;	
			}
			if(c=='%') cout<<r<<endl;
			else{
				int i;
				for(i=0;i<len-1;i++) if(q[i]!=0) break;
				for(int j=i;j<len;j++) cout<<q[j];
				cout<<endl;	
			}
	}
	return 0;	
}
