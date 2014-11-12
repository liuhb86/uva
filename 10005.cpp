#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Point{
	double x;
	double y;
};

double distance2(Point& p1, Point& p2) {
	Point delta;
	delta.x = p1.x-p2.x;
	delta.y = p1.y-p2.y;
	return delta.x*delta.x+delta.y*delta.y;
}

bool getCenter(Point& p1, Point& p2, double r2, Point* center) {
	Point delta;
	delta.x = p1.x-p2.x;
	delta.y = p1.y-p2.y;
	double d2 = delta.x*delta.x+delta.y*delta.y;
	//double r2=r*r;
	if (d2>r2*4) return false;
	double d = sqrt(d2);
	double h = sqrt(r2-d2/4);
	Point offset;
	offset.x = delta.y * h / d;
	offset.y = -delta.x * h / d;
	Point middle;
	middle.x = (p1.x+p2.x)/2;
	middle.y = (p1.y+p2.y) /2;
	center[0].x = middle.x+offset.x;
	center[1].x = middle.x-offset.x;
	center[0].y = middle.y+offset.y;
	center[1].y = middle.y-offset.y;
	return true;
}

int main() {
	while(true) {
		int n;
		cin>>n;
		if (n==0) break;
		vector<Point> points(n);
		for (int i=0;i<n;++i) cin>>points[i].x>>points[i].y;
		double r;
		cin>>r;
		double r2 = r*r;
		bool possible = false;
		for (int i=0;i<n;++i) {
			for (int j=i+1;j<n;++j) {
				Point c[2];
				bool f = getCenter(points[i], points[j],r2, c);
				if (!f) goto breakI;
				//cout<<distance2(points[i],c[0])<<" "<<distance2(points[j],c[0])<<" "<<r2<<endl;
				for (int ci=0;ci<2;++ci) {
					bool contain = true;
					for (int k=0;k<n;++k) {
						if (k==i || k==j) continue;
						if (distance2(points[k], c[ci])>r2) {
							contain = false;
							break;
						}
					}
					if (contain) {possible = true; goto breakI;}
				}
			}
		}
breakI:
		if (possible) cout<<"The polygon can be packed in the circle."<<endl;
		else cout<<"There is no way of packing that polygon."<<endl;
	}
	return 0;
}