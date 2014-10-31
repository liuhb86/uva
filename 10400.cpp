#include <iostream>
#include <cstring>
using namespace std;

bool visited[101][64001];
char path[101];
int num[101];
int target;
int p;

bool solve(int result, int i) {
	if (result>32000 || result<-32000) return false;
	if (i==p) {
		if (result!=target) return false;
		cout<<num[0];
		for (int j=1;j<p;++j) cout<<path[j]<<num[j];
		cout<<"="<<target<<endl;
		return true;
	}
	if (visited[i][result+32000]) return false;
	visited[i][result+32000] = true;

	path[i]='+';
	if (solve(result+num[i], i+1)) return true;
	path[i]='-';
	if (solve(result-num[i], i+1)) return true;
	path[i]='*';
	if (solve(result*num[i], i+1)) return true;
	if (num[i]!=0 && result%num[i]==0) {
		path[i]='/';
		if (solve(result/num[i], i+1)) return true;
	}
	return false;
}

int main() {
	int nkase = 0;
	cin>>nkase;
	for (int kase=0;kase<nkase;++kase) {
		memset(visited, 0, sizeof(visited));
		cin>>p;
		for (int i=0;i<p;++i) cin>>num[i];
		cin>>target;
		if (!solve(num[0], 1)) {
			cout<<"NO EXPRESSION"<<endl;
		}
	}
}