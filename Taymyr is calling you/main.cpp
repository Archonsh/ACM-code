#include <cstdio>

using namespace std;

int main() {
    int n,m,z,i,ans=0,count=1;
    scanf("%d%d%d",&n,&m,&z);
    for(i=1;i<=10005;i++)
    {
        if(i*n>z)
            break;
        if(i*n % m ==0)
        {
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}