#include <iostream>
#include <vector>
using namespace std;

char buf[100];
vector<char>output;
int main(){
	cin.getline(buf,100);
	while(1){
		cin.getline(buf,100);
		if(*buf=='_')break;
		char c=0;
		if(buf[2]=='o') c+=1<<6;
		if(buf[3]=='o') c+=1<<5;	
		if(buf[4]=='o') c+=1<<4;
		if(buf[5]=='o') c+=1<<3;
		if(buf[7]=='o') c+=1<<2;
		if(buf[8]=='o') c+=1<<1;
		if(buf[9]=='o') c+=1;
		output.push_back(c);
	}
	int len=output.size();
	for( int i=0;i<len;i++) cout<<output[i];
	return 0;	
}
