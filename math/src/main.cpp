#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

template<typename T>
T sq(T base){return base*base;}

ll binex(ll base, ll sup){// Recursive binary exponentiation
	if(sup == 1) return base;
	else if(sup%2 == 0) return sq(binex(base, sup/2));
	else return base*sq(binex(base, sup/2));
}

ll binex(ll base, ll sup, ll mod){// Recursive modular binary exponentiation
	if(sup == 1) return base%mod;
	else if(sup%2 == 0) return sq(binex(base, sup/2, mod))%mod;
	else return (base*sq(binex(base, sup/2, mod)))%mod;
}

ll euc(ll a, ll b){// Euclidean for GCF
	if(a > b) swap(a, b);
	while(b > 0){
		a %= b;
		swap(a, b);
	}
	return a;
}

ll lcm(ll a, ll b){// LCM
	return a*(b/euc(a, b));
}

bool primality(ll num){// Prime test
	ll sr = ceil(sqrt(num));
    if(num == 1 || num == 2 || num == 3 || num%2 == 0 || num%3 == 0) return false;
    for(ll a = 5; a <= sr; a += 6) if(num%a == 0 || num%(a + 2) == 0) return false;
	return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	return 0;
}