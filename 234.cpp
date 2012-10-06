#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

const int INF=INT_MAX;

struct Alignment{
	int priority;
	int time;
};

bool compare(Alignment a1, Alignment a2){
	return a1.time<a2.time;
}

int main(){ 
	int best_miss[10];
	int cur_miss[10];
	int best_arrange[10];
	int programme[10];
	int segment[10];
	Alignment align[10];
	int kase=0;
	while(1){
		int p;
		cin>>p;
		if(p==0) break;
		++kase;
		for(int i=0;i<p;++i)
			cin>>programme[i];
		int a;
		cin>>a;
		int max_p=0;
		for(int i=0;i<a;++i){
			cin>>align[i].priority>>align[i].time;
			if (max_p<align[i].priority) max_p=align[i].priority;
		}
		sort(programme,programme+p);
		sort(align,align+a,compare);
		for(int i=1;i<=max_p;++i)
			best_miss[i]=INF;
		segment[p]=INF;
		
		do{
			for(int i=1;i<=max_p;++i)
				cur_miss[i]=0;
			segment[0]=programme[0];
			for(int i=1;i<p;++i)
				segment[i]=segment[i-1]+programme[i];
			int before=0;
			int after=segment[0];
			int cur=0;
			for(int i=0;i<a;++i){
				int t=align[i].time;
				//int ob, oa;
				while(1){
					if(t<after) break;
				//	ob=before;
				//	oa=after;
					before=after;
					after=segment[++cur];
				}
				cur_miss[align[i].priority]+=min(t-before, after-t);
				//if(cur_miss[align[i].priority]<0) {
				//	cout<<"#@@#@"<<before<<" "<<t<<" "<<after<<" "<<ob<<" "<<oa<<endl;
				//	for(int j=0;j<p;++j) cout<<segment[j]<<" ";
				//	cout<<":"<<cur<<endl;
				//}
			}
			bool best=false;
			for(int i=1;i<=max_p;++i){
				if(cur_miss[i]<best_miss[i]){best=true;break;}
				if(cur_miss[i]>best_miss[i]){break;}
			}
			if(best){
				for(int i=1;i<=max_p;++i)
					best_miss[i]=cur_miss[i];
				for(int i=0;i<p;++i)
					best_arrange[i]=programme[i];
			}
		}while(next_permutation(programme,programme+p));
		
		cout<<"Data set "<<kase<<endl;
		cout<<"  Order:";
		for(int i=0;i<p;++i)
			cout<<' '<<best_arrange[i];
		int sum_miss=0;
		for(int i=1;i<=max_p;++i){
			sum_miss+=best_miss[i];
	//		cout<<"*"<<best_miss[i];
		}
		cout<<endl<<"  Error: "<<sum_miss<<endl;
	}
	return 0;
}


