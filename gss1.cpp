/*
*	@coder : devsks	(Santosh Kumar Shaw)
*	@college : Acamdemy Of Technology (WB)
*	@quote : "Code Like Thers's No Tommorow!"
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#define ll long long
using namespace std;
struct node{
	ll sum, lS, rS, best;
	
};
node nul = {0,0,0,0};
class segTree{
	vector<node> tree;
	vector<int> lazy;
	int size, N;
	int getSize(int n){
		int ret = 1;
		while(ret < n ) ret <<= 1;
		return ret << 1;
	}
	void buildTree(vector<int>& arr, int root, int low, int high){
		if(low==high){
			tree[root].sum = tree[root].lS = tree[root].rS = tree[root].best = arr[low];
		}else{
			int mid = (low + high) >> 1;
		
			buildTree(arr, root<<1, low, mid);
			buildTree(arr, root<<1|1, mid + 1, high);
		
			tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
			tree[root].lS = max(tree[root<<1].lS, tree[root<<1].sum + tree[root<<1|1].lS) ;
			tree[root].rS = max(tree[root<<1|1].rS, tree[root<<1|1].sum + tree[root<<1].rS) ;
			tree[root].best = max( max(tree[root<<1].best, tree[root<<1|1].best), tree[root<<1].rS + tree[root<<1|1].lS);
		}
	}
	node query(int root, int left, int right, int l, int r){
	//	updateLazy(root, left, right);
			
		if( l == left && r == right){
			
			return tree[root];
		}
		else{
			int mid = (left + right) >> 1;
			node a,b,c;
			if(  r <= mid)
				return query(root<<1,left,mid,l,r);
			else if( l > mid)
				return query(root<<1|1, mid + 1, right, l, r);
	 
			b = query(root<<1|1, mid + 1, right, mid+1, r);
			a =  query(root<<1, left, mid, l, mid); 
			c.sum = a.sum + b.sum;
			c.lS = max(a.lS, a.sum + b.lS);
			c.rS = max(b.rS, b.sum + a.rS);
			c.best = max( max(a.best, b.best), a.rS + b.lS);
			return c;
		
		}
	}
	/*
	void update(int root, int left, int right, int ind, int val){
		if(ind >= left && ind <= right){
			if(left==right){	
				tree[root].val += val;
			}
			else{
				int mid = (left + right) >> 1;
				ind <= mid ? update(root<<1, left, mid, ind, val) : update(root<<1|1, mid + 1, right, ind, val);
				tree[root].val = tree[root<<1].val + tree[root<<1|1].val;
			}
		}
	}
	void rangeUpdate(int root, int left, int right, int low, int high, int val){
		updateLazy(root, left, right);
		if(low > right || high < left )
			return;
		if(low<=left && high>=right){
			tree[root].val += (right - left + 1) * val;
			if(left-right){
				lazy[root<<1] += val;
				lazy[root<<1|1] += val;
			}
			return;
		}	
		int mid = (left + right) >> 1;
		rangeUpdate(root<<1, left, mid, low, high, val);
		rangeUpdate(root<<1|1, mid + 1, right, low, high, val);
		tree[root].val = tree[root<<1|1].val + tree[root<<1].val;
	}
	void updateLazy(int root, int left, int right){
		if(lazy[root]){
            tree[root].val += (right - left + 1) * lazy[root];
            if(left - right){
                lazy[root<<1] += lazy[root];
                lazy[root<<1|1] += lazy[root];
            }
           lazy[root]  = 0;
        }	
	}*/
	public:
		segTree(int n, vector<int>& arr){
		size = getSize(n);
		N = n - 1;
		//lazy.assign(size, 0);
		tree.assign(size,nul);
		buildTree(arr, 1, 0, N);	
		
	}
	ll query(int l, int r){
		return query(1, 0, N, l, r).best;
	}/*
	void update(int ind, int val){
		update(0, 0, N, ind, val);
	}
	
	void update(int si, int ei, int val){
		rangeUpdate(0, 0, N, si, ei, val);
	}*/
};
int main(){
	int n, q, x, y;
	scanf("%i", &n);
	vector<int>arr(n);
	for(int i = 0; i < n; i++)
		scanf("%i",&arr[i]);
	segTree t(n, arr);
	scanf("%i",&q);

	while(q--){
		scanf("%i %i",&x,&y);
		printf("%lli\n",t.query(x - 1, y - 1));
	}
	return 0;




}




