/*
 * @author Santosh Kumar Shaw (devsks)
 * @quote "Code like there's no tommorow!"
 */
#include <bits/stdc++.h>
#define FOR(X,Y) for(ll  X = 0; X < Y; X++)

#define mod 1000000007
#define ll long long
using namespace std;
int dp[1001][1001][1001];
ll getAns(ll *arr, int day, int low, int high)
{
		
	if(low > high)
		return 0;
	if(dp[day][low][high])
		return dp[day][low][high];
	if (low == high)
	{
		dp[day][low][high] = arr[low]*day;
		return dp[day][low][high];
	}
//	if(low+1==high)
//		return min( arr[low]*day, arr[high]*day);
	dp[day][low][high] = max( arr[low]*day + getAns(arr,day+1,low+1,high), arr[high]*day +getAns(arr,day+1,low,high-1));
	return dp[day][low][high];
}

int main()
{
    int t = 1, i, j;
	//cin>>t;
    //while(t--)
    {
        ll n, x, ans=0;
		cin>>n;
    	ll arr[n];
		FOR(i,n)
			cin>>arr[i];
		ans  = getAns(arr, 1, 0, n - 1);
		cout<<ans;
    }    
    return 0;
}    

