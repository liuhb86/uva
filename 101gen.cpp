#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

char *op;
char *method;
int main(){
	srand(time(NULL));
	int kase=rand()%10;
	for(int i=0;i<kase;i++){
		int n=rand()%30+2;
		cout<<n<<endl;
		int step=rand()%30;
		for(int j=0;j<step;j++){
			int from=rand()%n;
			int to=rand()%n;
			if(rand()%2==0) op="move"; else op="pile";
			if(rand()%2==0) method="onto"; else method="over";
			cout<<op<<" "<<from<<" "<<method<<" "<<to<<endl;
		}
		cout<<"quit"<<endl;
	}
	return 0;
}
