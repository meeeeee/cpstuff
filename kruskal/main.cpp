#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef string str;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
struct tii{int first, second, weight;};
vector<tii> edges = {}, mst = {};

struct dsu{
	vector<pii> szpred; // size-predecessor pairs
	dsu(int n):szpred(n){for(int a = 0; a < n; a++) szpred[a] = {0, a};}
	int find(int a){return (a == szpred[a].second) ? a : szpred[a].second = find(szpred[a].second);} // path compression
	void merge(int a, int b){ // union by size
		a = find(a), b = find(b);
		if(a == b) return;
		if(szpred[a].first < szpred[b].first) swap(a, b);
		szpred[b].second = a;
		szpred[a].first += szpred[b].first;
	}
	bool eq(int a, int b){return find(a) == find(b);}
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, v1, v2, w;
	scanf("%d %d", &n, &m);
	dsu d(n);
	while(m--){
		scanf("%d %d %d", &v1, &v2, &w);
		edges.push_back({v1-1, v2-1, w});
	}
	sort(edges.begin(), edges.end(), [](tii a, tii b){return a.weight < b.weight;});
	for(auto x : edges){
		if(d.eq(x.first, x.second)) continue;
		mst.push_back(x);
		d.merge(x.first, x.second);
	}
	for(auto x : mst) printf("{%d %d %d} ", x.first + 1, x.second + 1, x.weight);
	printf("\n");
	return 0;
}
/* Kruskal's algorithm for finding an MST in a graph */
/* T1:
 * 4 6
 * 1 2 1
 * 1 3 5
 * 2 4 2
 * 1 4 6
 * 3 2 4
 * 3 4 3
 * ---
 * {1 2 1} {2 4 2} {3 4 3}
 */
