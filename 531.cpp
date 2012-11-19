//531 - Compromise
//DP, LCS, string split

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> p1, p2;
vector<int> result;

int d[110][110];
char solution[110][110];

int main(){
	while(true){
		p1.clear();
		p2.clear();		
		string s;
		while(cin>>s){
			if(s=="#") break;
			p1.push_back(s);
		}
		if(cin.eof()) break;
		while(cin>>s){
			if (s=="#") break;
			p2.push_back(s);
		}
		for(int i=0;i<=p2.size();++i) d[0][i]=0;
		for(int i=1;i<=p1.size();++i){
			d[i][0]=0;
			for(int j=1;j<=p2.size();++j){
				int m,t;
				m=d[i-1][j];
				solution[i][j]=1;
				t=d[i][j-1];
				if(t>m) {m=t; solution[i][j]=2;}
				if (p1[i-1]==p2[j-1]){
					t=d[i-1][j-1]+1;
					if (t>m) {m=t; solution[i][j]=3;}
				}
				d[i][j]=m;
			}
		}
		result.clear();
		int i=p1.size(), j=p2.size();
		while(i>0 && j>0){
			if (solution[i][j]==3){
				result.push_back(i-1);
				--i;--j;
			} else if (solution[i][j]==2)
				--j;
			else
				--i;
		}
		//reverse(result.begin(),result.end());
		bool first=true;
		for (vector<int>::reverse_iterator it=result.rbegin();it!=result.rend();++it){
			if(first) 
				first=false;
			else
				cout<<' ';
			cout<<p1[*it];
		}
		cout<<endl;
	}
	return 0;
}