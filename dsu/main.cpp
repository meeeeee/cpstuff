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
	int n, r, tmp1, tmp2;
	string st;
	scanf("%d %d", &n, &r);
	dsu u(n);
	while(r--){
		cin >> st >> tmp1 >> tmp2;
		if(st == "merge") u.merge(tmp1, tmp2);
		else printf(u.eq(tmp1, tmp2) ? "YES\n" : "NO\n");
	}
	return 0;
}
/* test dsu */
/* Test 1 (partitioning numbers into set):
 * 5 7
 * merge 1 4
 * eq 1 4
 * eq 1 2
 * merge 0 4
 * eq 0 4
 * eq 0 1
 * eq 0 2
 * ---
 * YES
 * NO
 * YES
 * YES
 * NO
 */
