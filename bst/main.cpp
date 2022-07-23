#include <bits/stdc++.h>
using namespace std;

template<typename T> struct node{
	T val;
	node *p,*l,*r;
	node(T val){this -> val = val;}
	void left(node<T> *left){
		l = left;
		left -> p = this;
	}
	void right(node<T> *right){
		r = right;
		right -> p = this;
	}
};

template<typename T> class BST{
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
		BST(){}
		BST(T val){root = new node<T>(val);}
		bool search(T val){return find(val) -> val == val;}
		void insert(T val){
			node<T> *n = new node<T>(val);
			if(!root) root = n;
			else{
				auto pr = find(val);
				if(pr -> val != val) (pr -> val > val) ? pr -> left(n) : pr -> right(n);
			}
		}
		bool del(T val){
			auto pr = find(val);
			if(pr -> val != val) return false;
			node<T> *curr = pr;
			for(; curr -> r; curr = curr -> r) curr -> val = curr -> r -> val;
			if(curr -> l) curr -> p -> right(curr -> l);
			else curr -> p -> r = nullptr;
			return true;
		}
};

int main(){}
