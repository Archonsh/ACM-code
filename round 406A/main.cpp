#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAXN 1000000

using namespace std;



int main() {
    int n,m,i,j,k,a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    for(i=0;;i++)
    {
        n=b+i*a;
        j=(n-d)/c;
        if(j>=0)
            for(k=0;k<=j;k++)
                if(n==j*c+d)
                {
                    printf("%d\n",n);
                    return 0;
                }
     //   if(i>10000)
            break;
    }
    printf("-1");
//    return 0;

    return 0;
}