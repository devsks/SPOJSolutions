//author@devsks

/*

Link to problem: https://www.spoj.com/problems/COINS/
In Byteland they have a very strange monetary system.

Each Bytelandian gold coin has an integer number written on it. 
A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. 
But these numbers are all rounded down (the banks have to make a profit).

You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1.
But you can not buy Bytelandian coins.

You have one gold coin. What is the maximum amount of American dollars you can get for it?

Input
The input will contain several test cases (not more than 10).
Each testcase is a single line with a number n, 0 <= n <= 1 000 000 000. 
It is the number written on your coin.

Output
For each test case output a single line, containing the maximum amount of American dollars you can make.

Example
Input:
12
2

Output:
13
2
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX(X,Y) (X) < (Y) ? (Y) : (X)
#define ll long long
ll arr[1000000001];
ll max(ll n)
{
	if(n == 0 || n == 1)
		return n;	
	if(!arr[n])
		return (arr[n] = MAX(n, max(n/2)+max(n/3)+max(n/4)));
	else
		return arr[n];
	
}
int main()
{
    ll n;
    
    while(scanf("%lld",&n)==1)
    {
	    printf("%lld\n",max(n));
    	
    }
    return 0;
}

