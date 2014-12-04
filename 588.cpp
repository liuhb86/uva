#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Point {
	int x;
	int y;
};

int product(Point& p1, Point& p2, Point& p3) {
	return (p2.x-p1.x)*(p3.y-p2.y) - (p2.y-p1.y)*(p3.x-p2.x);
}

int main(){
	int kase = 0;
	while(true) {
		int n;
		cin>>n;
		if (n==0) break;
		++kase;
		int xl=INT_MIN, xu=INT_MAX, yl=INT_MIN, yu=INT_MAX;
		vector<int>x(n);
		vector<int>y(n);
		for (int i=0;i<n;++i) {
			cin>>x[i]>>y[i];
		}
		int px=x.back(), py=y.back();
		for (int i=0;i<n;++i) {
			if (x[i]==px) {
				if (y[i]>py) xl=max(xl, px);
				else xu=min(xu, px);
			} else {
				if (x[i]>px) yu=min(yu, py);
				else yl=max(yl, py);
			}
			px=x[i]; py=y[i];
		}
		bool possible = (xl<=xu && yl<=yu);

		cout<<"Floor #"<<kase<<endl;
		cout<<"Surveillance is "<<(possible? "possible":"impossible")<<"."<<endl<<endl;

	}
	return 0;
}
/*
int main(){
	int kase = 0;
	while(true) {
		int n;
		cin>>n;
		if (n==0) break;
		++kase;
		vector<Point> points(n);
		for (int i=0;i<n;++i) {
			cin>>points[i].x>>points[i].y;
		}
		bool possible = false;
		for (int i=0;i<n;++i) {
			bool visible = true;
			for (int j=1;j<n-1;++j) {
				if (product(points[i], points[(i+j)%n], points[(i+j+1)%n]) > 0) {
					visible = false;
					break;
				}
			}
			if (visible) {
				possible = true;
				break;
			}
		}

		cout<<"Floor #"<<kase<<endl;
		cout<<"Surveillance is "<<(possible? "possible":"impossible")<<"."<<endl<<endl;

	}
	return 0;
}
*/