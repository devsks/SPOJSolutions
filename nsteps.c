#include <stdio.h>
int main()
{
    int t;
    scanf("%i", &t);
    while(t--)
    {
        int x, y, ans;
        scanf("%i %i", &x, &y);
        if(x == y || x == y + 2)
        {
            if(y&1)
                ans = x + y -1;
            else
                ans = x + y;
             printf("%i\n", ans);
        }
        else
            puts("No Number");
    }    

}    
