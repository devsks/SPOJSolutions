/*
 * brief@ KnapSack 0-1 Problem using recurrsion.
 * author@ devsks
 * quote@ "Code Like There's No Tommorow!"
 */
#include <stdio.h>
#define size 123
#define max(X, Y) ( (X) > (Y) ? (X) : (Y) )
int fillSack(int n, int w, int *wgt, int *val)
{
    if(!n || !w)
        return 0;
    else if (wgt[n] > w)
        return fillSack(n - 1, w, wgt,val);
    else
        return max( fillSack(n - 1, w, wgt, val), val[n] + fillSack(n - 1, w - wgt[n], wgt,val));
    
}    
int main()
{
    int n, wMax, curW = 0, w;
    double profit = 0;
    int wgt[size], val[size];
    wgt[0]=0;
    val[0] =0;
    do{
    scanf("%i %i", &wMax,&n);
    if(!wMax && !n)
        break;
    for(int i = 1; i <= n; i++)
        scanf("%i %i", &wgt[i], &val[i]);    

    int mat[n + 1][wMax + 1];   
    for(int i = 0 ; i <= n; i++)
        for(int j = 0; j <= wMax; j++)
            if(!j || !i)
                mat[i][j] = 0;
            else
                mat[i][j] = (wgt[i] > j) ? mat[i - 1][j] : max(mat[i - 1][j], val[i] + mat[i - 1][j - wgt[i]] );
    int ans =mat[n][wMax];
    for(int i = wMax;i>0;i--)
        if(mat[n][i]< ans){
            ans = i;
            break;
        }
    printf("%i %i\n",ans+1, mat[n][wMax]);
    
    }while(1);
    return 0;
}

