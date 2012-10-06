#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAX_SIZE=10;
int matrix[MAX_SIZE][MAX_SIZE];
int length[MAX_SIZE];
int sIndex[26];
char revIndex[MAX_SIZE];
int order[MAX_SIZE];
int minOrder[MAX_SIZE];
int loc[MAX_SIZE];
char buffer[500];
int main(){
	while(1){
		cin.getline(buffer,sizeof(buffer));
		if(*buffer=='#') break;
		for(int i=0;i<26;++i) sIndex[i]=0;
		char* p=buffer;
		while(*p!=0){
			if(*p>='A' && *p<='Z') sIndex[*p-'A']=1;
			++p;
		}
		int numNode=0;
		for(int i=0;i<26;++i) if(sIndex[i]) {sIndex[i]=numNode; revIndex[numNode]='A'+i; ++numNode;}
		for(int i=0;i<numNode;++i) length[i]=0;
		p=buffer;
		while(1){
			int from=sIndex[*p-'A'];
			p+=2;
			while(1){
				if(*p==';') {++p;break;}
				if(*p==0) goto break1;
				int to=sIndex[*p-'A'];
				matrix[from][length[from]++]=to;
				matrix[to][length[to]++]=from;
				++p;
			}
		}
break1:
		//for(int i=0;i<numNode;++i) cout<<length[i]<<' '; cout<<endl;
		for(int i=0;i<numNode;++i) order[i]=i;
		bool suc;
		int minBandwidth=numNode+1;
		do{
			for(int i=0;i<numNode;++i) loc[order[i]]=i;
			int bandwidth=0;
			for(int i=0;i<numNode;++i){
				for(int j=0;j<length[i];++j){
					int distance=abs(loc[i]-loc[matrix[i][j]]);
					//cout<<revIndex[i]<<revIndex[matrix[i][j]]<<distance<<endl;
					if(distance>bandwidth) bandwidth=distance;
				}
			}
			if(bandwidth<minBandwidth){
				minBandwidth=bandwidth;
				for(int i=0;i<numNode;++i) minOrder[i]=order[i];
			}
			suc=next_permutation(order,order+numNode);
		}while(suc);
		for(int i=0;i<numNode;++i){
			cout<<revIndex[minOrder[i]]<<' ';
		}
		cout<<"-> "<<minBandwidth<<endl;
	}	
	return 0;
}
