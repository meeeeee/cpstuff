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
const int mxpow = 20;
int anc[mxpow][200000] = {}, depth[200000] = {};
vector<int> adj[200000] = {};

void dfs(int curr, int parent, int dpth){
	anc[0][curr] = parent;
	depth[curr] = dpth;
	for(auto x : adj[curr]) if(x != parent) dfs(x, curr, dpth+1);
}

int ancc(int curr, int k){
	for(int a = mxpow; a >= 0; a--) if((k >> a)&1) curr = curr == -1 ? -1 : anc[a][curr];
	return curr;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, r, q, v1, v2;
	scanf("%d %d %d", &n, &r, &q);
	for(int a = 0; a < n-1; a++){
		scanf("%d %d", &v1, &v2);
		adj[v1-1].push_back(v2-1);
		adj[v2-1].push_back(v1-1);
	}
	dfs(r-1,-1,0);
	for(int a = 1; a < mxpow; a++) for(int b = 0; b < n; b++) anc[a][b] = anc[a-1][b] == -1 ? -1 : anc[a-1][anc[a-1][b]];
	for(int a = 0; a < q; a++){
		scanf("%d %d", &v1, &v2);
		int md = min(depth[v1-1], depth[v2-1]);
		v1 = ancc(v1-1, depth[v1-1] - md), v2 = ancc(v2-1, depth[v2-1] - md);
		while(v1 != v2)	v1 = ancc(v1,1), v2 = ancc(v2,1);
		printf("%d %d\n", v1+1, depth[v1]);
	}
	return 0;
}
/* calculate lca of two vertices by comparing kth ancestors */
/* T1
 * 8 1 4
 * 1 2
 * 1 3
 * 1 4
 * 2 5
 * 2 6
 * 6 8
 * 4 7
 * 5 6
 * 5 8
 * 2 7
 * 6 2
 * ---
 * 2 1
 * 2 1
 * 1 0
 * 2 1
 */
