#include <iostream>
using namespace std;

char field[101][101];
int main() {
	int kase = 0;
	while(true) {
		int m,n;
		cin>>m>>n;
		if (m==0 && n==0) break;
		++kase;
		for (int i=0;i<m;++i) cin>>field[i];
		for (int i=0;i<m;++i) {
			for (int j=0;j<n;++j) {
				if (field[i][j]=='*') continue;
				int c = 0;
				for (int ii=i-1;ii<=i+1;++ii) {
					if (ii<0 || ii>=m) continue;
					for (int jj=j-1;jj<=j+1;++jj) {
						if (jj>=0 && jj<n && field[ii][jj]=='*') ++c;
					}
				}
				field[i][j]=c+'0';
			}
		}
		if (kase>1) cout<<endl;
		cout<<"Field #"<<kase<<":"<<endl;
		for (int i=0;i<m;++i) cout<<field[i]<<endl;
	}
	return 0;
}