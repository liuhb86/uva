#include <iostream>
using namespace std;

int main() {
	int b[3][3];
	const char* p[6] = {"132","123","312","321","213","231"};
	const char* c="BGC";
	while(true) {
		for (int i=0;i<3;++i) {
			for (int j=0;j<3;++j) {
				cin>>b[i][j];
				if (!cin) return 0;
			}
		}
		int min;
		int minK;
		for (int k=0;k<6;++k) {
			int count =0;
			for (int i=0;i<3;++i) {
				int color = p[k][i]-'1';
				for (int j=0; j<3;++j) {
					if (j!=i) count+=b[j][color];
				}
			}
			if (k==0 || count<min) {min=count; minK=k;}
		}
		for (int i=0;i<3;++i) cout<<c[p[minK][i]-'1'];
		cout<<" "<<min<<endl;
	}
	return 0;
}