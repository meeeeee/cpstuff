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
vector<int> adj[200000] = {};

pii dfs(int curr, int par){
	int l = 0, v = curr;
	for(auto x : adj[curr]){
		if(x == par) continue;
		auto d = dfs(x, curr);
		if(l < d.first){l = d.first, v = d.second;}
	}
	return {l+1, v};
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, v1, v2;
	scanf("%d", &n);
	for(int a = 0; a < n-1; a++){ // m = n - 1
		scanf("%d %d", &v1, &v2);
		adj[v1 - 1].push_back(v2 -1); adj[v2 - 1].push_back(v1 - 1);
	}
	int mxv = dfs(0, 0).second;
	printf("%d %d\n", mxv, dfs(mxv, mxv).first - 1);
	return 0;
}
/* calculate tree diameter by choosing an arbitrary vertex, finding the farthest vertex from it and finding the maximum distance from this second vertex to any other vertex in the tree*/
/* T1:
 * 3
 * 1 2
 * 2 3
 * ---
 * 3 2
 */
/* T2:
 * 8
 * 1 2
 * 1 3
 * 2 4
 * 2 5
 * 3 7
 * 5 6
 * 7 8
 * ---
 * 6 6
 */
