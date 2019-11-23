/*
 * @author Santosh Kumar Shaw (devsks)
 * @quote "Code like there's no tommorow!"
 */
#include <bits/stdc++.h>
#define FOR(X,Y) for( X = 0; X < Y; X++)

#define mod 1000000007
#define ll long long
using namespace std;
vector<ll> arr;
int mp[1000001];
int prim[1000001];
void gen()
{
	for(int i=2;i*i < 1000001; ++i)
		if(prim[i]==0)
		{
			for(int j = i<<1; j<1000001;j+=i)
			{
				prim[j] +=1;
				if(prim[j] >=3 && mp[j]==0 )
				{
					arr.push_back(j);
					mp[j] =1;
				}
			}
		}
}
int main()
{
    int t, i, j;
   	gen();
	sort(arr.begin(),arr.end());
	cout<<arr.size()<<endl;
   	cin>>t;
    while(t--)
    {
        ll n;
		cin>>n;
		cout<<arr[n-1]<<endl;
    	
    }    
    return 0;
}    
