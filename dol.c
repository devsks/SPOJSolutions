#include <stdio.h>
#define ll long long
int main(void)
{
    ll t,i;
    scanf("%lli",&t);
    for(i=1;i<=t;i++)
    {
        ll n;
        scanf("%lli",&n);
        printf("Case %lli: ",i);
        if(n&1)
            printf("%lli\n",n);
        else
        {    
            do
            {
                n = n/2;
            }   
            while((n&1) == 0);
  
            printf("%lli\n",n);
        }
    }    

    return 0;
}    
