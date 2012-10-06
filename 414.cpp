#include <iostream>
#include <cstdio>
using namespace std;

const int COL=25+10;
int main(){
	char line[COL];
	int n;
	cin>>n;
	while(n){
		cin.getline(line,COL);
		int total=0;
		int min=COL;
		for (int i=0;i<n;i++){
			cin.getline(line,COL);
			char* p=line;
			int subtotal=0;
			while (*p=='X') p++;
			while (*p==' ') {subtotal++;p++;}
			total+=subtotal;
			if(subtotal<min)min=subtotal;
		}
		cout<<(total-n*min)<<endl;
		cin>>n;
		//cout<<n<<" ";
	}
	return 0;
}