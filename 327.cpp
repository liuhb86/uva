#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


const char SPACE[]="    ";
char buffer[200];
int loc,loc2,len;
bool appeared[30]={false};
//int increment[30]={0};
int value[30];

char nextToken(bool move,int location=loc){
	loc2=location;
	if(loc2>=len) return 0;
	while(buffer[loc2]==' ') ++loc2;
	if(move) loc=loc2+1;
	return buffer[loc2];
}

int main(){
	for(int i=0;i<26;++i) value[i]=i+1;
	while(cin.getline(buffer,sizeof(buffer))){
		cout<<"Expression: "<<buffer<<endl;
		int result=0;
		int lastOp=1;		//1-- add, 2-- substract
		int selfInc=0;
		loc=0;len=strlen(buffer);
		bool waitForVar=true;
		while(true){
			char c=nextToken(true);
			if(c==0) break;
			else if(c=='+'){
				if(waitForVar){
					//prefix self increment operator
					selfInc=1;
					nextToken(true);
				}else{
					lastOp=1;
					waitForVar=true;
				}
			}else if(c=='-'){
				if(waitForVar){
					selfInc=-1;
					nextToken(true);
				}else{
					lastOp=-1;
					waitForVar=true;
				}
			}else if(c>='a' && c<='z'){
				waitForVar=false;
				int index=c-'a';
				appeared[index]=true;
				value[index]+=selfInc;
				result+=lastOp*value[index];
				//Look for postfix
				if(selfInc==0){
					char c1=nextToken(false);
					char c2=nextToken(false,loc2+1);
					char c3=nextToken(false,loc2+1);
					if((c1=='+' ||c1=='-') && 
					   c2==c1 &&
					   (c3=='+' || c3=='-' || c3==0)){
							value[index]+=(c1=='+')?1:-1;
							nextToken(true);
							nextToken(true);
					}
				}
				selfInc=0;	
			}
		}
		cout<<SPACE<<"value = "<<result<<endl;
		for(int i=0;i<26;++i){
			if(appeared[i]) cout<<SPACE<<static_cast<char>('a'+i)<<" = "<<value[i]<<endl;	
			appeared[i]=false;
			value[i]=i+1;
		}
	}
	return 0;
}
