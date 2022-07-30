#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef unsigned long long ll;

unordered_map<char, uint> mp;
const ll p = 31, mod = 1e9 + 9;

ll binex(ll a, ll b, ll m){
	ll ans=1;
	while(b){
		if(b&1) ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

ll shash(string st){ // rolling variable-string hash
	ll hsh = 0;
	for(int a = 0; a < (int)st.size(); a++) hsh = (hsh + (ll)mp[st[a]]*binex(p, a, mod))%mod;
	return hsh;
}

struct triple{
	string st;
	int cnt;
	ll hash;
	triple(){}
	triple(string ist, int icnt):st(ist),cnt(icnt),hash(shash(ist)){}
};
typedef set<triple, decltype([](triple a, triple b){return a.hash > b.hash;})> sett; // reverse comparator to get largest element not greater than

ll trie[1000][26][26] = {};
int k;
sett autocmpl[1000][26][26], emptyset;

bool chk(str s){ // checks if s has previously been processed
	uint prev = 0;
	for(int a = 0; a < (int)s.size(); prev = mp[s[a]], a++) if(!mp.count(s[a]) || !trie[a][prev][mp[s[a]]]) return false;
	return true;
}

sett traverse(string s){ // return the set associated with the last edge
	if(s.size() == 0 || !mp.count(s[s.size()-1])) return emptyset;
	else if(s.size() == 1 || !mp.count(s[s.size()-2])) return autocmpl[0][0][mp[s[s.size()-1]]];
	else return autocmpl[s.size()-1][mp[s[s.size()-2]]][mp[s.size()-1]];
}

void ins(triple s, sett *st){ // helper function to update edge sets
	if(st -> begin() -> cnt > s.cnt){
		if((int)st -> size() < k) st -> insert(s);
	}
	else{
		st -> erase(st -> lower_bound(s));
		st -> insert(s);
	}
}

void insert(string s){ // update edge counts and update each edge set
	if(s.size() == 0) return;
	uint prev = 0;
	triple *tmp;
	for(int a = 0; a < (int)s.size(); prev = mp[s[a]], a++){
		if(!mp.count(s[a])) return;
		trie[a][prev][mp[s[a]]]++;
		if(a == (int)(s.size()-1)) tmp = new triple(s, trie[a][prev][mp[s[a]]]);
	}
	prev = 0;
	for(int a = 0; a < (int)s.size(); prev = mp[s[a]], a++) ins(*tmp, &(autocmpl[a][prev][mp[s[a]]]));
}

int main(){
	int n;
	str st;
	cin >> n >> k >> st;
	for(int a = 0; a < (int)st.size(); a++) mp[st[a]] = a;
	while(n--){
		cin >> st;
		for(auto x : traverse(st)) cout << x.st << " ";
		cout << endl;
		insert(st);
	}
	return 0;
}
/* prefix tree/trie --- maintain an array with maximum string size by alphabet size, initialize to 1, traverse nodes by incrementing array position & checking if the next character exists if the kth bit of the number is 1 (note that the array type must contain at least as many bits as there are characters in the alphabet; rather than using a uint or ull, we can use a bitset) */
/* maintain a number for each node containing the number of times the node has been visited, increment each node in the prefix and accordingly update the k most-visited elements in each node (nlogk to update and constant time to get autocomplete suggestions) */
/* maintain the number of times a vertex has been visited as an int array; also maintain a set array with size at most k that contains the string, the number of occurrences of the string, and the hash of the string
 * we can find an element in logk by binary searching to find the hash of a string and replacing if the string exists
 * two arrays: traversal array (traverse when searching in Theta(n) and update similarly in Theta(n)) and set array (traverse as you traverse traversal array and return the k largest elements in Theta(k), update in Theta(logk) per edge)
 * traversal is done trivially in the forward direction by iterating over edges and outputting all of the elements stored in the last edge set, done in Theta(n+k) per string (we repeat this process per string regardless of character insertions or deletions as they can be arbitrary)
 * updating is done by traversing the string in the edge array, updating the final count (if we want prefixes to be distinct from words, we only update the final count; otherwise, we update the count of each prefix as well --- update prefix counts), then iterating over the array again and updating each edge set in O(logk) by checking if the smallest element is greater than the word; if so, we only add the word if the size of the set is less than k, and if not we lower_bound on the hash (we assume the hash produces collisions negligibly frequently) and if we find the hash, we remove the string and replace it with the new word; otherwise, we remove the smallest element and replace it with the new word. We repeat this process at each character to update in O(nlogk).
 * does not return the most-frequently seen strings that match the current string but rather the most-frequently seen suffixes that contain the final edge
 */
/* supports checking if a string or prefix exists and adding it to the trie in \Theta(n) */
/* T1 (lowercase alphabet)
 * 10 5 abcde
 * a
 * b
 * a
 * ab
 * abcde
 * ab
 * ac
 * abcd
 * b
 * bcd
 * ---
 * NO
 * NO
 * YES
 * NO
 * NO
 * YES
 * NO
 * YES
 * YES
 * NO
 */
