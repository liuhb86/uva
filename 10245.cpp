#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

struct Point{
	double x;
	double y;

	double distance2(const Point& p){
		return (x - p.x)*(x - p.x) + (y - p.y)*(y - p.y);
	}
};

bool cmp(Point a, Point b){
	return a.x<b.x;
}

const int MAX = 10000+10;
Point points[MAX];
Point sortY[MAX];
Point tmp[MAX];

double calcMinDistance2(Point* begin, Point* end,Point* yBegin){
	size_t length = end-begin;
	if(length <= 2){
		if (length ==0) {
			return -1;
		} else if (length ==1){
			*yBegin = *begin;
			return -1;
		}else if (length ==2){
			if(begin[0].y <= begin[1].y) {
				yBegin[0] = begin[0]; yBegin[1]=begin[1];
			}else {
				yBegin[0] = begin[1]; yBegin[1]=begin[0];
			}
			return begin->distance2(begin[1]);
		}
	}
	Point* middle = begin + (length+1)/2;
	Point* yMiddle = yBegin + (length+1)/2;
	double minDist2 =  calcMinDistance2(begin, middle, yBegin);
	double minRight = calcMinDistance2(middle, end, yMiddle);
	if (minRight>=0 && minRight<minDist2) minDist2 = minRight;

	//merge
	Point* y1 = yBegin, *y2 = yMiddle, *yEnd = yBegin+length, *dest;
	for(dest = tmp; y1!= yMiddle && y2!=yEnd; ++dest){
		if (y1->y<=y2->y) *dest = *(y1++);
		else *dest = *(y2++);
	}
	for(;y1!=yMiddle;++y1,++dest) *dest = *y1;
	for(;y2!=yEnd; ++y2,++dest) *dest = *y2;

	//copyback & get points in delta range
	for(y1=yBegin, y2=dest=tmp; y1!=yEnd; ++y1,++y2){
		*y1 = *y2;
		double delta = y2->x -middle->x;
		delta *= delta;
		if (delta<minDist2) {
			*(dest++) = *y2;
		}
	}

	//calc min distance betwen two parts
	for(y1=tmp;y1!=dest;++y1){
		for(y2=y1+1; y2<y1+8&& y2!=dest; ++y2){
			double tmin = y1->distance2(*y2);
			if (tmin<minDist2) minDist2 = tmin;
		}
	}

	return minDist2;
}

/*
Point *dbgP1, *dbgP2;
double naive(Point* begin, Point* end){
	if (begin+1>=end) return -1;
	double minDistance2 = begin->distance2(begin[1]);
	dbgP1=begin; dbgP2=begin+1;
	for(Point* p1=begin;p1!=end; ++p1){
		for(Point* p2=p1+1; p2!=end; ++p2){
			double dist = p1->distance2(*p2);
			if(dist<minDistance2) {
				minDistance2 = dist;
				dbgP1 = p1;
				dbgP2 = p2;
			}
		}
	}
	return minDistance2;
}
*/

int main(){
	while (true){
		int n;
		cin>>n;
		if (n==0) break;
		for(int i=0;i<n;++i){
			cin>>points[i].x>>points[i].y;
		}
		sort(points,points+n, cmp);
		/*for(Point* p=points; p!=points+n; ++p){
			cout<<p->x<<' '<<p->y<<endl;
		}*/
		double minDistance2 = calcMinDistance2(points, points+n,sortY);
		if (minDistance2<0 || minDistance2>10000*10000)
			cout<<"INFINITY"<<endl;
		else
			printf("%.4lf\n", sqrt(minDistance2));
		/*minDistance2 = naive(points, points+n);
		cout<<dbgP1-points<<dbgP1->x<<dbgP1->y<<endl;
		cout<<dbgP2-points<<dbgP2->x<<dbgP2->y<<endl;
		if (minDistance2<0 || minDistance2>10000*10000)
			cout<<"INFINITY"<<endl;
		else
			printf("%.4lf\n", sqrt(minDistance2));
		*/

	}
	return 0;
}