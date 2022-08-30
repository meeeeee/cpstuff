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
int depth[200000] = {};
struct lcarmq{
	int first[200000] = {};
	vector<int> euler;

	struct sugTree{
		int n;
		int t[800000] = {};
		sugTree(){}
		void init(int sz, vector<int> arr){n = sz; copy(arr.begin(),arr.end(), t+n); build();}
		void build(){for(int i = n-1; i > 0; i--) t[i] = (depth[t[i<<1]] < depth[t[i<<1|1]] ? t[i<<1] : t[i<<1|1]);}
		int range(int l, int r){ // 0-indexed range inclusive
			r++;
			int res = t[l+n];
			for(l += n, r += n; l < r; l >>= 1, r >>= 1){
				if(l&1 && depth[t[l++]] < depth[res]) res = t[l-1];
				if(r&1 && depth[t[--r]] < depth[res]) res = t[r];
			}
			return res;
		}
	};

	sugTree st;
	void dfs(int curr, int parent, int d){
		euler.push_back(curr);
		if(first[curr] == -1){
			first[curr] = euler.size()-1;
			depth[curr] = d;
		}
		for(auto x : adj[curr]){
			if(x == parent) continue;
			dfs(x, curr, d+1);
			euler.push_back(curr);
		}
	}

	lcarmq(){}
	
	void init(int root = 0){
		memset(first, -1, sizeof(first));
		memset(depth, 0, sizeof(depth));
		euler.clear();
		dfs(root,root,0);
		st.init(euler.size(), euler);
	}

	int lca(int v1, int v2){return st.range(min(first[v1],first[v2]), max(first[v1], first[v2]));}
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	lcarmq lca_;
	int n, q, v1, v2;
	scanf("%d", &n);
	for(int a = 1; a < n; a++){
		scanf("%d %d", &v1, &v2);
		adj[v2-1].push_back(v1-1);
		adj[v1-1].push_back(v2-1);
	}
	lca_.init();
	scanf("%d", &q);
	while(q--){
		scanf("%d %d", &v1, &v2);
		printf("%d\n", 1+lca_.lca(v1-1,v2-1));
	}
	return 0;
}
// actually finds lca in O(log n) by finding depth rmq over first occurrences of each vertex in Euler tour of tree
// T1: CodeForces 1702 G2 - Passable Paths (hard version)
