#include <iostream>
using namespace std;
const int MAXLEN=20+5;

char keywords[MAXLEN][MAXLEN];
char excuses[MAXLEN][10000];
char buf[MAXLEN];
int numKeywords[MAXLEN];
int k,e;

int count(char* word){
	for(int i=0;i<k;i++){
		if(strcmp(keywords[i],word)==0) return 1;	
	}
	return 0;
}
int main(){
	int i;
	int cases=0;
	while(cin>>k>>e){
		cases++;
		//cout<<"--"<<cases<<"--"<<endl;
		for(i=0;i<k;i++) cin>>keywords[i];
		//for(i=0;i<k;i++) cout<<keywords[i]<<endl;
		cin.getline(buf,MAXLEN);
		int max=-1;
		for(i=0;i<e;i++){
			int sum=0;
			bool processed=true;
			int k=0;
			int k2=0;
			char c;
			while(1){
				int r=scanf("%c",&c);
				if(r==EOF) c='\n';
				//cout<<c;
				excuses[i][k2++]=c;
				if(isalpha(c)) {buf[k++]=tolower(c);processed=false;}
				else{
					if(!processed){
						buf[k]=0;
						sum+=count(buf);
						//cout<<endl<<sum<<endl;
						processed=true;
						k=0;
					}
					if(c=='\n')break;
				}
			}
			//cout<<"sum="<<sum<<endl;
			excuses[i][k2]=0;
			numKeywords[i]=sum;
			if(sum>max) max=sum;
		}
		cout<<"Excuse Set #"<<cases<<endl;
		for( i=0;i<e;i++){
			if(numKeywords[i]==max) cout<<excuses[i];
		}
		cout<<endl;
	}
	return 0;
}
