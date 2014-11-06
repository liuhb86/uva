#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	int nkase;
	cin>>nkase;
	for (int kase=0;kase<nkase;++kase){
		string s;
		cin>>s;
		deque<int> pos[26];
		int len = s.size();
		for (int i=0;i<len;++i) {
			pos[s[i]-'a'].push_back(i);
		}
		bool odd = false;
		bool possible = true;
		for (int i=0;i<26;++i) {
			if (pos[i].size()%2==1) {
				if (odd) {possible = false; break;}
				odd = true;
			}
		}
		if ((len%2==0)==odd) possible = false;
		if (!possible) {cout<<"Impossible"<<endl; continue;}
		int nswap = 0;
		while(len>2) {
			int minSwap = 2*len;
			int minChar;
			for (int i=0;i<26;++i) {
				if (pos[i].size()<2) continue;
				int s = pos[i].front() + (len-pos[i].back()-1);
				if (s<minSwap) {
					minSwap = s;
					minChar = i;
				}
			}
			nswap+=minSwap;
			int p1 = pos[minChar].front();
			int p2 = pos[minChar].back();
			pos[minChar].pop_back(); pos[minChar].pop_front();
			for (int i=0;i<26;++i) {
				for (int j=0;j<pos[i].size();++j) {
					if (pos[i][j]>p2) pos[i][j]-=2;
					else if (pos[i][j]>p1) pos[i][j]-=1;
				}
			}
			len -=2;
		}
		cout<<nswap<<endl;
	}
	return 0;
}