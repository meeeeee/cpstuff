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

template <class T> struct segTree{
	int n;
	T t[400000] = {};
	segTree(int sz, T arr[]):n(sz){memcpy(t + sz, arr, sz*sizeof(arr[0])); build();}
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

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q, x, y;
	scanf("%d %d", &n, &q);
	ll arr[n];
	for(int a = 0; a < n; a++) scanf("%lld", &arr[a]);
	segTree<ll> st(n, arr);
	while(q--){
		scanf("%d %d %d", &n, &x, &y);
		if(n == 1) st.set(x-1, y);
		else printf("%lld\n", st.range(x-1,y-1));
	}
	return 0;
}
