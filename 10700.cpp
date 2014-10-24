#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int nkase;
	cin>>nkase;
	for (int kase=0;kase<nkase;++kase) {
		string s;
		cin>>s;
		vector<int> num;
		vector<char> op;
		vector<unsigned long long> r;
		int n=0;
		op.push_back(' ');
		for (int i=0;i<s.size();++i) {
			if (s[i]=='+' || s[i]=='*'){
				num.push_back(n);
				op.push_back(s[i]);
				n=0;
			} else {
				n=n*10+(s[i]-'0');
			}
		}
		num.push_back(n);

		r.clear();
		r.push_back(num[0]);
		for (int i=1;i<num.size();++i) {
			if (op[i]=='+') {
				r.push_back(num[i]);
			} else {
				r.back()*=num[i];
			}
		}
		unsigned long long minimum = 0;
		for (int i=0;i<r.size();++i) minimum += r[i];

		r.clear();
		r.push_back(num[0]);
		for (int i=1;i<num.size();++i) {
			if (op[i]=='+') {
				r.back()+=num[i];
			} else {
				r.push_back(num[i]);
			}
		}
		unsigned long long maximum = 1;
		for (int i=0;i<r.size();++i) maximum *= r[i];

		cout<<"The maximum and minimum are "<<maximum<<" and "<<minimum<<"."<<endl;
	}

	return 0;
}