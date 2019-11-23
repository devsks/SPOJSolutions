/*
 * @brief Segment Tree
 * @author Santosh Kumar Shaw (devsks)
 * @quote "Code like there's no tommorow!"
 */
#include <stdio.h>
#include <limits.h>
#define MAX(X, Y) (X > Y ? X : Y)
int tree[5432100];
void buildTree(int*, int, int, int);
int query(int, int, int,int,int);
int main(void)
{
    int n, m, i, j;
    scanf("%i",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%i",&arr[i]);
    buildTree(arr, 0, n, 0);
    scanf("%i",&m);
    while(m--)
    {    
        scanf("%i %i",&i,&j);
        printf("%i\n",query(0,n,--i,--j,0));
    }
    return 0;
}
void buildTree(int *arr, int low, int high, int root)
{
    if (low == high-1)
    {
        tree[root] = arr[low];
    }    
    else
    {
        int mid = (low + high) >> 1, l = root << 1 | 1, r = l + 1;
        buildTree(arr, low, mid, l);
        buildTree(arr, mid, high, r);
        tree[root] = 0;
        if(tree[l]>0)
            tree[root] += tree[l];
        if(tree[r]>0)
            tree[root] +=tree[r];
        if(tree[root]==0)
            tree[root] = MAX(tree[l],tree[r]);
    }    

}
int query(int low, int high,int left, int right, int root)
{
    if (left > high-1 || right < low)
        return INT_MIN;
    else if (left <= low && right >= high-1)
        return tree[root];
    else
    {
        int mid = (low + high) >> 1, l = root << 1 | 1, r = l + 1, ans = 0, a, b;      
         a = query(low, mid, left, right, l);
         b = query(mid, high, left, right, r);
        if(a>0)
            ans += a;
        if(b>0)
            ans += b;
        if(ans == 0)
            ans  = MAX(a,b);
        return ans ;   
    }    

}    
