#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    int n,m,i,j,x,y,pmin=0x7fffffff,pmax=0,cmin=0x7fffffff,cmax=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        if(y<cmin)
            cmin=y;
        if(x>cmax)
            cmax=x;
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        if(y<pmin)
            pmin=y;
        if(x>pmax)
            pmax=x;
    }
    if(pmax-cmin<0 && cmax-pmin<0)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n",max(pmax-cmin,cmax-pmin));
    }
    return 0;
}