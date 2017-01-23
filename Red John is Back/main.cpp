/*
 * 题型是coin change
 * 但是不同顺序算不同方法
 * dp[i][j]: amount = i ; number of '4' coins ;
 * 每个情况都有两种选择 最后一位加1或加4
 * dp[i][j] = dp[i-4][j-1] + dp[i-1][j]
 * 因为加1或加4是根据前面的情况转移而来的
 * 所以一定 不存在重复问题
 *
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int sieve(int *n)
{
    if(*n==2) return 1;
    int i,j,bound,f=1,ans=1;
    for(i=3;i<=*n;i++)
    {
        bound=int(sqrt(i))+1;
        f=1;
        for(j=2;j<=bound;j++)
            if(!(i%j)) {f=0;break;}
        if(f) ans++;
    }
    return ans;

}
int main() {
    int T,n,dp[41][11],i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n<4) {printf("0\n");continue;}

        memset(dp,0,sizeof(dp));
        for(i=0;i<=n;i++)
            dp[i][0]=1; //选0个4 '11111...111'
        for(i=0;i<=3;i++)
            for(j=1;j<=10;j++)
                dp[i][j]=0;


        for(i=4;i<=n;i++)//amount dp[i][]
        {
            for(j=1;j<=10;j++)// 4的个数
            {
                if(4*j>i) break;
                dp[i][j]=dp[i-4][j-1]+dp[i-1][j];//最后一位是4 + 最后一位是1
            }
        }
        k=0;
        for(i=0;i<=10;i++)
            k+=dp[n][i]; //amount为n时的总方案数
        printf("%d\n",sieve(&k));
    }
    return 0;
}