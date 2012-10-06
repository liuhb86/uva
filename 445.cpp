#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
const int MAX=150;
int main(){
    char line[MAX];
    while(cin.getline(line,MAX)){
        int len=strlen(line);
        if(line[len-1]=='\n') len--;
        if(len==0) {cout<<endl;continue;}
        int count=0;
        for(int i=0;i<len;i++){
            if(isdigit( line[i])) count+=line[i]-'0';
            else if(line[i]=='!') cout<<endl;
            else {
                if(line[i]=='b') line[i]=' ';
                for(int j=0;j<count;j++) cout<<line[i];
                count=0;     
            } 
        }
        cout<<endl;                            
    }
    return 0;    
}
