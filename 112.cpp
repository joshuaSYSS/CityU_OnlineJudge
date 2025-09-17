/*
INCORRECT SOLUTION!
*/

#include <stdio.h>
#include <stdint.h>
typedef int16_t S;
int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        S a,b,c;
        scanf("%hd%hd%hd",&a,&b,&c);
        int ok=0;
        S v0=10001,v1=10001,v2=10001;
        S Babs = b>=0?b:-b;
        for(S d=1; d*d<=Babs; ++d){
            if(Babs%d) continue;
            S cand[4] = { d, -d, b/d, -(b/d) };
            for(int t=0;t<4;++t){
                S x = cand[t];
                if(x==0 || b%x) continue;
                S Ax = a - x;
                S q = b / x;
                S disc = Ax*Ax - 4*q;
                if(disc<0) continue;
                S r=0;
                while((S)(r+1)*(S)(r+1) <= disc) r++;
                if(r*r != disc) continue;
                for(int sgn=-1; sgn<=1; sgn+=2){
                    S num = Ax + sgn*r;
                    if(num & 1) continue;
                    S z = num/2;
                    S y = a - x - z;
                    if(x*y*z != b) continue;
                    if(x*x + y*y + z*z != c) continue;
                    if(!ok || x < v0 || (x == v0 && y < v1)){
                        ok=1; v0=x; v1=y; v2=z;
                    }
                }
            }
        }
        if(!ok) printf("No solution.\n");
        else printf("%hd %hd %hd\n",v0,v1,v2);
    }
    return 0;
}