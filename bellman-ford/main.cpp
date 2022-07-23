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

int main(){
	int n, m, src, tmp1, tmp2, w;
	scanf("%d %d %d", &n, &m, &src);
	vector<pii> adj[n] = {};
	for(int a = 0; a < m; a++){
		scanf("%d %d %d", &tmp1, &tmp2, &w);
		adj[tmp1].push_back({tmp2, w});
	}
	int dist[n];
	memset(dist, INF, sizeof(dist));
	dist[src] = 0;
	for(int _ = 0; _ < n-1; _++) for(int a = 0; a < n; a++) for(auto e : adj[a]) dist[e.first] = min(dist[e.first], dist[a] + e.second); // adjust distances n-1 times
	for(int a = 0; a < n; a++) for(auto e : adj[a]) if(dist[e.first] > dist[a] + e.second){printf("negative-weight cycle"); break;}// negative-weight cycle check
	for(int a = 0; a < n; a++) printf("%d ", dist[a]);
	return 0;
}
/* Bellman-Ford implementation*/
// T1 (tree): 5 4 0 / 0 1 1 / 0 2 2 / 1 3 3 / 1 4 4 ; 0 1 2 4 5
// T2 (undirected graph): 4 8 0 / 0 1 1 / 1 0 1 / 0 2 2 / 2 0 2 / 1 3 3 / 3 1 3 / 2 3 4 / 3 2 4 ; 0 1 2 4
// T3 (directed graph): 4 5 1 / 1 0 1 / 1 3 2 / 0 3 7 / 0 2 8 / 3 2 4 ; 1 0 6 2
