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
int ind[200000] = {}, sub[200000] = {}, arr[200000] = {}, arrr[200000] = {}; 
vector<int> adj[200000] = {}, dfsi(0);

template <class T> struct segTree{
	int n;
	T t[400000] = {};
	segTree(int sz, T ar[]):n(sz){memcpy(t + sz, arr, sz*sizeof(ar[0])); build();}
	void build(){for(int i = n-1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];}
	void set(int p, T val){for(t[p += n] = val; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];} // 0-indexed stab
	T range(int l, int r){ // 0-indexed range inclusive
		r++;
		T res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l&1) res += t[l++];
			if(r&1) res += t[--r];
		}
		return res;
	}
};

int dfs(int curr, int parent){
	dfsi.push_back(curr);
	int sz = 1;
	/* if(curr != parent) arr[curr] += arr[parent]; */// for path queries
	for(auto x : adj[curr]) if(x != parent) sz += dfs(x, curr);
	sub[curr] = sz;
	return sz;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, r, q, v1, v2;
	scanf("%d %d %d", &n, &r, &q);
	for(int a = 0; a < n; a++) scanf("%d", &arrr[a]);
	for(int a = 0; a < n-1; a++){
		scanf("%d %d", &v1, &v2);
		adj[v1-1].push_back(v2-1);
		adj[v2-1].push_back(v1-1);
	}
	dfs(r-1,r-1);
	for(int a = 0; a < n; a++) ind[dfsi[a]] = a;
	for(int a = 0; a < n; a++) arr[ind[a]] = arrr[a];
	segTree<int> vals(n, arr);
	for(int a = 0; a < n; a++) printf("\n%d: %d", a+1, vals.range(ind[a], ind[a]+sub[a]-1)); //for subtree queries
	/* for(int a = 0; a < n; a++) printf("\n%d: %d", a+1, vals.range(ind[a], ind[a])); */// for path queries
	return 0;
}
/* subtree and path queries using dfs arrays and segtrees */
/* maintain a dfs index array, and subtree size array; on top of this, maintain a value array per node in a segtree; update individual values by updating the range starting at the node and ending at the subtree */
// NOTE: node updates are not currently supported because my segtree doesn't have lazy propagation yet
/* T1:
 * 5 1 0
 * 1 2 3 4 5
 * 1 2
 * 1 3
 * 2 4
 * 2 5
 * ---
 * 1: 15
 * 2: 11
 * 3: 3
 * 4: 4
 * 5: 5
 */
