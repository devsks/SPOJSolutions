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

