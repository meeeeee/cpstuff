#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;
typedef long double ld;

ll maxDepth, samples, endVertex, prec;
ld vCount = 0;


double randDouble(){return double(rand()%(prec - 1) + 0.9999)/double(prec);}

struct vertex{
	int vertexNum;
	double weight;
	vertex* nextVertex;
};

struct edge{
	int tail, head;
	double prob;
};

class Digraph{
	vertex* adjacencyList(int tail, double prob, vertex* head){
		vertex* nvert = new vertex;
		nvert -> vertexNum = tail;
		nvert -> weight = prob;
		nvert -> nextVertex = head;
		return nvert;
	}
	
	public:
		int vertices;
		vertex** heads;
		
		Digraph(vector<edge> edgeSet, int vertices){
			heads = new vertex*[vertices]();
			this -> vertices = vertices;
			for(int a = 1; a <= vertices; a++) heads[a] = nullptr;
			for(auto x : edgeSet) heads[x.tail] = adjacencyList(x.head, x.prob, heads[x.tail]);
		}

		void printEdges(){
			for(int a = 1; a <= vertices; a++){
				printf("%d:", a);
				for(vertex* b = heads[a]; b != nullptr; b = b -> nextVertex) printf(" %d -> %f", b -> vertexNum, b -> weight);
				printf("\n");
			}
		}

		int jumpFrom(int vertexNum){
			vector<pair<double, int>> w = {{0.0, 0}};
			for(vertex* a = heads[vertexNum]; a != nullptr; a = a -> nextVertex) w.push_back({w[w.size() - 1].first + (a -> weight), a -> vertexNum});
			return lower_bound(w.begin(), w.end(), pair<double, int>{randDouble(), 0}) -> second;
		}

		void randomWalk(int startVertex, int length){
			if(length == 1) vCount += ((startVertex == endVertex) ? 1.0 : 0.0)/double(pow(2, maxDepth - 1));
			else{
				vCount += ((startVertex == endVertex) ? 1.0 : 0.0)/double(pow(2, maxDepth - length + 1));
				randomWalk(jumpFrom(startVertex), length - 1);
			}
		}
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	srand(time(NULL));
	maxDepth = 10;
	samples = pow(10, 7);
	endVertex = 5;
	prec = pow(10, 5);
	vector<edge> edgeSet({{1, 2, 0.5}, {1, 3, 0.5}, {2, 1, 0.3}, {2, 3, 0.2}, {2, 5, 0.4}, {2, 6, 0.1}, {3, 1, 0.7}, {3, 4, 0.2}, {3, 5, 0.1}, {4, 3, 1.0}, {5, 2, 0.5}, {5, 3, 0.3}, {5, 6, 0.2}, {6, 2, 1.0}});
	Digraph maze(edgeSet, 6);
	maze.printEdges();
	for(ll a = 0; a < samples; a++) maze.randomWalk(maze.jumpFrom(1), maxDepth);
	printf("%Lf", vCount);
	return 0;
}