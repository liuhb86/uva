#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int nkase;
	cin>>nkase;
	int edge[4];
	for (int kase =0;kase<nkase;++kase) {
		for (int i=0;i<4;++i) cin>>edge[i];
		sort(edge, edge+4);
		if (edge[0]==edge[3]) cout<<"square";
		else if (edge[0]==edge[1] && edge[2]==edge[3]) cout<<"rectangle";
		else if (edge[0]+edge[1]+edge[2]>edge[3]) cout<<"quadrangle";
		else cout<<"banana";
		cout<<endl;
	}
	return 0;
}