#include <bits/stdc++.h>
using namespace std;
#define  ll long long
struct point
{
    int x,y;

    point(int a, int b)
    {
        x= a, y=b;
    }
};

int mat[1001][1001], row, col, x2, y2,cx[] = {1,-1,0,0},cy[]={0,0,1,-1};
ll dp[1001][1001];

bool isValid(int r, int c)
{
	return ((r>= 0) && (r < row) && (c >= 0) && (c < col) && !mat[r][c]  );
}

void bfs(point p)
{
    queue<point> myq;
    myq.push(p);
    while(!myq.empty())
    {
        point aux = myq.front();
        myq.pop();
        for(int i = 0; i < 4; ++i)
        {
            int mx = aux.x, my=aux.y;    
            while(isValid(mx+cx[i], my+cy[i]))
            {
                if(dp[mx+cx[i]][my+cy[i]] > dp[aux.x][aux.y]+1)
                {
                    point np(mx+cx[i],my+cy[i]);
                    dp[np.x][np.y] = dp[aux.x][aux.y]+1;
                    myq.push(np);
                    
                }
                mx+=cx[i];
                my+=cy[i];
            }
            
        }
        
    }
    
}
int main()
{
    scanf("%i %i", &col, &row);
    char str[col+2];
    int x1,y1, f=0;
    for(int i = 0; i < row; ++i)
    {
        scanf("%s", str);
        for(int j = 0; j < col; ++j)
        {
            if(str[j] == 'C')
            {
            	if(!f)
            	{
                	x1 = i, y1 = j;
            		f=1;
            		
            	}
                else
                	x2 = i, y2 = j;
            }    
            else if(str[j]=='*')
                mat[i][j] = 1; 
            dp[i][j] = INT_MAX;
        }
    }
    point pp(x1,y1);
    dp[x1][y1] = 0;
    bfs(pp);
    cout<< dp[x2][y2]-1;
    return 0;
}
