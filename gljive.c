#include<stdio.h>
int main()
{
    int t = 10 ,i=0,j=0;
    int arr[10],sum = 0;
    while(i<t)
    {
        scanf("%i",&arr[i++]);
    }
    for(i=0;i<10;i++)
    {
    	sum+=arr[i];
		if(sum >= 100)
		{
			if(sum-100 <= 100 - (sum-arr[i]) )
				printf("%i",sum);
			else
				printf("%i",sum-arr[i]);
			j=1;
			break;
		}
    }
	if(!j)
    printf("%i",sum);

}    
