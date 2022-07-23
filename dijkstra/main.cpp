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
		scanf("%d %d %d", &tmp1, &tmp2, &w); // directed edges
		adj[tmp1].push_back({tmp2, w});
	}
	int dist[n];
	bool check[n] = {};
	memset(dist, INF, sizeof(dist));
	dist[src] = 0;
	priority_queue<pii, vector<pii>, decltype([](pii a, pii b){return a.second > b.second;})> pq; // vertex and distance
	pq.push({src, 0}); // push source
	while(!pq.empty()){ // keep removing smallest vertex if unvisited and updating neighbors if neighbor distance is greater than vertex distance plus edge weight
		tmp1 = pq.top().first; pq.pop();
		if(check[tmp1]) continue;
		check[tmp1] = true;
		for(auto e : adj[tmp1]){
			if(dist[e.first] > tmp2 + e.second){
				dist[e.first] = dist[tmp1] + e.second; // update distance
				pq.push({e.first, dist[tmp1] + e.second}); // add to pq
			}
		}
	}
	for(int a = 0; a < n; a++) printf("%d ", dist[a]);
	return 0;
}
/* Calculate the distance of the shortest path from a given source to each vertex in the graph with Dijkstra's */
/* T1 (tree):
 * 5 4 0
 * 0 1 1
 * 0 2 2
 * 1 3 3
 * 1 4 4
 * ---
 *  0 1 2 4 5
 */
/* T2 (undirected graph):
 * 4 8 0
 * 0 1 1
 * 1 0 1
 * 0 2 2
 * 2 0 2
 * 1 3 3
 * 3 1 3
 * 2 3 4
 * 3 2 4
 * ---
 *  0 1 2 4
 */
/* T3 (directed graph):
 * 4 5 1
 * 1 0 1
 * 1 3 2
 * 0 3 7
 * 0 2 8
 * 3 2 4
 * ---
 *  1 0 6 2
 */
