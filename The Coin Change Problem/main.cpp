/*
 * dp中"前"几件物品的 状态 即 选择和不选择的状态
 * dp的数据范围估算
 * 合理剪枝
 */
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,m,dp[51][251],v[51];
int main() {
    long long i,j,k,f,tmp;
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%lld",&v[i]);
        dp[i][0]=1;
    }
    dp[0][0]=1;
    for(i=1;i<=n;i++)
        dp[0][i]=0;
    sort(v,v+m+1);
    for(i=1;i<=n;i++)//i for amount
    {
        for(j=1;j<=m;j++)//j for coin
        {
            if(v[j]<=i)//valid choice
            {
                dp[j][i]=dp[j][i-v[j]]+dp[j-1][i];
            }
            else
            {
                for(k=j;k<=m;k++)
                    dp[k][i]=dp[j-1][i];
                break;
            }
        }
    }
    printf("%lld\n",dp[m][n]);
    return 0;
}