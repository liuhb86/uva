#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef vector<string>::iterator It;

bool isPred(It& it1,It& it2){
	int len1,len2,temp1;
	string *s1,*s2,*temp2;
	s1=&(*it1);s2=&(*it2);
	//cout<<(*s1)<<" *** "<<(*s2)<<" *** ";
	len1=s1->length();len2=s2->length();
	if(len1>len2){temp1=len1;len1=len2;len2=temp1;temp2=s1;s1=s2;s2=temp2;}
	for(int i=0;i<len1;i++){
		if ((*s1)[i]!=(*s2)[i]) return false;
	}
	return true;
}

int main(){
	int n=1;
	vector<string> codes;
	string s;
	while(cin>>s){
		if(s[0]=='9'){
			It end=codes.end();
			bool decodable=true;
			for(It i=codes.begin();i!=end;i++){
				for(It j=i+1;j!=end;j++){
					//bool result=isPred(i,j);
					//cout<<result<<endl;
					//if(result) {decodable=false;goto break1;}
					if(isPred(i,j)) {decodable=false;goto break1;}
				}
			}
break1:
			if(decodable) cout<<"Set "<<n<<" is immediately decodable"<<endl;
			else cout<<"Set "<<n<<" is not immediately decodable"<<endl;
			
			//clean up
			codes.clear();
			n++;
		}
		else codes.push_back(s);
	}
	return 0;	
}
