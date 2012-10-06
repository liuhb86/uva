#include <iostream> 
using namespace std;

const int MAX_STATIONS=7+3;
const int MAX_ORDERS=22+3;
int numPassengers[MAX_STATIONS];
int src[MAX_ORDERS];
int dest[MAX_ORDERS];
int numTickets[MAX_ORDERS];
int capacity, numStations, numOrders;

int earning;
int maxEarning;

void solve(int idxOrder){
	/*cout<<idxOrder<<" "<<earning;
	for(int i=0;i<numStations;++i) cout<<" "<<numPassengers[i];
	cout<<endl;*/
	if(idxOrder==numOrders){
		if(earning>maxEarning) maxEarning=earning;
		return ;
	}
	solve(idxOrder+1);
	int i;
	bool success=true;
	for(i=src[idxOrder];i<dest[idxOrder];++i){
		numPassengers[i]+=numTickets[idxOrder];
		if(numPassengers[i]>capacity){
			numPassengers[i]-=numTickets[idxOrder];
			success=false;
			break;
		}
	}
	if(success){
		int profit=(dest[idxOrder]-src[idxOrder])*numTickets[idxOrder];
		earning+=profit;
		solve(idxOrder+1);
		earning-=profit;
	}
	for(int j=src[idxOrder];j<i;j++) numPassengers[j]-=numTickets[idxOrder];
}

int main(){
	while(1){
		cin>>capacity>>numStations>>numOrders;
		if(capacity==0 && numStations==0 && numOrders==0) break;
		++numStations;
		for(int i=0;i<numOrders;++i) cin>>src[i]>>dest[i]>>numTickets[i];
		for(int i=0;i<numStations;++i) numPassengers[i]=0;
		earning=0;
		maxEarning=0;
		solve(0);
		cout<<maxEarning<<endl;
	}
	return 0;
}
