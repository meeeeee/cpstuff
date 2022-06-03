#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct point{
	T x, y;
	point(){}
	point(T xx, T yy){
		x = xx;
		y = yy;
	}
	bool conv(point<T> b, point<T> c){return (y-b.y)*(b.x-c.x) >= (b.y-c.y)*(x-b.x);}//convexity reverses between lower and upper
};

template <typename T>
vector<point<T>> convhull(vector<point<T>> points){// assume no three points colinear
	point<T> mp = points[0];
	for(auto p : points) if(mp.x > p.x) mp = p;
	vector<point<T>> upper, lower, u({mp}), l({mp});
	for(auto p : points){
		if(p.y >= mp.y) upper.push_back(p);
		else lower.push_back(p);
	}
	auto srt = [](point<T> a, point<T> b){return a.x < b.x;};
	sort(upper.begin(),upper.end(), srt);
	sort(lower.begin(), lower.end(). srt);
	for(auto p : upper){
		while(u.size() >= 2 && !p.conv(u[u.size()-1], u[u.size()-2])) u.pop_back();
		u.push_back(p);
	}
	for(auto p : lower){
		while(l.size() >= 2 && !p.conv(l[l.size()-1], l[l.size()-2])) l.pop_back();
		l.push_back(p);
	}
	if(u.size()>=2 && l.size()>=2){
		if(u[u.size()-1].x > l[l.size()-1].x) while(l.size()>=2 && !u[u.size()-1].conv(l[l.size()-1], l[l.size()-2])) l.pop_back();
		else while(u.size()>=2 && !l[l.size()-1].conv(u[u.size()-1], u[u.size()-2])) u.pop_back();
	}
	u.insert(u.end(), l.rbegin(), l.rend());
	u.pop_back();
	return u;
}

int main(){}
