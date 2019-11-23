/*
coder@devsks

Link : https://www.spoj.com/problems/AIBOHP/
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int LCS(string one, string two)
{
	int dp[one.length()+1][two.length()+1];
	for(int i = 0; i <= one.length(); ++i)
		for(int j = 0; j <= two.length(); ++j)
		{
			if(!i || !j)
				dp[i][j] = 0;
			else if(one[i-1] == two[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
		}
	return dp[one.length()][two.length()];
}
int main(void)
{

	int t;
	cin>>t;
	string str, rev;
	while(t--)
	{

		cin>>str;
		//Best Case
		rev = str;
		reverse(str.begin(), str.end());
		if (str == rev)
			puts("0");
		else
			printf("%lu\n",str.length() - LCS(str, rev));	
	}
	return 0;
}
