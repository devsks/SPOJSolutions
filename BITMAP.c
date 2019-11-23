/*
 * @author Santosh Kumar Shaw (devsks)
 * @quote "Code like there's no tommorow!"
 */
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define mod 1000000007
#define ll long long
#define FOR(X,Y) for(ll X = 0; X < Y; ++X)
#define inp(X) scanf("%lli",&X)
#define prn(X) printf("%lli",X);
typedef struct node node;
struct node
{
	int x,y;
	node*next;
};
int cmp(const void*a, const void*b);
void ins(node**root, int x, int y)
{
	node *aux = (node*)calloc(1,sizeof(node));
	aux->x = x;
	aux->y = y;
	aux->next = *root;
	*root = aux;
}
int main(void)
{
	ll t;
	inp(t);
	FOR(tt,t)
	{
		ll n,m;
		inp(n),inp(m);
		ll dis[n][m];
		FOR(i,n)
			FOR(j,m)
				dis[i][j] = INT_MAX;
		char str[n][m+2];
		node*root = NULL;
		FOR(i,n)
		{
			scanf("%s", str[i]);
			char*ptr  = strchr(str[i],'1');
			while(ptr)
			{
				ins(&root,i,ptr-str[i]);
				ptr = strchr(ptr+1,'1');
			}
		}
		while(root)
		{
			int x = root->x,y = root->y;
			FOR(i,n)
				FOR(j,m)
				{
					if(str[i][j]=='0')
					{
						ll d = abs(x-i)+abs(y-j);
						dis[i][j] = d < dis[i][j] ? d : dis[i][j];
					}
					else
						dis[i][j] =0;
				}
			root = root->next;
		}
		FOR(i,n)
		{
			FOR(j,m)
				printf("%lli ",dis[i][j]);
			putchar('\n');	
		}

	}
	return 0;
}

