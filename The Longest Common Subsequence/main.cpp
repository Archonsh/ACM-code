/*
 * 顺序找到a串中的每一个字母在b串的位置
 * 然后遍历字母i前的所有字母 找到前i-1个的最长公共字串
 * 保存转移后的状态
 * 输出长度最长的串
 *
 * dp[i][j]=[前i个字符][选择第i个字符 在b中的 第j次出现位置]的最长值
 * dp[i][j]=max(dp[1...i-1][k])+1
 *
 */


#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct pos
{
    int p,v;        // position , max length
    vector<int>ans;
};
vector<pos>dp[105];
int main()
{
    int n,m,a[105],i,j,k,t,len,cmax=0,kk,tt;
    vector<int>b[1005];
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&k);
        b[k].push_back(i);
    }
    pos tmp;
    tmp.p=0;
    tmp.v=0;
    dp[0].push_back(tmp);

    for(i=1;i<=n;i++) //traversal a[]
    {
        len=b[a[i]].size();
        for(j=0;j<len;j++) // dp[][j] position j of a[i] in b
        {
            //position of number a[i] is b[j]
            tmp.p=b[a[i]][j];
            tmp.v=1;
            for(k=i-1;k>=0;k--)  //find the longest subseq of first (i-1) number of a
            {

                for(t=0;t<dp[k].size();t++)//length of choose subseq a[k] at t position of b
                {
                    if(b[a[i]][j] > dp[k][t].p && dp[k][t].v+1>tmp.v)
                    {
                        tmp.v=dp[k][t].v+1;
                        tmp.ans=dp[k][t].ans;         // 保存由什么状态转移而来
                        //vector 复制 直接用 =
                        tmp.ans.push_back(a[i]);      // 加上自己
                    }

                }
            }
            if(tmp.v>cmax)
            {
                cmax=tmp.v;
                kk=i;
                tt=j;
            }
            if(tmp.v==1)
                tmp.ans.push_back(a[i]);
            dp[i].push_back(tmp);
        }
    }
    //printf("%d\n",cmax);
    for(i=0;i<dp[kk][tt].ans.size();i++)
        printf("%d ",dp[kk][tt].ans[i]);
    return 0;
}