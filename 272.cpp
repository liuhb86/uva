#include <iostream>
using namespace std;

int main() {
	bool closing = false;
	char c;
	while(cin.get(c)) {
		if (c!='"') {cout<<c; continue;}
		if (closing) cout<<"''"; else cout<<"``";
		closing = !closing;
	}
	return 0;
}