/*
	Given two strings write a method to decide if one
	is a permutation of other
*/
#include <bits/stdc++.h>

using namespace std;

/*Solution 1 <==> Sort the string*/
bool isPermutation(string s, string t){
	
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	
	if(s.length() != t.length()){
		return false;
	}
	
	return (s == t) ? true : false;
}

int main()
{	
	
	cout <<  isPermutation("abcd", "abc") << endl;
		
	return 0;
}
