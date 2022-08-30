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
template <
    class result_t   = std::chrono::milliseconds,
    class clock_t    = std::chrono::steady_clock,
    class duration_t = std::chrono::milliseconds
>
auto since(std::chrono::time_point<clock_t, duration_t> const& start)
{
    return std::chrono::duration_cast<result_t>(clock_t::now() - start);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, b, k;
	scanf("%d", &n);
	int arr[n];
	for(int a = 0; a < n; a++) arr[a] = n - a;
	//for(int a = 0; a < n; a++) scanf("%d", &arr[a]);
	auto start = chrono::steady_clock::now();
	for(int a = 1; a < n; arr[b] = k, a++){
		k = arr[a];
		for(b = a; b >= 0 && arr[b] >= k; b--);
		b++;
		for(int c = a; c > b; c--) arr[c] = arr[c-1];
	}
	auto end = since(start).count();
	printf("%ld\n", end);
	//for(int a = 0; a < n; a++) printf("%d ", arr[a]);
	return 0;
}
