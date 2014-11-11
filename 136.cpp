#include <stdio.h>

const int k=1500;

int generator() {
	int ugly[k];
	ugly[0] = 1;
	int factor[3] = {2,3,5};
	int top[3] = {2,3,5};
	int index[3] = {0,0,0};
	int count = 1;
	while(count<k) {
		int s;
		if (top[0]<=top[1] && top[0]<=top[2]) {s=0;}
		else if (top[1]<=top[2]) {s=1;}
		else {s=2;}
		if (top[s]>ugly[count-1]) {
			ugly[count++] = top[s];
			//printf("%d ", top[s]);
		}
		top[s] = factor[s] * ugly[++index[s]];
	}
	return ugly[k-1];
}

int main() {
	//printf("The 1500'th ugly number is %d.\n", generator());
	printf("The 1500'th ugly number is 859963392.\n");
	return 0;
}