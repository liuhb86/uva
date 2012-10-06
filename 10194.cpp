#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

bool ilt(const string& s1,const string& s2){
	size_t len1,len2,lenm;
	len1=s1.length();len2=s2.length();lenm=min(len1,len2);
	for(size_t i=0;i<lenm;i++){
		if(i>=len1) return true;
		if(i>=len2) return false;
		if(toupper(s1[i])<toupper(s2[i])) return true;
		if(toupper(s1[i])>toupper(s2[i])) return false;
	}
	return true;
}

struct Team{
	string name;
	int win;
	int tie;
	int lose;
	int goalScored;
	int goalAgainst;
	int total()const {return win+tie+lose;}
	int point()const {return win*3+tie;}
	int goalDiff()const {return goalScored-goalAgainst;}
	Team(string& name):name(name),win(0),tie(0),lose(0),goalScored(0),goalAgainst(0){}
	bool operator<(const Team& b)const {
		if(point()<b.point()) return false;
		if(point()>b.point()) return true;
		if(win<b.win) return false;
		if(win>b.win) return true;
		if(goalDiff()<b.goalDiff()) return false;
		if(goalDiff()>b.goalDiff()) return true;
		if(goalScored<b.goalScored) return false;
		if(goalScored>b.goalScored) return true;
		if(total()>b.total()) return false;
		if(total()<b.total()) return true;
		return ilt(name,b.name);
	}

};

typedef deque<Team> Deque;
typedef map<string,Team*> Map;

int main(){

	int n;
	cin>>n;
	string s;
	getline(cin,s);
	Deque dteams;
	Map mteams;
	bool first=true;
	for(int i=0;i<n;i++){
		dteams.clear(); mteams.clear();
		if(first) first=false; else cout<<endl;
		getline(cin,s);
		cout<<s<<endl;
		int numTeam,numMatch;
		cin>>numTeam;
		getline(cin,s);
		for(int j=0;j<numTeam;j++){
			getline(cin,s);
			dteams.push_back(Team(s));
			mteams.insert(make_pair(s,&(dteams.back())));
		}
		cin>>numMatch;
		getline(cin,s);
		for(int j=0;j<numMatch;j++){
			Team* t1,*t2;
			int score1,score2;
			getline(cin,s,'#');
			t1=mteams.find(s)->second;
			cin>>score1;
			getline(cin,s,'@');
			cin>>score2;
			getline(cin,s,'#');
			getline(cin,s);
			t2=mteams.find(s)->second;
			t1->goalScored+=score1;
			t1->goalAgainst+=score2;
			t2->goalScored+=score2;
			t2->goalAgainst+=score1;
			if(score1>score2){t1->win++;t2->lose++;}
			else if(score1<score2){t1->lose++;t2->win++;}
			else {t1->tie++;t2->tie++;}
		}
		sort(dteams.begin(),dteams.end());
		int rank=1;
		for(Deque::iterator it=dteams.begin();it!=dteams.end();it++,rank++){
			cout<<rank<<") "<<it->name<<" "<<it->point()<<"p, "<<it->total()<<
				"g ("<<it->win<<"-"<<it->tie<<"-"<<it->lose<<"), "<<
				it->goalDiff()<<"gd ("<<it->goalScored<<"-"<<it->goalAgainst<<")"<<endl;
		}
		//cout<<endl;
	}	
}
