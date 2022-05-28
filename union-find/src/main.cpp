#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node{ll number, parent, size;};

struct node* newnode(ll val){
	node* no = new node;
	 no -> number = val;
	 no -> parent = val;
	 no -> size = 1;
	return no;
};

class UnionFind{
	public:
		map<ll, node*> nodes;

		UnionFind(vector<ll> inits){for(auto x : inits) nodes[x] = newnode(x);}

		void makeSet(ll val){nodes[val] = newnode(val);}

		void unionSet(ll a, ll b){// Union by size
			if(nodes[a] -> size < nodes[b] -> size) swap(a, b);
			nodes[b] -> parent = a;
			nodes[a] -> size += nodes[b] -> size;
		}

		ll findSet(ll val){
			if(nodes[val] -> parent == val) return val;
			(nodes[val] -> parent) = findSet(nodes[val] -> parent);
			return nodes[val] -> parent;
		}

		bool sameSet(ll a, ll b){return findSet(a) == findSet(b);}
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	return 0;
}