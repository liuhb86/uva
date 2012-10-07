#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 100+10;
const int nCountry = 20;
int distances[MAXN][MAXN];

int main(){
	int kase=0;
	while (true){
		char c;
		while(cin>>c){
			if (!isspace(c)){
				cin.putback(c);
				break;
			}
		}
		if (cin.eof()) break;
		++kase;
		memset(distances, -1, sizeof(distances));
		
		for(int i=1;i<20;++i){
			int nNbr;
			cin>>nNbr;
			for(int j=0;j<nNbr; ++j){
				int k;
				cin>>k;
				distances[i][k] = distances[k][i] = 1;
			}
		}
		for(int i=1;i<=20;++i) distances[i][i]=0;

		for (int k=1;k<=20; ++k){
			for(int i=1;i<=20; ++i){
				for(int j=1; j<=20; ++j){
					if (distances[i][k]>=0 && distances[k][j]>=0){
						int dist = distances[i][k] +distances[k][j];
						if (distances[i][j]<0 || dist<distances[i][j])
							distances[i][j] = dist;
					}
				}
			}
		}

		cout<<"Test Set #"<<kase<<endl;
		int nTest;
		cin>>nTest;
		for(int i=0;i<nTest; ++i){
			int src, dest;
			cin>>src>>dest;
			printf("%2d to %2d: %d\n", src, dest, distances[src][dest]);

		}
		cout<<endl;
	}
}
