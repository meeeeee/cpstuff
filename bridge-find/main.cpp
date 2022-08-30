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
int visited[200000] = {}, dp[200000] = {}, vst = 0;
vector<int> adj[200000] = {};
vector<pii> spann, back, bridges;
bool bridge = false;

void dfs(int curr){
	if(visited[curr]) return;
	visited[curr] = ++vst;
	for(auto x : adj[curr]) dfs(x);
}

void dps(int curr, int parent){
	if(dp[curr]) return;
	dp[curr] = visited[curr];
	for(auto x : adj[curr]){
		if(visited[x] >= visited[parent]) continue;
		dp[curr] = min(dp[curr], visited[x]);
		back.push_back({curr, x});
	}
	for(auto x : adj[curr]){
		if(visited[x] <= visited[curr]) continue;
		dps(x, curr);
		dp[curr] = min(dp[curr], dp[x]);
	}
	spann.push_back({curr, parent});
	if(dp[curr] > visited[parent] && parent != curr){
		bridge = true;
		bridges.push_back({curr, parent});
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, v1, v2;
	scanf("%d %d", &n, &m);
	while(m--){
		scanf("%d %d", &v1, &v2);
		adj[v1-1].push_back(v2-1);
		adj[v2-1].push_back(v1-1);
	}
	dfs(0);
	dps(0,0);
	if(bridge) for(auto x : bridges) printf("%d %d\n", x.second+1, x.first+1);
	else printf("-1\n");
	return 0;
}
// find visiting time for each node
/* T1: tree
 * 3 2
 * 1 2
 * 2 3
 * ---
 * 1 2
 * 2 3
 */
/* T2: 3-ring
 * 3 3
 * 1 2
 * 2 3
 * 3 1
 * ---
 * -1
 */
/* T3: lollipop
 * 3 4
 * 1 2
 * 2 3
 * 3 4
 * 4 2
 * ---
 * 1 2
 */
/* T4: beeg tree
 * 9 8
 * 1 2
 * 1 6
 * 2 4
 * 2 7
 * 4 3
 * 4 5
 * 6 8
 * 8 9
 * ---
 * 1 2
 * 1 6
 * 2 4
 * 2 7
 * 4 3
 * 4 5
 * 6 8
 * 8 9
 */
/* T5: beeg cycle with antennae
 * 9 9
 * 1 2
 * 1 6
 * 2 4
 * 2 7
 * 4 3
 * 4 5
 * 6 8
 * 8 9
 * 3 9
 * ---
 * 2 7
 * 4 5
 */
