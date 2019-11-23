#include "bits/stdc++.h"
using namespace std;
int maxwa;
int bfs(int n, int s, vector<vector<int> > g){
    int ind  =s;
    maxwa = 0;
    vector<int >prn(n+1,0);
    vector<int> dis(n+1,0);
    vector<int> vis(n+1,0);
    stack<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    prn[s] = -1;
    while(!q.empty()){
        int root = q.top();
        q.pop();
        for(vector<int>::iterator it = g[root].begin();it!=g[root].end();it++){
            if( !vis[*it]){
                vis[*it] = 1;
                prn[*it] = root;
                dis[*it] = dis[root] + 1;
                if(maxwa < dis[*it]){
                    ind = *it;
                }
                maxwa = max(maxwa,dis[*it]);
                q.push(*it);
            }
        }
    }
    return ind;
}
int main(){
    int n,u,v;
    
    scanf("%i", &n);
    vector< vector<int> > g(n+1);
    for(int i=1;i<n;i++){
        scanf("%i %i",&u,&v);
        if(v-u){
            g[v].push_back(u);
            g[u].push_back(v);
        }
    
    }
    int i = bfs(n,1,g);
    bfs(n,i,g);
    /*for(int i=1;i<=n;i++){
        bfs(n,i,g);
        if(maxwa >= n-1)
            break;
    }*/
    printf("%i", maxwa);
    return 0;
}
