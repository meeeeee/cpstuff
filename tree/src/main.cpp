#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

struct node{
	ll number;
	vector<node*> child;
	node* parent;
};

struct node* newnode(ll val){
	node* no = new node;
	 no -> number = val;
	 no -> parent = nullptr;
	return no;
};

class Tree{
	node* createNode(vector<node*> child, ll val){
		node* no = newnode(val);
		no -> child = child;
		no -> parent = nullptr;
		return no;
	}

	node* createNode(vector<node*> child, node* parent, ll val){
		node* no = newnode(val);
		no -> child = child;
		no -> parent = parent;
		return no;
	}
	
	public:
		vector<vector<node*>> nodes;
		
		Tree(vector<ll> children){
			nodes = vector<vector<node*>>(0, vector<node*>(0, newnode(0)));
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