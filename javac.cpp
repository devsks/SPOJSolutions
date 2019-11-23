/*
 * @author Santosh Kumar Shaw (devsks)
 * @quote "Code like there's no tommorow!"
 */
#include <bits/stdc++.h>
#define FOR(X, Y) for( X = 0; X < Y; X++)
#define mod 1000000007
#define ll long long
using namespace std;
int main(void)
{
	int t, i, j;
	char st[1234];
	
    while(cin>>st)
	{
        
        int len = strlen(st);
        if(strchr(st,'_'))
        {
           
            int flag = 0,up = 0;
            vector<string> a;
           
            if(st[0]!='_' && islower(st[0]))
            {
                string s="";
                FOR(i,len)
                {
                    
                    if(st[i]=='_')
                    {
                        if( (i+1<len && st[i+1]=='_') || i==len-1)
                        {
                            flag = 1;
                            break;
                        }    
                        a.push_back(s);
                        up= 1;
                        s = "";
                    }    
                    else
                    {    
                        if(isupper(st[i]))
                        {
                            flag = 1;
                            break;
                        }    
                        if(up)
                        {
                            s+=toupper(st[i]);
                            up = 0;
                        }    
                        else
                            s+=st[i];
                    }        
                }
                if(!flag && s!="")
                    a.push_back(s);
            }           
            else
                flag = 1;
            if(flag)
                printf("Error!");
            else
            {
                for(vector<string>::iterator it  = a.begin(); it != a.end(); it++)
                {
                    cout<<*it;
                
                }    
            }    
        }
        else
        {
            i = 0;
          if(isupper(st[0]))
               printf("Error!");
           else
           {
               int flag = 0;
               j = 0;
               while(j<len)
               {    
                    i = j;
                   while(i<len && islower(st[i]))
                   {
                        cout<<st[i];
                        i++;
                   }
                   if(i!=len)
                        cout<<"_";
                   else
                    break;
                   st[i] = tolower(st[i]);
                   j = i;
               
              }          
           }    
        
        }    

        cout<<endl;

	}
	return 0;
}

