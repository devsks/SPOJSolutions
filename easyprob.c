#include <stdio.h>
#include <math.h>
void print(int n)
{
    int i = 1<<20, p = 20,flag = 0;
    if(!n)
        putchar('0');
    else if(n==2)
        putchar('2');
    /*else if( !(n&(n-1)))
    {    
        p = 0;
        while(n>0)
        {
            n>>=1;
            p++;
        }
       
        printf("%i",p);
    }*/
    else
    {    
        while(i>0)
        {
            if(n&i)
            {
                if(flag)
                    putchar('+');
                flag = 1;
                if(p!=1)
                {    
                    printf("2(");
                    print(p);
                    printf(")");
                }
                else
                    putchar('2');
            }    
            i>>=1;
            p--;
        }
    }    
}    
int main(void)
{
    int t = 7;
//    scanf("%i",&t);
    while(t--)
    {    
        int n,i=0;
        scanf("%i",&n);
        printf("%i=",n);
        print(n);
      /*  puts("");
        while(n)
        {
            printf("%i",n&1);
            n>>=1;
        }*/    
        if(t)
        puts("");
    }
}
