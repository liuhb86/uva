/*
NOTE on output spec:
	Each line has EXACT C columns, the width of which are as in the documetation.
	If there are not enough files, the column is filled by %width spaces.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;
typedef vector<string> Vec;
const int COL_WIDTH=60;
int main(){
	string separator;
	fill_n(inserter(separator,separator.begin()),COL_WIDTH,'-');
	Vec files;
	string file;
	int n;
	cout.setf(ios::left,ios::adjustfield);
	while(cin>>n){
		files.clear();
		getline(cin,file);
		int maxLen=0;
		for(int i=0;i<n;++i) {
			getline(cin,file);
			if(file.length()>maxLen) maxLen=file.length();
			files.push_back(file);
		}
		sort(files.begin(),files.end());
		int width=maxLen+2;
		int col=(COL_WIDTH-maxLen)/width+1;
		int row=(files.size()-1)/col+1;
		cout<<separator<<endl;
		//cout<<col<<" "<<row<<endl;
		int tail=COL_WIDTH-(col-1)*width-maxLen;
		
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				int index=j*row+i;
			
				int w2=(j==col-1)?maxLen:width;
				if(index>=files.size())  //goto break1;
					cout<<setw(w2)<<" "; //<<x<<" "<<y<<" "<<z;
				else
					cout<<setw(w2)<<files[index];//<<x<<" "<<y<<" "<<z;
			}
			//for(int j=0;j<tail;j++) cout<<" ";
			cout<<endl;
		}

break1:
		;
		/*if(files.size()%col!=0) {
			int tail=COL_WIDTH-(files.size()%col)*width;
			//for(int j=0;j<tail;j++) cout<<" ";
			cout<<endl;
		}*/
	}
	return 0;	
}
