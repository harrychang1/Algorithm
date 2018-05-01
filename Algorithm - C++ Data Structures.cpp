//C++ Common Data Structures

#include <bits/stdc++.h>

using namespace std;

int main()
{	
	
	// 1. Vector
	// Common Method : push_back() , [] , size()   ==> Run Time O(1)
	
	vecotr<int> v;						// v = {}
	cout << v.size() << endl;			// output = 0
	v.push_back(20);					// v = { 20 } 
	v.push_back(10);					// v = { 20, 10 }
	v.push_back(10);					// v = { 20, 10, 10 }
	cout << v[1] << endl;				// outputs 10
	cout << v.size() << endl;			// outputs 3
	
	
	// 2. Set
	// Common Method : insert() ==> Run Time O(log n) , find() ==> Run Time O(log n) , size() ==> Run Time O(1)
	
	set<int> s;							// s = {}
	cout << s.size() << endl;			// outputs 0
	s.insert(20);						// s = { 20 } 
	s.insert(10);						// s = { 10, 20 }
	s.insert(10);						// s = { 10, 20 }
	auto it = s.find(10);				// it is an iterator that points to 10
	cout << (it != s.end() ? "found" : "") << endl; 	// output found
	cout << s.size() << endl;			// outputs 2
	
	return 0;
}
