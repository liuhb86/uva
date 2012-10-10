//10875 - Big Math
//parse, ,pretty print, calculator
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <deque>
#include <cstring>
using namespace std;

struct Line{
	static const int HEIGHT= 5;
	static const int N_SYMBOLS = 14;
	static const char printSymbols[HEIGHT][4*N_SYMBOLS+10];
	static const char symbols[];
	static map<int,char> symbolMap;
	static map<char,int> symbolIndex;
	static bool _init;
	static bool static_init() {
		for (int i=0;i< N_SYMBOLS; ++i){
			int sum = 0;
			int bit =1;
			symbolIndex.insert(make_pair(symbols[i],i));
			for(int row=0;row<HEIGHT;++row) {
				for(int col = 4*i;col<4*i+3;++col){
					if(printSymbols[row][col]=='0') sum+=bit;
					bit<<=1;
				}
			}
			symbolMap.insert(make_pair(sum,symbols[i]));
		}
		return true;
	}
	string buffer[HEIGHT];
	void clear(){
		for(int i=0; i<HEIGHT;++i) buffer[i].clear();
	}

	int get(char* dest) const{
		int length = (int) (buffer[0].size()+1)/4;
		for (int i=0;i<length; ++i){
			int sum = 0;
			int bit =1;
			for(int row=0;row<HEIGHT;++row) {
				for(int col = 4*i;col<4*i+3;++col){
					if(buffer[row][col]=='0') sum+=bit;
					bit<<=1;
				}
			}
			dest[i] = symbolMap[sum];
		}
		dest[length]=0;
		return length;
	}

	void put(char c){
		int i = symbolIndex[c];
		for(int row=0;row<HEIGHT;++row){
			if (buffer[row].size() != 0) buffer[row].push_back(' ');
			for(int col = 4*i;col<4*i+3;++col){	
				buffer[row].push_back(printSymbols[row][col]);
			}
		}
	}

	void put(int v){
		bool minus = v<0;
		if (minus) {
			v=-v;
			put('-');
		}
		vector<char> digits;
		while(v>0){
			int d = v%10;
			v = v/10;
			digits.push_back('0'+d);
		}
		if (digits.size()==0) digits.push_back('0');
		for (vector<char>::reverse_iterator it=digits.rbegin(); it!=digits.rend(); ++it){
			put(*it);
		}
	}

	
};
const char Line::symbols[N_SYMBOLS+10] = "0123456789+-*/";
const char Line::printSymbols[Line::HEIGHT][4*(10+4)+10] ={
		"000 .0. 000 000 0.0 000 0.. 000 000 000 .0. ... 0.0 .0.",
		"0.0 .0. ..0 ..0 0.0 0.. 0.. ..0 0.0 0.0 .0. ... 0.0 ...",
		"0.0 .0. 000 000 000 000 000 ..0 000 000 000 000 .0. 000",
		"0.0 .0. 0.. ..0 ..0 ..0 0.0 ..0 0.0 ..0 .0. ... 0.0 ...",
		"000 .0. 000 000 ..0 000 000 ..0 000 ..0 .0. ... 0.0 .0."
};
map<int,char> Line::symbolMap;
map<char,int> Line::symbolIndex;
bool Line::_init = Line::static_init();
ostream& operator <<(ostream& os, const Line& line){
	for(int row=0;row<line.HEIGHT;++row){
		os<<line.buffer[row]<<endl;
	}
	os<<endl;
	return os;
}
istream& operator >>(istream& is, Line& line){
	string s;
	for(int i=0;i<line.HEIGHT;++i){
		getline(is, line.buffer[i]);
		//for debug
		if(line.buffer[i][0]!='0' && line.buffer[i][0]!='.'){
			string s = line.buffer[i];
			cout<<"Echo Mode: "<<s<<endl;
			line.clear();
			for(size_t j=1;j<s.size(); ++j){
				line.put(s[j]);
			}
			cout<<line;
			return is;
		}
	}
	getline(is, s);
	return is;
}

char inBuf[1000];

int priority(char op){
	if (op==0) return -1;
	if (op=='*' || op=='/') return 2;
	else return 1;
}

int calc(char* expr){
	deque<int> numStack;
	deque<char> opStack;
	int num=0;
	int i=0;
	while(true){
		char c=inBuf[i++];
		if(c>='0' && c<='9') num=num*10+c-'0';
		else {
			numStack.push_back(num);
			num = 0;
			while(!opStack.empty() && priority(c)<=priority(opStack.back())){
				char op = opStack.back(); opStack.pop_back();
				int oprand1,oprand2, result=0;
				oprand2 = numStack.back(); numStack.pop_back();
				oprand1 = numStack.back(); numStack.pop_back();
				switch(op){
					case '+': result = oprand1 + oprand2; break;
					case '-': result = oprand1 - oprand2; break;
					case '*': result = oprand1 * oprand2; break;
					case '/': result = oprand1 / oprand2; break;
				}
				numStack.push_back(result);
			}
			opStack.push_back(c);
		}
		if (c==0) break;
	}
	return numStack.back();
}

int main(){
	Line line;
	while(true){
		line.clear();
		cin>>line;
		line.get(inBuf);
		//cin.getline(inBuf,1000);
		//cout<<inBuf<<endl;
		if (strcmp(inBuf,"0")==0) break;
		int result = calc(inBuf);
		line.clear();
		line.put(result);
		cout<<line;
	}
	return 0;
}
