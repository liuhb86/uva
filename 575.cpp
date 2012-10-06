#include <iostream>
using namespace std;

char buf[10000];
int main(){
	while(1){
		cin.getline(buf,sizeof (buf));
		int len=strlen(buf);
		int skew=0;
		unsigned int n=0;		
		for(int i=0;i<len;i++){
			int c=buf[i]-'0';
			n=2*n+c;
			skew+=c;
		}
		n=n*2-skew;
		if(n==0) break;
		cout<<n<<endl;
	}
	return 0;
}
