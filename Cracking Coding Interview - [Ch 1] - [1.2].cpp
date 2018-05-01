/*
	Implement a function void reverse(char* str) in C or C++
	which reverses a null-terminated string
*/
#include <bits/stdc++.h>

using namespace std;

void reverse(char *str){
	char* end = str;
	char tmp;
	if(str){
		while(*end){
			++end;
		}
		--end;
		
		while(str < end){
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}

int main()
{	
	char str[5];
	scanf("%[^\n]",str);
	reverse(str);
	printf("%s\n",str);
	return 0;
}
