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

vector<int> adj[200000] = {}, srt = {};
int proc[200000] = {};

void dfs(int v){
	if(proc[v] == 2) return;
	if(proc[v] == 1){
		fprintf(stderr, "graph contains cycle\n");
		exit(EXIT_FAILURE);
	}
	proc[v] = 1;
	for(auto x : adj[v]) dfs(x);
	proc[v] = 2;
	srt.push_back(v);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, v1, v2;
	scanf("%d %d", &n, &m);
	while(m--){
		scanf("%d %d", &v1, &v2);
		adj[v1-1].push_back(v2-1);
	}
	for(int a = 0; a < n; a++) dfs(a);
	for(int a = srt.size()-1; a >= 0; a--) printf("%d ", srt[a]+1);
	printf("\n");
	return 0;
}
/* topological sort on a graph in linear time */
/* T1 (tree):
 * 7 6
 * 1 2
 * 1 3
 * 2 4
 * 2 5
 * 3 6
 * 3 7
 * ---
 * 1 3 7 6 2 5 4
 */
/* T2a (DAG):
 * 5 6
 * 1 2
 * 1 5
 * 2 4
 * 3 5
 * 4 3
 * 4 5
 * ---
 * 1 2 4 3 5
 */
/* T2b (DAG):
 * 5 6
 * 5 1
 * 5 4
 * 1 3
 * 2 4
 * 3 2
 * 3 4
 * ---
 * 5 1 3 2 4
 */
/* T3 (cyclic graph):
 * 3 3
 * 1 2
 * 2 3
 * 3 1
 * ---
 * stderr "graph contains cycle"
 */
