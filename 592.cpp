#include <iostream>
#include <cstring>
using namespace std;

enum Pred{INIT,MULTI,DIVINE,HUMAN,EVIL,LYING,DAY,NIGHT};
const int TIME=-1;
struct Statement{
	int speaker;
	int subject;
	bool negative;
	Pred predictive;
	void get();
	bool check();
};

const int MAX_BEING=5;
Pred deduction[MAX_BEING+5];
Pred deduction_day;
int appeared[MAX_BEING+5];
Statement statements[50+5];
int n_statement;
Pred curDeduce[MAX_BEING+5];
Pred curDay;
bool possible;

void Statement::get(){
	char buffer[50];
	cin.getline(buffer,sizeof(buffer));
	//cout<<buffer<<"****";
	cin.getline(buffer,sizeof(buffer),':');
	//cin>>buffer;
	//cout<<buffer<<"###";
	speaker=buffer[0]-'A';
	appeared[speaker]=true;
	cin>>buffer;
	//cout<<buffer<<endl;
	if(strcmp(buffer,"It")==0){
		subject=TIME;	
		cin>>buffer;
		negative=false;
		cin>>buffer;
		if(buffer[0]=='d') predictive=DAY; else predictive=NIGHT;
		return;
	}
	if (buffer[0]=='I') subject=speaker; else subject=buffer[0]-'A';
	appeared[subject]=true;
	cin>>buffer;
	cin>>buffer;
	if(strcmp(buffer,"not")==0) {negative=true;cin>>buffer;} else negative=false;
	if (buffer[0]=='d') predictive=DIVINE;
	else if(buffer[0]=='h') predictive=HUMAN;
	else if(buffer[0]=='e') predictive=EVIL;
	else predictive=LYING;
}

bool Statement::check(){
	bool falseSpeaking=(curDeduce[speaker]==EVIL || (curDeduce[speaker]==HUMAN && curDay==NIGHT));
	bool satisfied;
	if(subject==TIME)	satisfied=((predictive==curDay));
	else {
		if(predictive==LYING) satisfied=(curDeduce[subject]==EVIL || (curDeduce[subject]==HUMAN && curDay==NIGHT));
		else satisfied=(predictive==curDeduce[subject]);
		satisfied=satisfied^negative;
	}
	return satisfied^falseSpeaking;
}

void deduce(int being){
	if(being!=MAX_BEING){
		if(!appeared[being]) deduce(being+1);
		else{
			curDeduce[being]=DIVINE; deduce(being+1);
			curDeduce[being]=HUMAN; deduce(being+1);
			curDeduce[being]=EVIL; deduce(being+1);
		}
	}else{
		bool valid=true;
		for(int i=0;i<n_statement;++i) if(!statements[i].check()) {valid=false;break;}
		if(valid){
			possible=true;
			for(int i=0;i<MAX_BEING;++i){
				if(!appeared[i]) continue;
				if(deduction[i]==MULTI) continue;
				if(deduction[i]==INIT) {deduction[i]=curDeduce[i];continue;}
				if(deduction[i]!=curDeduce[i]) deduction[i]=MULTI;
			}
			if(deduction_day==INIT) deduction_day=curDay;
			else if(deduction_day!=MULTI){
				if(deduction_day!=curDay) deduction_day=MULTI;
			}
		}
	}
}

int main(){
	int kase=0;
	while(1){
		cin>>n_statement;
		if(n_statement==0) break;
		++kase;
		memset(appeared,0,sizeof(appeared));
		for(int i=0;i<MAX_BEING;++i) deduction[i]=INIT;
		deduction_day=INIT;
		for(int i=0;i<n_statement;++i) statements[i].get();
		possible=false;
		curDay=DAY;
		for(int i=0;i<2;++i){
			deduce(0);
			curDay=NIGHT;
		}
		cout<<"Conversation #"<<kase<<endl;
		if(!possible) cout<<"This is impossible."<<endl;
		else{
			bool deduciable=false;
			for(int i=0;i<MAX_BEING;++i){
				if(!appeared[i]) continue;
				if(deduction[i]==MULTI) continue;
				deduciable=true;
				cout<<static_cast<char>('A'+i)<<" is ";
				if(deduction[i]==DIVINE) cout<<"divine";
				else if(deduction[i]==HUMAN) cout<<"human";
				else cout<<"evil";
				cout<<"."<<endl;
			}
			if(deduction_day!=MULTI){
				deduciable=true;
				cout<<"It is ";
				if(deduction_day==DAY) cout<<"day";
				else cout<<"night";
				cout<<"."<<endl;
			}
			if(!deduciable) cout<<"No facts are deducible."<<endl;
		}
		cout<<endl;
	}
	return 0;
}
