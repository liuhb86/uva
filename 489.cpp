#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	char letter[30];
	char buffer[100];
	int round;
	cin>>round;
	while(round!=-1){
		memset( letter,0,sizeof(letter));
		int chance=7;
		int remain=0;
		cin.getline(buffer,100);
		cin.getline(buffer,100);
		int len=strlen(buffer);
		if(buffer[len-1]=='\n') len--;
		for(int i=0;i<len;i++){
			if(letter[buffer[i]-'a']==0){
				letter[buffer[i]-'a']=2;
				remain++;
			}
		}
		cin.getline(buffer,100);
		len=strlen(buffer);
		if(buffer[len-1]=='\n') len--;
		for(int i=0;i<len && chance>0 && remain>0;i++){
			int c=buffer[i]-'a';
			if(letter[c]==0){
				letter[c]==1;
				chance--;	
			}else if(letter[c]==2){
				letter[c]=1;
				remain--;
			}
		}
		cout<<"Round "<<round<<endl;
		if(remain==0) cout<<"You win."<<endl;
		else if(chance==0) cout<<"You lose."<<endl;
		else cout<<"You chickened out."<<endl;
		
		cin>>round;
	}
	return 0;	
}
