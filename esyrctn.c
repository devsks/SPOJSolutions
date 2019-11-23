#include <stdio.h>
#define ll long long
int main()
{
    int t;
    scanf("%i",&t);
    while(t--)
    {    
        ll n, arr[]={0, 1, 4, 6, 5, 2};
        scanf("%lli",&n);
        printf("%lli\n", arr[n % 6]);
    }
    return 0;
}    
