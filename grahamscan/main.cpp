#include<bits/stdc++.h>
using namespace std;
template <typename T>
struct point{
	T x,y;
	point(T xx, T yy){x = xx; y = yy;}
};
template <typename T>
double tfunc(point<T> a, point<T> b){return (b.x-a.x)/((double) sqrt(pow(b.x-a.x,2) + pow(b.y-a.y,2)));}
template <typename T>
bool conv(point<T> a, point<T> b, point<T> c){return (a.y-b.y)*(b.x-c.x) >= (b.y-c.y)*(a.x-b.x);}
template<typename T>
vector<point<T>> grahamscan(vector<point<T>> points){
	point<T> min_y = points[0];
	vector<pair<point<T>, double>> point_angle;
	for(auto p : points) if(p.y < min_y.y) min_y = p;
	for(auto p : points) if(p.x != min_y.x || p.y != min_y.y) point_angle.push_back({p, tfunc(min_y, p)});
	for(auto pr : point_angle) printf("%d %d\n", pr.first.x, pr.first.y);
	sort(point_angle.begin(), point_angle.end(), [](pair<point<T>, double> a, pair<point<T>, double> b){return a.second > b.second;});
	for(auto pr : point_angle) printf("%d %d %f\n", pr.first.x, pr.first.y, pr.second);
	points = {min_y};
	for(auto pr : point_angle){
		while(points.size() >= 2 && !conv(pr.first, points[points.size()-1], points[points.size()-2])) points.pop_back();
		points.push_back(pr.first);
	}
	return points;
}

int main(){}
