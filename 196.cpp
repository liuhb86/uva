#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;


int m,n;
int* spreadsheet;
char buffer[1000];
typedef vector<int> Vector;
typedef map<int,int> Map;
typedef Map::iterator It;

Map formulas;
Vector cellBuffer;

void calculate(It it){
	spreadsheet[it->first]=0;
	for(int i=it->second;cellBuffer[i]!=-1;++i){
		It it2=formulas.find(cellBuffer[i]);
		if(it2!=formulas.end()) calculate(it2);
		spreadsheet[it->first]+=spreadsheet[cellBuffer[i]];
	}
	formulas.erase(it);
}
int main(){
	int kase;
	cin>>kase;
	for(int i=0;i<kase;++i){
		cin>>n>>m;
		spreadsheet=new int[m*n];
		cellBuffer.clear();
		formulas.clear();
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				//cout<<i<<" "<<j<<endl;
				cin>>buffer;
				if(buffer[0]!='='){
					spreadsheet[i*n+j]=atoi(buffer);
					//cout<<"DATA:"<<i<<" "<<j<<" "<<spreadsheet[i*n+j]<<endl;
				}else{
					formulas.insert(make_pair(i*n+j,cellBuffer.size()));
					int x=0,y=0,accu=0,mul=1;
					int len=strlen(buffer);
					buffer[len]='+'; buffer[len+1]=0;
					char *p=buffer+1;
					//cout<<"FORMULA:"<<endl;
					while(*p!=0){
						if(*p=='+'){
							cellBuffer.push_back((x-1)*n+y+accu-1);
						   	x=0; y=0;accu=0;mul=1;
							//cout<<"+"<<cellBuffer.back()<<" "<<endl;
						}
						else if(isalpha(*p)){y=y*26+(*p)-'A';accu+=mul;mul*=26;}
						else if(isdigit(*p)){x=x*10+(*p)-'0';}
						++p;
						//cout<<x<<" "<<y<<" "<<accu<<" "<<mul<<" "<<static_cast<int>(*p)<<endl;
					}
					cellBuffer.push_back(-1);
				}
			}
		}
		while(!formulas.empty()){
			calculate(formulas.begin());
		}
		for(int i=0;i<m;++i){
			int first=true;
			for(int j=0;j<n;++j){
				if(first) first=false; else cout<<' ';
			   	cout<<spreadsheet[i*n+j];			
			}
			cout<<endl;
		}
		delete[] spreadsheet;
	}
	return 0;
}
