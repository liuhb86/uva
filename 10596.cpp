#include <iostream>
#include <cstring>
using namespace std;

const int MAX_NODE=200+10;
int connected[MAX_NODE];
bool used[MAX_NODE];
int degree[MAX_NODE];

int main(){
	int n_nodes,n_edges;
	while(cin>>n_nodes>>n_edges){
		for(int i=0;i<n_nodes;++i) {
			connected[i]=i;
			used[i]=false;
			degree[i]=0;
		}
		int m,n;
		for(int i=0;i<n_edges;++i){
			cin>>m>>n;
			//cout<<m<<endl;
			++degree[m];
			++degree[n];
			used[m]=true;
			used[n]=true;
			if(connected[m]!=connected[n]){
				for(int j=0;j<n_nodes;++j) if(connected[j]==connected[n]) connected[j]=connected[m];
			}
		}
		//cout<<m<<endl;
		//for(int i=0;i<n_nodes;++i) cout<<used[i]<<"_"<<connected[i]<<" ";
		int connect=-1;
		//cout<<endl<<m;
		bool possible=true;
		for(int i=0;i<n_nodes;++i){
			if(used[i]){
				if(degree[i]%2!=0){possible=false;break;}
				if (connect==-1) connect=connected[i];
				else if(connected[i]!=connect){possible=false;break;}
			}
		}
		if(possible && n_edges)cout<<"Possible"<<endl;
		else cout<<"Not Possible"<<endl;
	}
	return 0;
}
