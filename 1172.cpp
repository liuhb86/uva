#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct OS {
	map<string, int> dict;
	int nos;
	OS() :nos(0) {}
	int get(string& s) {
		map<string, int>::iterator it = dict.find(s);
		if (it!=dict.end()) return it->second;
		int r = nos++;
		dict[s]= r;
		return r;
	}
};

int main() {
	int nkase;
	cin>>nkase;
	for (int kase=0;kase<nkase;++kase) {
		int m,n;
		OS os;
		string city, ostype;
		int osid, val;
		vector<int> c1, v1, c2, v2;
		cin>>m;
		for (int i=0;i<m;++i) {
			cin>>city>>ostype>>val;
			osid = os.get(ostype);
			c1.push_back(osid);
			v1.push_back(val);
		}
		cin>>n;
		for (int i=0;i<n;++i) {
			cin>>city>>ostype>>val;
			osid = os.get(ostype);
			c2.push_back(osid);
			v2.push_back(val);
		}
		
		vector<vector<int> > v(m+1);
		vector<vector<int> > count(m+1);
		v[0].resize(n+1);
		count[0].resize(n+1);
		for (int i=1;i<=m;++i) {
			v[i].resize(n+1);
			count[i].resize(n+1);
			for (int j=1;j<=n;++j) {
				if (v[i-1][j]<v[i][j-1]) {
					v[i][j]=v[i][j-1];
					count[i][j] = count[i][j-1];
				} else if (v[i-1][j]>v[i][j-1]) {
					v[i][j]= v[i-1][j];
					count[i][j] = count[i-1][j];
				} else {
					v[i][j] = v[i-1][j];
					count[i][j] = min(count[i][j-1], count[i-1][j]);
				}
				
				if (c1[i-1]==c2[j-1]) {
					int t = v1[i-1]+v2[j-1]+v[i-1][j-1];
					int tc = count[i-1][j-1]+1;
					if (t>v[i][j]) {
						v[i][j]=t;
						count[i][j]=tc;
					} else if (t==v[i][j]) {
						count[i][j]=min(count[i][j], tc);
					}
				}
			}
		}
		cout<<v[m][n]<<" "<<count[m][n]<<endl;
	}
	return 0;
}