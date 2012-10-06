#include <iostream>
using namespace std;

char name[]="AJAJAJAJAJASASASASASABABABABABAKAKAKAKAKATUTUTUTUTUCUCUCUCUCULULULULULUDUDUDUDUDUMUMEMEMEMEVEVEVEVEVENENENENENEWEWEWEWEWEFEFEFOFOFOXOXOXOXOXOGOGOGOGOGOPOPOPOPOPOYOYOYOYIYIHIHIHIHIHIQIQIQIQIQIZIZIZIZIZIRIRIRIRIR ";

int main(){
	int cases;
	cin>>cases;
	bool first=true;
	for(int i=1;i<=cases;i++){
		if(first) first=true;else cout<<endl;
		int n;
		cin>>n;
		char temp=name[n];
		name[n]=0;
		cout<<"Case "<<i<<": "<<name;
		name[n]=temp;	
	}	
	return 0;
}
