#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define ll long long
#define FOR(X, Y) for(ll X = 0; X < Y; X++)
#define MIN(X, Y) ( (X) < (Y) ? (X) : (Y))
typedef struct node{
    ll vertex, dist;
}node;
ll prims(ll**, ll, ll);
ll get_next_min(node*, ll*, ll);
void update_node(node*, ll*, ll, ll);
int main()
{
    FILE* inptr = stdin;
    if( inptr)
    {
        ll v, i , j, e, u, n, d, r;
        fscanf(inptr, "%lli %lli", &n, &e);
        ll **cost = (ll**)calloc(n , sizeof(ll*));
        FOR(i,n)
        {    
            cost[i] = (ll*)malloc( n * sizeof(n));
            FOR(j, n)
                cost[i][j] = i-j ? INT_MAX : 0;
        }

        FOR(i,e)
        {
            fscanf(inptr, "%lli %lli %lli", &u, &v, &d);
            if(u == v)
                continue;
			u--;
			v--;
            // Minimum Parallel edge (If any)
            cost[u][v] = MIN(cost[u][v],d);
            cost[v][u] = MIN(cost[u][v],d);
        }    
        // source node
        //fscanf(inptr, "%lli", &r);
        ll min_dist = prims(cost, 0, n);
        printf("%lli", min_dist);
    }    
    return 0;
}
ll prims(ll ** cost, ll source, ll v)
{
    ll edgeSet[v], heapSize = v, map[v],dist = 0, k = 1, u;
    node heap[v];
    heap[0].vertex = source;
    map[source] = 0;

    FOR(i, v)
    {       
        edgeSet[i] = -1;
        heap[i].dist = INT_MAX;
        if(source - i)
        {    
            heap[k].vertex = i;
            map[i] = k++;
        }    
    }  
    while(heapSize--)
    {
        u = get_next_min(heap, map, heapSize);
        FOR(i, heapSize)    
            if(  cost[u][heap[i].vertex] < heap[i].dist)
            {
                edgeSet[heap[i].vertex] = u;
                update_node(heap, map, heap[i].vertex, cost[u][heap[i].vertex]);
            }  
    }
    FOR(i,v)
    {
        if(edgeSet[i] + 1)
        {
            dist += cost[i][edgeSet[i]];
        }    
    }    
    return dist;
}

ll get_next_min(node *heap, ll *map, ll heapSize)
{
    ll ret = heap[0].vertex, p = 0, l, r, min;
    heap[p] = heap[heapSize];
    map[heap[p].vertex] = p;
    while (p < heapSize >> 1 )
    {
         l = p << 1 |1;
         r = l + 1;
         min = r < heapSize ? (heap[l].dist < heap[r].dist ? l : r) : l;
        if( heap[p].dist > heap[min].dist)
        {
            map[heap[p].vertex] = min;
            map[heap[min].vertex] = p;
            
            node tmp =  heap[p] ;
            heap[p] = heap[min];
            heap[min] = tmp;
            p = min;
         }    
        else
            break;
    }    

    return ret;
}
void update_node(node *heap, ll *map, ll u, ll val)
{
    ll c = map[u], p;
    heap[c].dist = val;
    while(c)
    {
        p = c >> 1;
        if(heap[p].dist >  heap[c].dist)
        {
            map[heap[p].vertex] = c;
            map[heap[c].vertex] = p;
            node tmp =  heap[p] ;
            heap[p] = heap[c];
            heap[c] = tmp;
            c = p;
        }    
        else
            break;
    }    
    
}    

