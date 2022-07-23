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
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, tmp1, tmp2, w;
	scanf("%d %d", &n, &m);
	vector<pii> adj[n] = {};
	for(int a = 0; a < m; a++){
		scanf("%d %d %d", &tmp1, &tmp2, &w);
		adj[tmp1].push_back({tmp2,w});
	}
	int dist[n][n];
	memset(dist, INF, sizeof(dist));
	for(int a = 0; a < n; a++) for(auto v : adj[a]) dist[a][v.first] = v.second;
	for(int a = 0; a < n; a++) dist[a][a] = 0;
	for(int c = 0; c < n; c++) for(int a = 0; a < n; a++) for(int b = 0; b < n; b++) dist[a][b] = min(dist[a][b], dist[a][c] + dist[c][b]);
	for(int a = 0; a < n; a++){
		for(int b = 0; b < n; b++) printf("%d ", dist[a][b]);
		printf("\n");
	}
	return 0;
}
/* Calculate the distance of the shortest path between all pairs of vertices using Floyd-Warshall */
// T1 (undirected graph): 4 8 / 0 1 1 / 1 0 1 / 0 2 2 / 2 0 2 / 1 3 3 / 3 1 3 / 2 3 4 / 3 2 4 ; 0 1 2 4 5 / 1 0 3 3 / 2 3 0 4 / 4 3 4 0
