#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAXN 10005

using namespace std;
int morty[MAXN];

int main()
{
    int i,j,k,n,m,t,tmp;
    memset(morty,0,sizeof(morty));
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        memset(morty,0,sizeof(morty));
        scanf("%d",&k);
        tmp=0;
        for(j=1;j<=k;j++)
        {
            scanf("%d",&t);
            if(morty[abs(t)]==0)
                morty[abs(t)]=t;
            else if(morty[abs(t)]==t)
                continue;
            else if(morty[abs(t)]==-t)
            {
                tmp=1;
            }
        }
        if(!tmp)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}