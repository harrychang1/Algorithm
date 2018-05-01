//Cracking Coding Interview [Chapter-1] Arrays and Strings
/*
	Implement on algorithm to determin if a string has all unique characters.
	What if you cannot use additional data structures?
*/
#include <bits/stdc++.h>

using namespace std;

bool isUniqueChars(string str)
{
	if(str.length() > 256)return false;
	
	bool char_set[256];
	for(int i = 0; i < 256; i++)
		char_set[i] = false;
	
	for(int i = 0; i < str.length(); i++){
			
		int Value = (int) str[i];
		if(char_set[Value])
			return false;
			
		char_set[Value] = true;
	}
	
	return true;
}

int main()
{	
	cout << isUniqueChars("hello") << endl;
	return 0;
}
