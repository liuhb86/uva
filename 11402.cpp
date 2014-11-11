#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

struct Input {
	int* repeat;
	char** pattern;
	int* pLen;
	int iPattern;
	int iRepeat;
	int iOffset;
	int count;
	int length;
	int index;
	
	Input(int size) :iPattern(0), iRepeat(0), iOffset(0), count(0), length(0), index(0) {
		repeat = new int[size];
		pattern = new char* [size];
		pLen = new int[size];
	}
	~Input() {
		for (int i=0;i<length;++i) delete pattern[i];
		delete repeat;
		delete pattern;
		delete pLen;
	}
	
	void add(int repeat, string& pattern) {
		if (repeat<=0 || pattern.empty()) return;
		int len = pattern.size();
		char* p = new char[len];
		memcpy(p, pattern.c_str(), len);
		this->repeat[length] = repeat;
		this->pattern[length] = p;
		pLen[length] = len;
		++length;
		count+= repeat*len;
	}
	
	inline int get(int index) {
		return next();
	}
	
	inline int next() {
		++index;
		if (iOffset>=pLen[iPattern]) {
			iOffset = 0;
			++iRepeat;
			if (iRepeat>=repeat[iPattern]) {
				iRepeat = 0;
				++iPattern;
			}
		}
		return pattern[iPattern][iOffset++]-'0';
	}
	
	int size() { return count;}
};

class SegTree {
public:
	SegTree(Input& array) {
		length = array.size();
		depth = length ==0 ? 0 : ceil(log(static_cast<double>(length))/log(2.0));
		size = (1<<(depth+1))-1 ;
		tree = new int[size];
		status = new char[size];
		init(0, 0, length-1, array);
	}
	
	~SegTree() {
		delete tree;
		delete status;
	}
	
	int query(int begin, int last) {
		return query(0, 0, length-1, begin, last);
	}
	
	void update(int begin, int last, char op) {
		update(0,0,length-1, begin, last, op);
	}
	
private:
	int length;
	int depth;
	int size;
	int* tree;
	char* status;
	
	int init(int index, int begin, int last, Input& array) {
		int d;
		if (begin==last) {
			d = array.get(begin);
		} else {
			int mid = leftLast(begin, last);
			d = init(left(index), begin, mid, array);
			d += init(right(index), mid+1, last, array);
		}
		tree[index] = d;
		status[index] = 'S';
		return d;
	}
	
	void updateStatus(int index, char op) {
		if (op != 'I') {
			status[index] = op;
			return;
		}
		char s;
		switch(status[index]) {
			case 'S': s='I'; break;
			case 'F': s='E'; break;
			case 'E': s='F'; break;
			case 'I': s='S'; break;
		}
		status[index] = s;
	}
	
	int getValue(int index, int begin, int last) {
		switch(status[index]) {
			case 'S': return tree[index];
			case 'F': return last-begin+1;
			case 'E': return 0;
			case 'I': return last-begin +1 -tree[index];
		}
		return -1;
	}
	
	void pushDownStatus(int index, int begin, int last) {
		if (status[index]=='S') return;
		tree[index] = getValue(index, begin, last);
		if (begin!=last) {
			updateStatus(left(index), status[index]);
			updateStatus(right(index), status[index]);
		}
		status[index] ='S';
	}
	
	int query(int index, int begin, int last, int qbegin, int qlast) {
		if (qbegin>last || qlast<begin) return 0;	// out of range
		pushDownStatus(index, begin, last);
		if (qbegin<=begin && qlast>=last) return tree[index];	// inclusive
		int mid = leftLast(begin, last);
		return query(left(index), begin, mid, qbegin, qlast)
			+ query(right(index), mid+1, last, qbegin, qlast);
	}
	
	int update(int index, int begin, int last, int qbegin, int qlast, char op) {
		if (qbegin<=begin && qlast>=last) {
			updateStatus(index, op);
			return getValue(index, begin, last);
		}

		if (qbegin>last || qlast<begin) return getValue(index, begin, last);		
		
		pushDownStatus(index, begin, last);
		int mid = leftLast(begin, last);
		int d = update(left(index), begin, mid, qbegin, qlast, op)
				+ update(right(index), mid+1, last, qbegin, qlast, op);
		tree[index] = d;
		return d;
	}
	
	inline static int left(int parent) {return 2*parent+1;}
	inline static int right(int parent) {return 2*parent+2;}
	inline static int leftLast(int begin, int last) { return begin+(last-begin)/2;}
};

int main() {
	int nkase;
	cin>>nkase;
	for (int kase=1;kase<=nkase;++kase) {
		cout<<"Case "<<kase<<":"<<endl;
		int m;
		cin>>m;
		Input input(m);
		for (int i=0;i<m;++i) {
			int t;
			cin>>t;
			string p;
			std::getline(cin, p);
			std::getline(cin, p);
			input.add(t,p);
		}
		SegTree segtree(input);
		int q;
		cin>>q;
		int nquery=0;
		for (int i=0;i<q;++i) {
			char op;
			int begin, last;
			cin>>op>>begin>>last;
			if (op=='S') {
				++nquery;
				cout<<"Q"<<nquery<<": "<<segtree.query(begin, last)<<endl;
			} else {
				segtree.update(begin, last, op);
			}
		}
	}
	return 0;
}