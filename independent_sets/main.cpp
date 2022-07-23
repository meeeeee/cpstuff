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

pii dfs(int curr, int parent){
	pii d = {1, 1};
	for(auto x : adj[curr]){
		if(x == parent) continue;
		pii tmp = dfs(x, curr);
		d.first *= tmp.second, d.second *= tmp.first + tmp.second;
	}
	return d;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, v1, v2;
	scanf("%d", &n);
	for(int a = 0; a < n-1; a++){
		scanf("%d %d", &v1, &v2);
		adj[v1-1].push_back(v2-1);
		adj[v2-1].push_back(v1-1);
	}
	pii tot = dfs(0,0);
	printf("%d\n", tot.first + tot.second);
	return 0;
}
// find the number of independent sets in a tree
// arbitrarily root tree & maintain the number of independent sets of the subtree rooted at a given vertex containing and not containing the vertex
// this equals a: prod(_b), b: prod(_a+_b) with initial condition a: 1, b: 1
/* T1:
 * 5
 * 1 2
 * 2 3
 * 1 4
 * 3 5
 * ---
 * 13
 */
