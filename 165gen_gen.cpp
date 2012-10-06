#include <iostream>
#include <fstream>
using namespace std;

int n[15][15];
int value[15][15][15];

int main(){
	ifstream fin("165gen.txt");
	ofstream fout("165gen_out.txt");
	fout<<"int value[15][15][15]={";
	for(int h=1;h<9;++h){
		if(h!=1) fout<<",";
		fout<<"{";
		for(int k=1;k<10-h;++k){
			if(k!=1) fout<<",";
			fout<<"{";
			for(int i=0;i<k;++i) {
				fin>>value[h][k][i];
				if(i!=0) fout<<",";
				fout<<value[h][k][i];
			}
			fout<<"}";
			char buf[10];
			fin>>buf;
			fin>>n[h][k];
		}
		fout<<"}";
	}
	fout<<"};"<<endl<<"int n[15][15]={";
	for(int h=1;h<9;++h){
		if(h!=1) fout<<",";
		fout<<"{";
		for(int k=1;k<10-h;++k){
			if(k!=1) fout<<",";
			fout<<n[h][k];
		}
		fout<<"}";
	}
	fout<<"};"<<endl;
	return 0;
}
