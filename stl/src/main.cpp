#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b){return a > b;}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//VECTOR - dynamic array
	vector<int> v = {34, 1, 2, 43}; // Initialize vector
	printf("%d ", v[3]); // Indexed referencing
	v.push_back(33); // Add element to vector
	sort(v.begin(), v.end()); // Sort with vectors
	binary_search(v.begin(), v.end(), 1); // Binary search on sorted array for element 1
	vector<int>::iterator low = lower_bound(v.begin(), v.end(), 33); // First element greater than or equal to 33
	auto high = upper_bound(v.begin(), v.end(), 33); // First element greater than 33; use auto for types with long names
	int diff = *high - *low; // Difference between element greater than 33 and 33
	int num = high - low - 1; // Count of number of elements equal to 33
	sort(v.begin(), v.end(), comp); // Custom sort comparator
	for(auto &x : v) x++; // Modify through for loop by referencing address

	//SET - ordered simple set
	set<int> s = {3, 4}; // Initialize set
	s.insert(1); // Add to set
	auto x = s.find(0); // Returns s.end() if not present
	// You can also use upper_bound and lower_bound for set but as a function of s because they're implemented as set functions. If there is no element greater than or equal to the element, it will return the end iterator
	
	//MAP - stores key and value
	map<int, int> m = {{1, 2}, {3, 4}}; // Initialize map with key-value pairs
	m.erase(1); // Erase pair with key 1
	
	return 0;
}