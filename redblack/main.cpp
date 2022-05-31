#include <bits/stdc++.h>
using namespace std;

#define red 0
#define black 1

template<typename T> struct node{
	T val;
	node *p,*l,*r;
	bool color = red;
	node(){}
	node(T val){this -> val = val;}
	void left(node<T> *left){
		l = left;
		left -> p = this;
	}
	void right(node<T> *right){
		r = right;
		right -> p = this;
	}
	void lr(){
		node<T> *rlr = r;
		r -> p = p;
		r = r -> l;
		rlr -> left(this);
	}
	void rr(){
		node<T> *llr = l;
		l -> p = p;
		l = l -> r;
		llr -> right(this);
	}
	void swp(node<T> *n){
	  swap(val, n -> val);
		swap(p, n -> p);
		swap(l, n -> l);
		swap(r, n -> r);
	}
};

template<typename T> class RedBlack{
	node<T> *root = nullptr;
	node<T> *find(T val){
		node<T> *curr = root;
		while(curr -> val != val){
			if (curr -> val >= val && curr -> l) curr = curr -> l;
			else if(curr -> val < val && curr -> r) curr = curr -> r;
			else break;
		}
		return curr;
	}
	public:
		RedBlack(){
			root = new node<T>;
			root -> p = root;
			root -> color = black;
		}
		RedBlack(T val){
			root = new node<T>(val);
			root -> p = root;
			root -> color = black;
		}
		bool search(T val){return find(val) -> val == val;}
		void insert(T val){
			node<T> *n = new node<T>(val);
			if(!root) root = n;
			else{
				auto x = find(val);
				if(x -> val != val){
					if(x -> val > val){
						x -> left(n);
						x = x -> l;
					}
					else{
						x -> right(n);
						x = x -> r;
					}
				}
				while(x -> p -> color == red){
					if(x -> p == x -> p -> p -> l){
						node<T> *y = x -> p -> p -> r;
						if(y -> color == red){
							x -> p -> color = black;
							y -> color = black;
							x -> p -> p -> color = red;
							x = x -> p -> p;
						}
						else if(x == x -> p -> r){
							x = x -> p;
							x -> lr();
							x -> p -> color = black;
							x -> p -> p -> color = red;
							x -> p -> p -> rr();
						}
					}
				}
			}
			root -> color = black;
		}
		bool del(T val){
			auto x = find(val);
			if(x -> val != val) return false;
			node<T> *xp = nullptr;
			bool fix = x -> color == black, dmor = true;
			while(x -> r){
				if(x -> r -> l){
					if(!xp) xp = x -> r -> l;
					x -> swp(x -> r -> l);
				}
				else{
					if(!xp) xp = x -> r;
					if(x -> val > x -> p -> val) x -> p -> right(x -> r -> p);
					else x -> p -> left(x -> r -> p);
					break;
				}

			}
			if(dmor && x -> l){
				if(x -> val > x -> p -> val) x -> p -> right(x -> l);
				else x -> p -> left(x -> l);
			}
			if(fix){
				if(!xp) xp = x -> p;
				while(xp != root && xp -> color == black){
					node<T> *w = xp -> p -> r;
					if(xp == xp -> p -> l){
						w -> color = black;
						x -> p -> color = red;
						x -> p -> lr();
						w = xp -> p -> r;
					}
					if(w -> l -> color == black && w -> r -> color == black){
						w -> color = red;
						xp = xp -> p;
					}
					else if(w -> r -> color == black){
						w -> l -> color = black;
						w -> color = red;
						w -> rr();
						w -> color = xp -> p -> color;
						xp -> p -> color = black;
						w -> r -> color = black;
						xp -> p -> lr();
						xp = root;
					}
				}
				xp -> color = black;
			}
			return true;
		}
};

int main(){}
