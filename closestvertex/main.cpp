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
int depth[200000] = {}, v[200000] = {}, mxd = 0;
vector<int> adj[200000] = {};

void dfs(int curr, int parent, int dpth){
	depth[dpth] = max(depth[dpth], v[curr]);
	mxd = max(mxd, dpth);
	for(auto x : adj[curr]){
		if(x == parent) continue;
		dfs(x, curr, dpth+1);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q, v1, v2;
	scanf("%d %d", &n, &q);
	for(int a = 0; a < n; a++) scanf("%d", &v[a]);
	for(int a = 0; a < n-1; a++){
		scanf("%d %d", &v1, &v2);
		adj[v1-1].push_back(v2-1);
		adj[v2-1].push_back(v1-1);
	}
	dfs(0, 0, 0);
	while(q--){
		scanf("%d", &v1);
		auto it = lower_bound(depth, depth+mxd, v1);
		pii tmp = (it == depth+mxd+1 ? (pii){-1,-1} : (pii){distance(depth, it), *it});
		printf("%d %d\n", tmp.first, tmp.second); 
	}
	return 0;
}
/* given a nonnegative min heap, find for q queries the closest vertex to the root geq the query value*/
// maintain a list of maximum vertex value per depth --- this is guaranteed to be non-decreasing --- then binary search on this array
/* T1:
 * 5 3
 * 1 2 3 4 5
 * 1 2
 * 2 3
 * 1 4
 * 3 5
 * 1
 * 2
 * 5
 * ---
 * 0 1
 * 1 4
 * 2 5
 */
