#include <bits/stdc++.h>

using namespace std;

template<typename T> vector<int> slaeSolve(T in){
	vector<int> sol(sizeof(in[0])/sizeof(in[0][0]), 1);
	int temp;
	for(int a = 0; a < sizeof(in)/sizeof(in[0]); a++){
		for(int b = 0; b < sizeof(in[0])/sizeof(in[0][0]); b++){
			in[a][b] /= double(in[a][a]);
			sol[a] /= double(in[a][a]);

		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	return 0;
}