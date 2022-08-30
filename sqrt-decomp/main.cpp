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
static const int asz = 200000, sqasz = 500;

struct sqrt_dec{
    ll blksz, blks[sqasz] = {}, blkq[sqasz] = {}, arr_[asz];
    
    sqrt_dec(int ar[], int blksztot){
        blksz = (int)(sqrt(blksztot + 0.1));
        for(int a = 0; a < blksztot; a++) blks[a/blksz] += ar[a];
        for(int a = 0; a < blksztot; a++) arr_[a] = ar[a];
    }

    void update(int l, int r, int u){
        int l_ = l/blksz, r_ = r/blksz;
        if(l_ == r_) for(int a = l; a <= r; a++){
            arr_[a] += u;
            blks[l_] += u;
        }
        else{
            for(int a = l_+1; a < r_; a++){
                blks[a] += blksz*u;
                blkq[a] += u;
            }
            for(int a = l; a < blksz*(l_+1); a++){
                arr_[a] += u-blkq[l_];
                blks[l_] += u-blkq[l_];
            }
            for(int a = blksz*r_; a <= r; a++){
                arr_[a] += u-blkq[r_];
                blks[r_] += u-blkq[r_];
            }
        }
    }

    ll sum(int l, int r){
        ll tot = 0;
        int l_ = l/blksz, r_ = r/blksz;
        if(l_ == r_) for(int a = l; a <= r; a++) tot += arr_[a] + blkq[l_];
        else{
            for(int a = l_+1; a < r_; a++) tot += blks[a];
            for(int a = l; a < blksz*(l_+1); a++) tot += arr_[a] + blkq[l_];
            for(int a = blksz*r_; a <= r; a++) tot += arr_[a] + blkq[r_];
        }
        return tot;
    }
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, l, r, u;
    scanf("%d %d", &n, &m);
    int arr[n];
    for(int a = 0; a < n; a++) scanf("%d", &arr[a]);
    sqrt_dec sqd(arr, n);
    for(int a = 0; a < m; a++){
        scanf("%d %d %d", &l, &r, &u);
        sqd.update(l-1, r-1, u);
        printf("%lld\n",  sqd.sum(l-1, r-1));
    }
    return 0;
}
// split array into sqrtn-sized blocks & update and query inclusive ranges by iterating over their sqrt blocks; block updates are constants on individual blocks while array updates are constants on the array itself; the sum array is distinct from the block update array
/* T1:
4 4
1 2 3 4
1 3 2
2 3 4
1 4 0
1 1 5
---
12
17
24
8
 */
/* T2:
5 4
1 2 3 4 4
1 3 2
2 3 4
1 4 0
1 1 5
---
12
17
24
8
 */
/* T3:
10 7
1 4 3 2 8 7 9 1 3 10
3 4 8
4 9 7
1 1 4
4 4 -9
1 10 8
2 10 -8
1 1 0
---
21
80
5
8
181
96
13
 */
