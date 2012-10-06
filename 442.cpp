#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

struct Matrix{
	int m;
	int n;
	bool defined;
	Matrix():defined(false){}	
};

typedef deque<Matrix> Stack;
Stack stack_Matrix;
Matrix matInfo[30];
char buffer[2000];

int main(){
	int num;
	cin>>num;
	for(int i=0;i<num;++i){
		char c;
		int m,n;
		cin>>c>>m>>n;
		int index=c-'A';
		matInfo[index].m=m;
		matInfo[index].n=n;
		matInfo[index].defined=true;
	}
	cin.getline(buffer,sizeof(buffer));
	while(cin.getline(buffer,sizeof(buffer))){
		stack_Matrix.clear();
		bool ill=false;
		int num_multiply=0;
		int len=strlen(buffer);
		for(int i=0;i<len;i++){
			if(buffer[i]=='(') continue;
			else if(buffer[i]==')'){
				Matrix b=stack_Matrix.back();
				stack_Matrix.pop_back();
				Matrix& a=stack_Matrix.back();
				if(a.n!=b.m) {ill=true;break;}
				num_multiply+=a.m*a.n*b.n;
				a.n=b.n;
			}else{
				int index=buffer[i]-'A';
				if(matInfo[index].defined==false){ill=true;break;}
				stack_Matrix.push_back(matInfo[index]);
			}

		}
		if(ill) cout<<"error"<<endl;
		else cout<<num_multiply<<endl;
	}

	return 0;
}
