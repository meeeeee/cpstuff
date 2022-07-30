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
int anc[mxpow][200000] = {};
vector<int> adj[200000] = {};

void dfs(int curr, int parent){
	anc[0][curr] = parent;
	for(auto x : adj[curr]) if(x != parent) dfs(x, curr);
}

int ancc(int curr, int k){
	for(int a = mxpow; a >= 0; a--) if((k >> a)&1) curr = curr == -1 ? -1 : anc[a][curr];
	return curr;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, r, v1, v2;
	scanf("%d %d", &n, &r);
	for(int a = 0; a < n-1; a++){
		scanf("%d %d", &v1, &v2);
		adj[v1-1].push_back(v2-1);
		adj[v2-1].push_back(v1-1);
	}
	dfs(r-1,-1);
	for(int a = 1; a < mxpow; a++) for(int b = 0; b < n; b++) anc[a][b] = anc[a-1][b] == -1 ? -1 : anc[a-1][anc[a-1][b]];
	for(int a = 0; a < mxpow; a++){
		for(int b = 0; b < n; b++) printf("%d ", anc[a][b]+1);
		printf("\n");
	}
	for(int a = 0; a < n; a++) for(int b = 0; b < n; b++) printf("%d, %d: %d\n", a+1, b, ancc(a,b)+1);
	return 0;
}
/* kth ancestor of tree */
/* T1 (1-rooted tree):
 * 8 1
 * 1 2
 * 1 4
 * 4 3
 * 4 7
 * 7 8
 * 1 5
 * 2 6
 * ---
 * 1 2 3 4 5 6 7 8 
 * 0 1 4 1 1 2 4 7 
 * 0 0 1 0 0 1 1 4 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0 
 * 0 0 0 0 0 0 0 0
 * 1, 0: 1
 * 1, 1: 0
 * 1, 2: 0
 * 1, 3: 0
 * 1, 4: 0
 * 1, 5: 0
 * 1, 6: 0
 * 1, 7: 0
 * 2, 0: 2
 * 2, 1: 1
 * 2, 2: 0
 * 2, 3: 0
 * 2, 4: 0
 * 2, 5: 0
 * 2, 6: 0
 * 2, 7: 0
 * 3, 0: 3
 * 3, 1: 4
 * 3, 2: 1
 * 3, 3: 0
 * 3, 4: 0
 * 3, 5: 0
 * 3, 6: 0
 * 3, 7: 0
 * 4, 0: 4
 * 4, 1: 1
 * 4, 2: 0
 * 4, 3: 0
 * 4, 4: 0
 * 4, 5: 0
 * 4, 6: 0
 * 4, 7: 0
 * 5, 0: 5
 * 5, 1: 1
 * 5, 2: 0
 * 5, 3: 0
 * 5, 4: 0
 * 5, 5: 0
 * 5, 6: 0
 * 5, 7: 0
 * 6, 0: 6
 * 6, 1: 2
 * 6, 2: 1
 * 6, 3: 0
 * 6, 4: 0
 * 6, 5: 0
 * 6, 6: 0
 * 6, 7: 0
 * 7, 0: 7
 * 7, 1: 4
 * 7, 2: 1
 * 7, 3: 0
 * 7, 4: 0
 * 7, 5: 0
 * 7, 6: 0
 * 7, 7: 0
 * 8, 0: 8
 * 8, 1: 7
 * 8, 2: 4
 * 8, 3: 1
 * 8, 4: 0
 * 8, 5: 0
 * 8, 6: 0
 * 8, 7: 0
 */
