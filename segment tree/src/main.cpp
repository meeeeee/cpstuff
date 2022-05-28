#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class SegmentTree{
	vector<ll> tree, presum;
	pair<ll, ll> uval;

	void updateRange(ll s, ll e, ll pos){
		tree[pos] = presum[e] - presum[s - 1];
		if(s != e){
			updateRange(s, (s + e)/2, 2*pos);
			updateRange((s + e)/2 + 1, e, 2*pos + 1);
		}
	}

	ll recurseSum(ll ts, ll te, ll pos, ll s, ll e){
		ll mid = (ts + te)/2;
		if(ts == s && te == e) return tree[pos];
		else return (s <= mid ? recurseSum(ts, mid, 2*pos, s, min(e, mid)) : 0) + (e > mid ? recurseSum(mid + 1, te, 2*pos + 1, max(s, mid + 1), e) : 0);
	}

	void recurseUpdate(ll ts, ll te, ll pos){
		tree[pos] += uval.second;
		if(ts == te);
		else if((ts + te)/2 + 1 <= uval.first && uval.first <= te) recurseUpdate((ts + te)/2 + 1, te, 2*pos + 1);
		else recurseUpdate(ts, (ts + te)/2, 2*pos);
	}

	public:
		SegmentTree(vector<ll> base){
			presum = vector<ll>(1 + base.size(), 0);
			presum[1] = base[0];
			for(int a = 1; a < base.size(); a++) presum[a + 1] = base[a] + presum[a];
			tree = vector<ll>(int(pow(2, 1 + ceil(log2(base.size())))), 0);
			updateRange(1, base.size(), 1);
		}

		ll sumQuery(ll s, ll e){return recurseSum(1, presum.size() - 1, 1, s, e);}

		void updateTree(ll pos, ll val){
			uval.first = pos;
			uval.second = val - presum[pos] + presum[pos - 1];
			recurseUpdate(1, presum.size() - 1, 1);
		}

		void printSeg(){
			for(int a = 1; a < tree.size(); a++){
				if(abs(log2(a) - int(log2(a)) < pow(10, -10))) printf("\n");
				printf("%lld ", tree[a]);
			}
		}
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	SegmentTree test({1, 2, 3, 4, 5});
	test.printSeg();
	for(int a = 1; a <= 5; a++) for(int b = a; b <= 5; b++) printf("%d %d %lld\n", a, b, test.sumQuery(a, b));
	return 0;
}