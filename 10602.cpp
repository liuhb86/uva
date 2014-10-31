#include <iostream>
#include <string>
#include <map>
#include <deque>
using namespace std;

struct Trie{
	int count;
	map<char, Trie*> next;

	Trie():count(0) {}
	void insert(const char* s) {
		if (*s=='\0') {++count; return;}
		map<char, Trie*>::iterator it = next.find(*s);
		if (it==next.end()) {
			Trie* t= new Trie();
			next[*s] =t;
			t->insert(s+1);
		} else {
			it->second->insert(s+1);
		}
	}

	bool erase(const char* s){
		if (*s=='\0') {--count;}
		else {
			if (next[*s]->erase(s+1)) {
				delete next[*s];
				next.erase(*s);
			}
		}
		return count==0 && next.empty();
	}
};

int main() {
	int nkase;
	cin>>nkase;
	for (int kase=0;kase<nkase;++kase) {
		Trie trie;
		int n;
		cin>>n;
		string s;
		cin>>s;
		for (int i=1;i<n;++i) {
			string t;
			cin>>t;
			trie.insert(t.c_str());
		}
		int types = 0;
		deque<string> strings;
		types+=s.size();
		strings.push_back(s);
		for (int i=1;i<n;++i) {
			int common = 0;
			Trie* t=&trie;
			for (common=0;common<s.size();++common) {
				map<char, Trie*>::iterator it = t->next.find(s[common]);
				if (it==t->next.end()) break;
				t=it->second;
			}
			s.resize(common);
			while(t->count==0) {
				s.push_back(t->next.begin()->first);
				t=t->next.begin()->second;
			}
			trie.erase(s.c_str());
			types+=s.size()-common;
			strings.push_back(s);
		}

		cout<<types<<endl;
		for (int i=0;i<strings.size();++i) cout<<strings[i]<<endl;
	}
	return 0;
}