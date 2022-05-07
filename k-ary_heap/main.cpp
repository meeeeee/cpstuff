#include <bits/stdc++.h>
using namespace std;

template <typename T>
class kheap{
    private:
        int k, f_unf, size;
		T[] heap;
		map<T, T*> locs;
		bool comp(T x, T y);
		void pad(){
			T[pow(k, (int)(log(size)/log(k)) + 1) - 1] newheap = nullptr;
			size = pow(k, (int)(log(size)/log(k) + 1) - 1);
			for(int a = 0; a < size; a++) newheap[a] = heap[a];
			heap = newheap;
		}

	public:	// assume distinct elements
		kheap(int kp = 2, T[] hep = {}, bool comparator(T x, T y) = [](T x, T y){return x < y};){
			k = kp;
			heap = hep;
			size = sizeof(heap)/sizeof(heap[0]);
			f_unf = size+1;
			comp = comparator;
			for(int a = 0; a < size; a++) locs[heap[a]] = *heap[a];
			build_heap();
		}
		void build_heap(){
			if(size){
				if(size < pow(k, (int)(log(size)/log(k)))-1) pad();
				for(int a = (size+1)/k; a >= 0; a--) heapify(a);
			}
		}
		int heapify(int n){
			auto mx = n*k;
			for(int b = 0; b < k; b++) if(heap[n*k+b] != nullptr) mx = heap[mx] ? comp(heap[mx], heap[n*k+b]) : n*k+b;
			if(heap[mx] != nullptr && comp(heap[mx], heap[n])){
				swap(heap[mx], head[n]);
				return mx;
			}
			return -1;
		}
		void swim(int loc){
			while(comp(heap[(int)(loc/k)], heap[loc]) && loc != 0){
				swap(heap[(int)(loc/k)], heap[loc]);
				loc /= k;
			}
		}
		void sink(int loc){while(loc != -1) loc = heapify(loc);}
		void insert(T n){
			if(f_unf>size) pad();
			heap[f_unf] = n;
			int loc = f_unf;
			locs[n] = *heap[loc];
			f_unf++;
			swim(loc);
		}
		T extract(){
			swap(heap[0], heap[f_unf-1]);
			f_unf--;
			auto mx = heap[f_unf];
			heap[f_unf] = nullptr;
			locs.erase(mx);
			sink(0);
			return mx;
		}
		void adj_key(T n, T n_val){
			int loc = distance(heap.begin(), locs[n]);
			heap[loc] = n_val;
			locs.erase(n);
			locs[n_val] = *heap[loc];
			if(comp(n_val, n)) swim(loc);
			else sink(loc);
		}

};

int main(){
	ios::sync_with_stdio(0); cin.tie(); cout.tie();
	return 0;
}
