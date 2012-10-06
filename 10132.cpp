#include <iostream>
#include <set>
#include <cstring>
using namespace std;

char* strings[300][2];
set<int> lengths;
const int DEBUG=0;


bool test(char* str,int lens){
	bool result=true;
	int limit=lens/2;
	//cout<<str<<endl;
	for(set<int>::reverse_iterator it=lengths.rbegin();it!=lengths.rend();++it){
		int len=*it;
		if(len<=limit) break;
		for(int i=0;i<1;++i){
			//cout<<strings[len][i]<<endl;
			if(strings[len][i][0]==0) continue;
			char temp=str[len];
			str[len]=0;
			if(strcmp(str,strings[len][i])==0){
				//cout<<"A"<<endl;
				str[len]=temp;
				bool ok=false;
				for(int j=0;j<2;++j){
					//cout<<strings[lens-len][j]<<endl;
					if(strcmp(str+len,strings[lens-len][j])==0) {/*cout<<"B"<<endl;*/ok=true;break;}
				}
				if(ok) continue;
			}
			str[len]=temp;
			if(strcmp(str+(lens-len),strings[len][i])==0){
				temp=str[lens-len];
				str[lens-len]=0;
				bool ok=false;
				for(int j=0;j<2;++j){
					if(strcmp(str,strings[lens-len][j])==0) {ok=true;break;}
				}
				str[lens-len]=temp;
				if(ok) continue;
			}
			result=false;
			break;
		}	
	}
	return result;
}


int main(){
	for(int i=1;i<300;++i){
		strings[i][0]=new char[i+1];
		strings[i][1]=new char[i+1];
	}
	int kase;
	cin>>kase;
	char buf[300];
	cin.getline(buf,300);
	cin.getline(buf,300);
	for(int i=0;i<kase;++i){
		for(set<int>::iterator it=lengths.begin();it!=lengths.end();++it){
			strings[*it][0][0]=strings[*it][1][0]=0;
		}
		lengths.clear();
		int total_length=0;
		int total_frag=0;
		while(1){
			cin.getline(buf,300);
			if(*buf==0) break;
			if(cin.eof()) break;
			int len=strlen(buf);
			if(DEBUG) cout<<len<<" "<<buf<<endl;
			if(strings[len][0][0]==0)
				strcpy(strings[len][0],buf);
			else if (strcmp(strings[len][0],buf)!=0)
				strcpy(strings[len][1],buf);
			
			lengths.insert(len);
			++total_frag;
			total_length+=len;
		}
		
		int len=total_length/(total_frag/2);
		//int half_len=len/2;
		int maxlen=*(lengths.rbegin());
		int minlen=len-maxlen;
		if(DEBUG) cout<<len<<" "<<maxlen<<" "<<minlen<<endl;
		if(strings[maxlen][1][0]==0){
			if(DEBUG) cout<<"CASE 1";
			if(strings[minlen][1][0]!=0){
				if(DEBUG) cout<<"A"<<endl;
				cout<<strings[maxlen][0]<<strings[minlen][0]<<endl;
				goto break1;
			}
			strcpy(buf,strings[maxlen][0]);
			strcat(buf,strings[minlen][0]);
			if(test(buf,len)){
				if (DEBUG) cout<<"B"<<endl;
				cout<<buf<<endl;
				goto break1;
			}
			if (DEBUG) cout<<"C"<<endl;
			cout<<strings[minlen][0]<<strings[maxlen][0]<<endl;
			goto break1;
		}else{
			if (DEBUG) cout<<"CASE 2";
			if(strings[minlen][1][0]==0){
				if(DEBUG) cout<<"A"<<endl;
				cout<<strings[maxlen][0]<<strings[minlen][0]<<endl;
				goto break1;
			}
			char temp1[300];
			char temp2[300];
			strcpy(temp1,strings[maxlen][0]);
			temp1[minlen]=0;
			if(strcmp(temp1,strings[minlen][0])==0)
				strcpy(temp2,strings[minlen][1]);
			else
				strcpy(temp2,strings[minlen][0]);
			temp1[minlen]=strings[maxlen][0][minlen];

			strcpy(buf,temp1);
			strcat(buf,temp2);
			if(test(buf,len)){
				if(DEBUG) cout<<"B"<<endl;
				cout<<buf<<endl;
				goto break1;
			}
			if(DEBUG) cout<<"C"<<endl;
			cout<<temp2<<temp1<<endl;
			goto break1;

		}
break1:
		if(i!=kase-1) cout<<endl;
	}
	
	return 0;
}
