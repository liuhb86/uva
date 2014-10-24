#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Point{
	int x;
	int y;
};

struct Slope {
	int dx;
	int dy;
	bool operator < (const Slope& that) const {
		if (that.dx==0) return false;
		if (dx==0) return true;
		if (dx*that.dx >0) return dy*that.dx < that.dy*dx;
		return dy*that.dx > that.dy*dx;
	}
};

int main() {
	string line;
	std::getline(std::cin, line);
	istringstream iss(line);
	int nkase;
	iss>>nkase;
	std::getline(std::cin, line);
	for (int kase=0;kase<nkase;++kase) {
		vector<Point> points;
		while(true){
			std::getline(std::cin, line);
			if (line.empty()) break;
			istringstream iss(line);
			int x, y;
			iss>>x>>y;
			points.push_back(Point());
			points.back().x = x;
			points.back().y = y;
		}

		int maxPoints = 0;
		for (int i=0;i<points.size();++i) {
			int countSame = 0;
			int countSlope = 0;
			map<Slope, int> slopes;
			for (int j=0;j<points.size();++j) {
				if (points[j].x==points[i].x && points[j].y==points[i].y) {
					++countSame;
					continue;
				}
				Slope s;
				s.dx = points[j].x-points[i].x;
				s.dy = points[j].y-points[i].y;
				int& count = slopes[s];
				++count;
				countSlope=max(countSlope, count);
			}
			maxPoints = max(maxPoints, countSame+countSlope);
		}
		if (kase>0) cout<<endl;
		cout<<maxPoints<<endl;
	}

}