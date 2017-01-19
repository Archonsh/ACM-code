/*
 * 前i个数字 (任意选择 无后效性) 的最大值
 * +当前数字选/不选的最大值
 *
 * 贪心不行 eg 10 62 30 贪不到最优解法
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define mm(a,i) memset(a,i,sizeof(a))
int main()
{
    int T,n,b[100005],i,j,k,dp[100005][3];
    scanf("%d",&T);
    while(T--)
    {
        mm(dp,0);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]);
        dp[1][0]=dp[1][1]=0;
        for(i=2;i<=n;i++)
        {
            dp[i][1]=max(dp[i-1][1]+abs(b[i]-b[i-1]) , dp[i-1][0]+abs(b[i]-1));//选i
            dp[i][0]=max(dp[i-1][1]+abs(1-b[i-1]) , dp[i-1][0]);//不选i
//            dp[i][1]=dp[i-1][0]+abs(b[i]-1);//选i
//            dp[i][0]=dp[i-1][1]+abs(1-b[i-1]);//不选i  贪心 错的
        }
        printf("%d\n",max(dp[n][0],dp[n][1]));
    }
}