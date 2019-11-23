#include <stdio.h>
#include <limits.h>
#define ll long long
int main(){
    ll a, d;
    scanf("%lli %lli", &a, &d);
    while(a || d){
        ll min=INT_MAX,x;
        ll min1 = INT_MAX, min2=INT_MAX;
        for(int i=0;i<a;i++){
            scanf("%lli",&x);
            if(x < min)
                min = x;
        }
        for(int i=0;i<d;i++){
            scanf("%lli",&x);
            if(x < min1){
                min2 = min1;
                min1 =x;
            }else if(x < min2)
                min2 =x;
        }
        if(min < min2 || min < min1)
            puts("Y");
        else
            puts("N");
        scanf("%lli %lli",&a,&d);
    }

    return 0;
}
