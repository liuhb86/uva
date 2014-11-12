#include <iostream>
#include <cstring>
using namespace std;

int main() {
	const char* key[4]={"`1234567890-=","QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./"};
	char map[128];
	for (int i=0;i<4;++i) {
		int len = strlen(key[i]);
		for (int j=1;j<len;++j) map[key[i][j]] = key[i][j-1];
	}
	map['\n'] = '\n';
	map[' ']=' ';
	char c;
	while(cin.get(c)) cout<<map[c];
}