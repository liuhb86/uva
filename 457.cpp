#include <iostream>
#include <cstdlib>
using namespace std;

char popu[4]={' ','.','x','W'};
const int  NUMDISH=40;
const int NUMDNA=10;
const int NUMBUF=NUMDISH+10;

int line1[NUMBUF];
int line2[NUMBUF];
int DNA[NUMDNA]; 
int main(){
	int n;
	cin>>n;
	int firstcase=1;
	for(int k=0;k<n;k++){
		for(int i=0;i<NUMDNA;i++) cin>>DNA[i];
		memset(line1,0,sizeof (line1));
		memset(line2,0,sizeof(line2));
		line1[20]=1;
		if(firstcase) firstcase=0 ; else cout<<endl;
		int* cur=line1,*next=line2,*tmp;
		for(int i=0;i<50;i++){
			for(int j=1;j<=NUMDISH;j++){
				cout<<popu[cur[j]];
				next[j]=DNA[cur[j]+cur[j-1]+cur[j+1]];
			}
			cout<<endl;
			tmp=cur;cur=next;next=tmp;
		}
		
	}
	return 0;
}
