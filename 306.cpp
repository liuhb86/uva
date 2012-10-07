#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 200+10;
int key[MAX];
typedef vector<int> Vec;
Vec permGroup[MAX];
Vec* groupOfKey[MAX];
int indexInGroup[MAX];
char buffer[MAX];
char encrypted[MAX];

int main(){
	while(true){
		int n;
		cin>>n;
		if (n==0) break;
		memset(groupOfKey, 0, n*sizeof(groupOfKey[0]));
		for(int i=0;i<n; ++i) cin>>key[i];

		int nGroups = 0;
		for(int i=0;i<n; ++i){
			if (groupOfKey[i]!=0) continue;
			Vec& group = permGroup[nGroups++];
			group.clear();
			int k = i;
			do {
				groupOfKey[k]=&group;
				indexInGroup[k] = (int)group.size();
				group.push_back(k);
				k = key[k]-1;
			} while (k!=i);
		}
		while(true){
			int repeat;
			cin>>repeat;
			if (repeat ==0) break;
			cin.getline(buffer, MAX);
			char* msg = buffer+1;
			for(int i=(int) strlen(msg); i<n; ++i){
				msg[i]=' ';
			}
			msg[n]=0;
			for(int i=0;i<n; ++i){
				Vec* group = groupOfKey[i];
				int index = indexInGroup[i];
				int groupSize =  (int) group->size();
				index = (index + repeat) % groupSize;
				encrypted[(*group)[index]] = msg[i];
			}
			encrypted[n]=0;
			cout<<encrypted<<endl;
		}
		cout<<endl;
	}
	return 0;
}