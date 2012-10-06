#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;
const int MAXLEN=50+10;
char grid[MAXLEN][MAXLEN];
int m,n ;


void find(char* str){
	int len=strlen(str);
	for(int i=0;i<len;i++) str[i]=toupper(str[i]);
	//cout<<str<<endl;	 
	for(int i=1;i<=m;i++){
	 	for(int j=1;j<=n;j++){
			//cout<<"<"<<i<<","<<j<<">"<<endl;
			for( int ver=-1;ver<=1;ver++){
	 			for(int hoz=-1; hoz<=1;hoz++){
					if(ver==0 && hoz==0) continue;
					int suc=1;
					int x=i,y=j;
					//cout<<"INC:"<<ver<<" "<<hoz<<endl;
					for(int k=0;k<len;k++){
						//cout<<k<<":"<<grid[x][y]<<" "<<str[k]<<" "<<suc<<endl;
						if(grid[x][y]<'A' || grid[x][y]!=str[k]){suc=0;break;} 
						x+=ver;y+=hoz;	
					}
					if(suc){cout<<i<<" "<<j<<endl;return;} //else cout<<"fail"<<endl;
				}
			}
		}
	}
}

int main(){
	char buf[30];
	int cases;
	cin>>cases;
	memset(grid,0,sizeof(grid));
	int firstcase=1;
	for (int i=0;i<cases;i++){
		if(firstcase) firstcase=0; else cout<<endl;
		cin>>m>>n;
		cin.getline(buf,30);
		for(int j=1;j<=m;j++){
				for(int k=1;k<=n;k++){
						char c;
						cin>>c;
						grid[j][k]=toupper(c);
				}
				cin.getline(buf,30);
		}
		//for(int j=1;j<=m;j++){for(int k=1;k<=n;k++) cout<<grid[j][k];cout<<endl;}
		int k;
		cin>>k;
		char str[100];
		for(int p=0;p<k;p++){
				cin>>str;
				find(str);
        }

	}
	
}
