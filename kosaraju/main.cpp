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
vector<int> adj[200000] = {}, revadj[200000] = {}, finish(0);
bool visited[200000] = {};
int components[200000] = {}, comp = 0;

void dfs1(int curr){
	if(visited[curr]) return;
	visited[curr] = true;
	for(auto x : adj[curr]) dfs1(x);
	finish.push_back(curr);
}

void dfs2(int curr){
	if(!visited[curr]) return;
	visited[curr] = false;
	components[curr] = comp;
	for(auto x : revadj[curr]) dfs2(x);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, v1, v2;
	scanf("%d %d", &n, &m);
	for(int a = 0; a < m; a++){
		scanf("%d %d", &v1, &v2);
		adj[v1-1].push_back(v2-1);
		revadj[v2-1].push_back(v1-1);
	}
	for(int a = 0; a < n; a++) dfs1(a);
	for(int a = n-1; a >= 0; a--){
		if(!visited[finish[a]]) continue;
		dfs2(finish[a]);
		comp++;
	}
	for(int a = 0; a < n; a++) printf("%d: %d\n", a+1, components[a]);
	return 0;
}
/* kosaraju's algorithm for finding strongly-connected components in linear time */
// dfs on the vertices and add them to a list in order of finishing time, then dfs on the reversed graph in reverse order of finishing time and group all vertices in the same dfs into the same component
/* T1:
 * 7 10
 * 1 2
 * 2 1
 * 1 4
 * 2 5
 * 5 4
 * 3 2
 * 3 7
 * 6 3
 * 7 6
 * 6 5
 * ---
 * 1 1
 * 2 1
 * 3 0
 * 4 3
 * 5 2
 * 6 0
 * 7 0
 */
