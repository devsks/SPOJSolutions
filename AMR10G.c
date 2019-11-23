/*
 * @author Santosh Kumar Shaw (devsks)
 * @quote "Code like there's no tommorow!"
 */
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define FOR(X,Y) for(ll X = 0; X < Y; ++X)
#define inp(X) scanf("%lli",&X)
int ja(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;	
}
int main(void)
{
	ll t;
	inp(t);
	FOR(tt,t)
	{
		ll n,k, min;
		inp(n),inp(k);
		
		ll arr[n];
		FOR(i,n)
			inp(arr[i]);
		if(k==1)
		{
			puts("0");
			continue;
		}
		qsort(arr,n,sizeof(ll),ja);
		min = arr[n-1] - arr[0];
		FOR(i,n-k+1)
		{
			if(arr[i+k-1]-arr[i] < min)
				min = arr[i+k-1] - arr[i];
		}
		printf("%lli\n",min);
	}
	return 0;
}

