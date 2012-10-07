#include <iostream>
#include <algorithm>

using namespace std;

struct Pack{
	int size;
	Pack* next;
	int depth;
};

int cmp_merge(Pack* p1, Pack* p2){
	return p1->depth < p2-> depth;
}
int cmp_sort(Pack p1, Pack p2){
	return p1.size < p2.size;
}


const int MAX = 10000+10;
Pack* buffer1[MAX];
Pack* buffer2[MAX];
Pack bags[MAX];

void print(Pack* p){
	if (p==0) return;
	cout<<p->size;
	if(p->next){
		cout<<' ';
		print(p->next);
	} else {
		cout<<endl;
	}
}

int main(){
	while (true){
		int n;
		cin>>n;
		if (n==0) break;
		for(int i=0;i<n;++i) cin>>bags[i].size;
		sort(bags,bags+n, cmp_sort);
		Pack** bufPrimary = buffer1;
		Pack** bufSecondary = buffer2;
		int nPack = 0;
		for(int i=0;i<n;){
			int size=bags[i].size;
			int count;
			int nNewPack = 0;
			for(count=0;i<n&& bags[i].size==size; ++i,++count){
				Pack* p = bags + i;
				if(count<nPack){
					p->next = bufPrimary[count];
					p->depth= bufPrimary[count]->depth+1;
					bufPrimary[count]=p;
				} else {
					++nNewPack;
					p->next = 0;
					p->depth = 0;
					bufPrimary[count]=p;
				}
			}
			if (nNewPack ==0){
				merge(bufPrimary, bufPrimary+count, bufPrimary+count, bufPrimary+nPack, bufSecondary, cmp_merge);
			} else {
				merge(bufPrimary, bufPrimary+nPack, bufPrimary+nPack, bufPrimary+nPack+nNewPack, bufSecondary, cmp_merge);
				nPack+=nNewPack;
			}
			swap(bufPrimary, bufSecondary);
		}
		cout<<nPack<<endl;
		for(int i=0; i<nPack; ++i){
			print(bufPrimary[i]);
		}
	}
	return 0;
}