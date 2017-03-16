#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n,i,j,ptr,t;
    bool map[100005];
    memset(map,0,sizeof(map));
    scanf("%d",&n);
    ptr=n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);
        map[t]=1;
        if(t==ptr)
        {
            while(map[ptr])
            {
                printf("%d ",ptr);
                ptr--;
            }
            printf("\n");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}