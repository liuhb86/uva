#include <iostream>
using namespace std;
const int BUFLEN=100;

int main(){
	char s[10][BUFLEN];
	char delim[10]="<><>\n.";
	int n;
	cin>>n;
	cin.getline(s[6],BUFLEN);
	for(int j=0;j<n;j++){
		for(int i=0;i<6;i++){
			cin.getline(s[i],BUFLEN,delim[i]);
		}
		cout<<s[0]<<s[1]<<s[2]<<s[3]<<s[4]<<endl;
		cout<<s[5]<<s[3]<<s[2]<<s[1]<<s[4]<<endl;
		cin.getline(s[6],BUFLEN);
	}
	return 0;
}
