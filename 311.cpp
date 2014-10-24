#include <iostream>
#include <string>
using namespace std;

int ceiling(int a, int b) {
	return (a%b==0) ? a/b : a/b+1;
}
int main() {
	int count[7];
	while(true) {
		bool end = true;
		for (int i=1;i<=6;++i) {
			cin>>count[i];
			end = end && count[i]==0;
		}
		if (end) break;

		int boxes = 0;
		int slot2= 0;
		int slot1 = 0;

		boxes+=count[6];
		boxes+=count[5]; slot1+= count[5]*11;
		boxes+=count[4]; slot2+= count[4]*5;
		
		boxes+=ceiling(count[3],4);
		switch(count[3]%4) {
		case 0: break;
		case 1: slot2+=5; slot1+=7; break;
		case 2: slot2+=3; slot1+=6; break;
		case 3: slot2+=1; slot1+=5; break;
		}
		
		if (slot2>=count[2]) {
			slot2-=count[2];
			slot1+=slot2*4;
		} else {
			count[2]-=slot2;
			boxes+=ceiling(count[2],9);
			slot1+=(9-count[2]%9)%9*4;
		}

		if (count[1] > slot1) {
			count[1]-=slot1;
			boxes+=ceiling(count[1], 36);
		}

		cout<<boxes<<endl;
	}
}