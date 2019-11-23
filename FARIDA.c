#include <stdio.h>
#include <strings.h>
#define ll long long
int main(void)
{
	ll t, c=0;
	scanf("%lli",&t);
	while(t--)
	{
		ll n;
		scanf("%lli", &n);
		ll arr[n];
		for(int i = 0; i < n; ++i)
			scanf("%lli", &arr[i]);
		ll ans[n], myans = 0;
		bzero(ans,n*sizeof(ll));
		for(int i = n-1; i >= 0; --i)
		{
			ll mm = 0;
			for(int j = i+2; j<n;++j)
				mm = ans[j] > mm ? ans[j] : mm;
			ans[i] = mm + arr[i];
			myans = myans < ans[i] ? ans[i] : myans;
		}
		printf("Case %lli: %lli\n", ++c,myans);
		
	}


}
