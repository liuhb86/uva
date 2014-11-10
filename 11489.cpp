#include <iostream>
#include <string>
using namespace std;

int main() {
	int nkase;
	cin>>nkase;
	int count[3];
	string line;
	std::getline(cin,line);
	for (int kase=1;kase<=nkase;++kase) {
		for (int i=0;i<3;++i) count[i]=0;
		std::getline(cin, line);
		int f = 0;
		for (int i=0;i<line.size();++i) {
			int d = line[i]-'0';
			int r = d%3;
			++(count[r]);
			f = (f+r) %3;
		}
		bool swin;
		if (f==0) {
			swin = (count[0]%2==1);
		} else {
			swin = (count[f]>0 && count[0]%2==0);
		}
		
		char winner = swin?'S':'T';
		cout<<"Case "<<kase<<": "<<winner<<endl;
		
	}
	return 0;
}