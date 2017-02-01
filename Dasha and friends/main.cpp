#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n,L,i,j,a[55],b[55],flag=0;
    scanf("%d%d",&n,&L);
    if(n==1)
    {
        printf("YES\n");
        return 0;
    }
    a[0]=0;

    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<=L;i++) //旋转i度
    {
        for(j=1;j<=n;j++)
        {
            b[j]+=1;
            b[j]%=L;
            //printf("%d ",b[j]);
        }
        //printf("\n");
        sort(b+1,b+n+1);
        flag=0;
        for(j=1;j<=n;j++)
        {
            if(a[j]!=b[j])
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO");
    return 0;
}