#include <iostream>
using namespace std;

//Rtn value: 
//	total weight if balanced
//	negative if not
int checkBalance(){
	int wl,wr,dl,dr;
	cin>>wl>>dl>>wr>>dr;
	if(wl==0){
		wl=checkBalance();
		if(wl==0) return -1;
	}
	if(wr==0){
		wr=checkBalance();
		if(wr==0) return -1;
	}
	if(wl*dl==wr*dr) return wl+wr;
	else return -1;
}
//Read to next case
void cleanUp(){
	string s;
	getline(cin,s);
	do{
		getline(cin,s);
	}while(s.size()>0);

}

int main(){
	int kase;
	cin>>kase;
	bool firstCase=true;
	for(int i=0;i<kase;++i){
		if(firstCase) firstCase=false; else cout<<endl;
		if(checkBalance()<0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		if(i<kase-1) cleanUp();
	}
	return 0;
}
