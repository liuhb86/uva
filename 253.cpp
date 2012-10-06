#include <iostream>
#include <cstring>
using namespace std;

char cube[20];
char cube2[20];
char cube3[20];
int main(){
	while(cin>>cube){
		strcpy( cube2,cube+6);
		bool equal=false;
		for(int i=0;i<6;i++){
			if(cube[0]!=cube2[i] || cube[5]!=cube2[5-i]) continue;
			cube3[0]=cube2[i];
			cube3[2]=cube2[(i+2)%6];
			cube3[4]=cube2[(i+4)%6];
			cube3[5]=cube2[5-i];
			cube3[3]=cube2[5-(i+2)%6];
			cube3[1]=cube2[5-(i+4)%6];
			for(int i=0;i<4;i++){
				equal=true;
				for(int i=1;i<=4;i++) if(cube3[i]!=cube[i]) {equal=false;break;}
				if(equal) goto break1;
				char temp=cube3[1];
				cube3[1]=cube3[2];
				cube3[2]=cube3[4];
				cube3[4]=cube3[3];
				cube3[3]=temp;
			}
		}
break1:
		if(equal) cout<<"TRUE"<<endl;
		else cout<<"FALSE"<<endl;
	}
	
	return 0;	
}
