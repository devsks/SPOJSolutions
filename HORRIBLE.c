/*
 * @author Santosh Kumar Shaw (devsks)
 * @quote "Code like there's no tommorow!"
*/
#define ll long long
#define FOR(X,Y) for(ll X = 0; X < Y; ++X)
#define inp(X) scanf("%lli",&X)
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
ll tree[1001234], lazy[1001234];
void update(int x, int y, int l, int h, int r, ll val)
{
	if(lazy[r])
	{
		tree[r] += (h-l+1LL)*lazy[r];
		if(l-h)
		{
			lazy[r<<1] +=lazy[r];
			lazy[r<<1|1]+=lazy[r];
		}
		lazy[r] = 0;
	}

	if( l>y || h < x || l > h)
		return ;
	if(l>=x && h<=y)
	{
		tree[r]+= (h-l+1LL)*val;
		if(h-l)
		{
			lazy[r<<1] +=val;
			lazy[r<<1|1]+=val;
		}
	}
	else
	{
		ll mid = l+h>>1;
		update(x,y,l,mid,r<<1,val);
		update(x,y,mid+1,h,r<<1|1,val);
		tree[r] = tree[r<<1] + tree[r<<1|1];
	}

}
ll query(int x, int y, int l, int h,int r)
{
	if(l > y || h < x || l > h)
		return 0;
	if(lazy[r])
	{
		tree[r] += (h-l+1)*lazy[r];
		if(l-h)
		{
			lazy[r<<1] +=lazy[r];
			lazy[r<<1|1]+=lazy[r];
		}
		lazy[r] = 0;
	}

	if(x<=l && h<=y)
		return tree[r];
	else
	{
		ll a1,a2,mid = l+h>>1;
		a1 = query(x,y,l,mid,r<<1);
		a2 = query(x,y,mid+1,h,r<<1|1);
		return (a1+a2);
	}

}
int main(void)
{
	ll t;
	inp(t);
	while(t--)
	{
		ll n, q, x, y, z;
		inp(n),inp(q);

		bzero(tree, sizeof(tree));
		bzero(lazy, sizeof(tree));
		while(q--)
		{
			inp(x),inp(y),inp(z);
			if(!x)
			{
				inp(x);
				update(y - 1, z - 1, 0, n - 1, 1, x);
			}
			else
				printf("%lli\n",query(y-1,z-1,0,n-1,1));			
		}
	}
	return 0;
}

