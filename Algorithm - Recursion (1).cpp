#include <bits/stdc++.h>

using namespace std;

int counter = 0;

//function implement collatz conjecture algorithm for multiple recursive case example
int collatz(int n){
	
	//base case
	if(n == 1)return counter;
	
	//recursive case
	if(n % 2 == 0){
		counter += 1;
		collatz(n/2);
	}else if(n % 2 != 0){
		counter += 1;
		collatz((3*n) + 1);
	}
	
}

int collatzz(int n){
	
	//base case
	if(n == 1)
		return 0;
	else if((n % 2) == 0)
		return 1 + collatz(n/2);
	else
		return 1 + collatz((3*n)+1);
}

//function implement fibonacci number algorithm for multiple base case example
int fibo(int n){
	
	//base case
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	
	//recursive case
	return fibo(n-1) + fibo(n-2);
}

//function implement factorial algorithm for single base case and single recursive case
int fact(int n){
	
	//base case
	if(n == 1)
		return 1;
	
	//recursive case
	return n * fact(n-1);
}

int main()
{	
	int n;
	scanf("%d",&n);
	
	cout << fact(n) << endl;
	cout << fibo(n) << endl;
	cout << collatz(n) << endl;
	
	return 0;
}
