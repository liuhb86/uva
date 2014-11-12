#include <iostream>
using namespace std;

int main() {
	while(true){
		unsigned long long a,b;
		cin>>a>>b;
		if (a==0 && b==0) break;
		int c = 0;
		int carry = 0;
		while(c!=0 || (a!=0 && b!=0)) {
			int da = a%10;
			a/=10;
			int db = b%10;
			b/=10;
			if (da+db+c>=10) {
				++carry;
				c=1;
			} else {
				c=0;
			}
		}
		if (carry==0) cout<<"No carry operation.";
		else if (carry==1) cout<<"1 carry operation.";
		else cout<<carry<<" carry operations.";
		cout<<endl;
	}
	return 0;
}