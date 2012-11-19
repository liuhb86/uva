//10130 - SuperSale
//DP, pack

#include <iostream>
#include <map>
using namespace std;

int N, G;

struct cmp {
	bool operator () (int*a, int* b){
		for(int i=0;i<=G;++i){
			if (a[i]<b[i]) return true;
			if (a[i]>b[i]) return false;
		}
		return false;
	}
};

map<int*, int, cmp> table;

int price[1000+10];
int weight[1000+10];

int solve(int* arg){
	map<int*,int, cmp>::iterator it=table.find(arg);
 	if (it!=table.end()){
		delete[] arg;
		return it->second;
	}
	int vmax=0;
	int index=arg[0];
	if (index==0){
		for(int i=1;i<=G;++i){
			if(arg[i]>=weight[0]) {
				vmax = price[0];
				break;
			}
		}
	} else {
		int* newArg= new int[G+1]; memcpy(newArg, arg, sizeof(int)*(G+1));
		newArg[0]--;
		vmax = solve(newArg);
		for (int i=1;i<=G;++i){
			if (arg[i]>=weight[index]){
				newArg= new int[G+1]; memcpy(newArg, arg, sizeof(int)*(G+1));
				newArg[0]--;
				newArg[i]-=weight[index];
				int r= solve(newArg)+price[i];
				if(r>vmax) vmax=r;
			}
		}
	}
	table.insert(make_pair(arg,vmax));
	return vmax;
}

int main(){
	int T;
	cin>>T;
	for(int kase=0;kase<T;++kase){
		cin>>N;
		for(int i=0;i<N;++i){
			cin>>price[i]>>weight[i];
		}
		cin>>G;
		int* arg =new int[G+1];
		for(int i=1;i<=G;++i)
			cin>>arg[i];
		arg[0]=N-1;
		int result=solve(arg);
		cout<<result<<endl;
		for (map<int*,int,cmp>::iterator it=table.begin(); it!=table.end(); ++it){
			delete[] (it->first);
		}
		table.clear();
	}
	return 0;
}