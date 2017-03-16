#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n,i,a[100005],ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(i=2;i<n;i++)
    {
        if(a[i]>a[1] && a[i]<a[n])
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}