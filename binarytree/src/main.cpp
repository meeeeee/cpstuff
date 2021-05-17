#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

struct node{
	ll number;
	node *child1, *child2, *parent;
};

struct node* newnode(ll val){
	node* no = new node;
	 no -> number = val;
	 no -> child1 = nullptr;
	 no -> child2 = nullptr;
	 no -> parent = nullptr;
	return no;
};

class BinaryTree{
	node* createNode(node* child1, node* child2, ll val){
		node* no = newnode(val);
		no -> child1 = child1;
		no -> child2 = child2;
		no -> parent = nullptr;
		return no;
	}
	
	public:
		vector<vector<node*>> nodes;
		
		BinaryTree(vector<ll> children, ll n){
			nodes = vector<vector<node*>>(n + 1, vector<node*>(0, newnode(0)));
			for(auto x : children) nodes[0].push_back(newnode(x));
			for(ll a = 1; a < nodes.size(); a++){
				for(ll b = 0; b < nodes[a - 1].size()/2; b++){
					
				}
			}
		}
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	return 0;
}