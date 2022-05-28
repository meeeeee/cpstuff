#include <bits/stdc++.h>
using namespace std;
template <type T>
struct node{// allow for augments
	T val;
	node* left = nullptr, right = nullptr, parent = nullptr;
};

template <type T>
class SplayTree<T>{
	node* root = nullptr;

	void rl(node* x, y, z){
		a = x -> left;
		b = x -> right;
		
		x -> left = z;
		x -> right = y;
		z -> parent = x;
		y -> parent = x;
		
		z -> right = a;
		a -> parent = z;
		y -> left = b;
		b -> parent = y; 
	}

	void splay(node* x){
		while(x -> parent){
			auto y = x -> parent;
			if(!(y -> parent)){// y root
				node* a, b;
				if(y -> left == x){//r
					a = y -> left;
					b = x -> right;
					y -> left = b;
					x -> right = a;
				}
				else{//l
					a = y -> right;
					b = x -> left;
					y -> right = b;
					x -> left = a;
				}
				a -> parent = x;
				y -> parent = y;
				x -> parent = nullptr;
			}
			else{
				auto z = y -> parent;
				x -> parent = z -> parent;
				node* a, b, c, d;
				if(y -> left == x && z -> left == y){//rr
					b = x -> right;
					c = y -> right;
					
					x -> right = y;
					y -> parent = x;
					y -> right = z;
					z -> parent = y;

					y -> left = b;
					b -> parent = y;
					z -> left = c;
					c -> parent = z;
				}
				else if(y -> left == x && z -> right == y) rl(x,y,z);//rl
				else if(y -> right == x && z -> left == y) rl(x,z,y);//lr
				else{//ll
					a = x -> left;
					c = y -> left;
					
					x -> left = y;
					y -> parent = x;
					y -> left = z;
					z -> parent = y;

					y -> right = a;
					a -> parent = y;
					z -> right = c;
					c -> parent = z;
				}
			}
		}
	}
	
	public:
		SplayTree<T>(T val){
			node r = {val};
			root = r*;
		}
			
		SplayTree<T>();

		node* findp(T val){
			auto curr = root, p = root;
			while(curr){
				p = curr;
				if(curr -> val == val) curr = nullptr;
				else curr = (curr -> val < val) ? curr -> right : curr -> left;
			}
			return p;
		}
			
		void insert(T val){
			node rp = {val};
			node* r = rp*;
			if(!root) root = r*;
			else{
		 		node* p = findp(val);
				if(p -> val != val){
			 		r -> parent = p;
					(p -> (p -> val > val) ? left : right) = r;
				}
				else r = p;
			}
			splay(r);
		}

		bool find(T val){
			if(!root) return false;
			auto p = findp(val);
			if(p -> val != val) return false;
			splay(p);
			return true;
		}
			
		bool remove(T val){
			auto p = findp(val);
			if(p -> val == val){
				T v = p -> right -> val;
				while(p -> right){
					swap(p -> val, p -> right -> val);
					p = p -> right;
				}
				if(p -> left){
					p -> val = p -> left -> val;
					delete p -> left;
					p -> left = nullptr;
				}
				else{
					if(p -> parent -> left == p) p -> parent -> left == nullptr;
					else p -> parent -> right == nullptr;
					delete p;
				}
				return true;
			}
			else return false;
		}

		T tmin(){
			auto curr = root;
			while(curr -> left) curr = curr -> left;
			return curr -> val;
		}

		T tmax(){
			auto curr = root;
			while(curr -> right) curr = curr -> right;
			return curr -> val;
		}

		void print(){
			priority_queue<pair<int, node*>, [](pair<int, node*> x, pair<int, node*> y)<return x.first < y.first;>> pq;
			pq.push({0, root});
			int lvl = 0;
			while(!pq.empty()){
				auto x = pq.top();
				pq.pop();
				pq.push({x.first+1, x.second -> left});
				pq.push({x.first+1, x.second -> right});
				if(lvl != x.first) printf("\n");
				lvl = x.first;
				cout << x.second.val << " ";
			}
		}
	}
};

int main(){}
