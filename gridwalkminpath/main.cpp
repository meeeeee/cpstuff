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
int t, n, m, dp[10000][10000] = {}, arr[10000][10000] = {};

void dps(int a, int b){
	if(dp[a][b] != INF) return;
	if(a == n-1 && b == m-1){dp[a][b] = arr[a][b]; return;}
	if(a < n-1){dps(a+1,b); dp[a][b] = min(dp[a][b], dp[a+1][b]);}
	if(b < m-1){dps(a,b+1); dp[a][b] = min(dp[a][b], dp[a][b+1]);}
	dp[a][b] += arr[a][b];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(scanf("%d", &t);t--;){
		scanf("%d %d", &n, &m);
		for(int a = 0; a < n; a++) for(int b = 0; b < m; b++) scanf("%d", &arr[a][b]);
		memset(dp, INF, sizeof(dp));
		dps(0,0);
		printf("%d\n", dp[0][0]);
	}
	return 0;
}
/* given a grid of ints, return the smallest value path from the top left node to the bottom right if you can only walk down or to the right every step */
/* T1:
 * 2
 * 3 4
 * 1 2 3 4
 * 5 6 7 8
 * 9 10 11 12
 * 3 3
 * 10 40 30
 * 8 -1 4
 * 50 50 3
 * ---
 * 30
 * 24
 */
