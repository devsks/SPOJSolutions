/*
 * @author Santosh Kumar Shaw (devsks)
 * @quote "Code like there's no tommorow!"
 */
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#define ll long long
#define mod 1000000007
#define FOR(X,Y) for(ll X = 0; X < Y; ++X)
#define inp(X) scanf("%lli",&X)
void mul(ll tmp[][2], ll tmp1[][2])
{
		ll x,y,z,k;
		x = (tmp[0][0]*tmp1[0][0])%mod + (tmp[0][1]*tmp1[1][0])%mod;
		y = (tmp[0][0]*tmp1[0][1])%mod + (tmp[0][1]*tmp1[1][1])%mod;
		z = (tmp[1][0]*tmp1[0][0])%mod + (tmp[1][1]*tmp1[1][0])%mod;
		k = (tmp[1][0]*tmp1[0][1])%mod + (tmp[1][1]*tmp1[1][1])%mod;
		tmp[0][0] = x%mod;
		tmp[0][1] = y%mod;
		tmp[1][0] = z%mod;
		tmp[1][1] = k%mod;


}
void powM(ll f[][2],ll a)
{
	ll tmp[][2] = {{1,1},{1,0}};
	while(a > 0)
	{
		if(a&1)
			mul(f,tmp);
		mul(tmp,tmp);
		a>>=1;
	}
}
int main(void)
{
	ll t;
	inp(t);
	FOR(tt,t)
	{
		ll a, b, f[][2]={1,0,0,1}, ans=0,ans1=0,aux,sum=0;
		inp(a);
		inp(b);
		if(b==0)
		{
			puts("0");
			continue;
		}
		powM(f,b+1);
		ans = (f[0][0]-1+mod)%mod;
		f[0][0] = 1; f[0][1] = 0; f[1][0] = 0; f[1][1] = 1;
		if(a!=0)
		{
			powM(f,a);
			ans1 = (f[0][0]-1+mod)%mod;
		}
		//	printf("%lli %lli\n%lli %lli\n\n",f[0][0],f[0][1],f[1][0],f[1][1]);
		
		sum = (ans - ans1 + mod)%mod;
		printf("%lli\n",sum);
	}
	return 0;
}

