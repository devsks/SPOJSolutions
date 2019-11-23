#include <stdio.h>
#include <stdlib.h>
#define ll long long

int cmp(const void*a, const void *b){
	return ( *(ll*)a - *(ll*)b);

}
int check(ll *arr, ll n, ll c, ll dist){
	ll pos = 0, placed = 1;
	
	for(int i=1;i<n;i++){
		if(arr[i]-arr[pos] >= dist){
			if(++placed==c)
				return 1;
			pos = i;
		}

	}
	return 0;
	
}
int main(){
	ll t, i, j, ans,arr[1023456];
	scanf("%lli",&t);
	while(t--){
		ll n,c;
		scanf("%lli %lli",&n,&c);
		ans = -1;	
		for( i=0;i<n;i++)
			scanf("%lli",&arr[i]);
		qsort(arr, n, sizeof(ll), cmp);
		ll low = 0 , high = arr[n-1] - arr[0], mid;
		while(low < high){
			mid = low+high >>1;
			if(check(arr, n, c, mid) )
			{	low = mid+1;
				ans = mid;
			}
			else
				high = mid;
		}
		printf("%lli\n", ans);
	}
	return 0;
}
