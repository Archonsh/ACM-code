/*
 * 10^6 是 1000000 6个零 数据范围-->数组大小出错
 * 此题O(n^2)解法TLE
 *
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,a[1000005],i,j=0,dp[1000005],b[1000005];
void ON_2() {
    int cmax=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        dp[i] = 1;
    }
    for(i=2;i<=n;i++)
    {
        for(j=i-1;j>=1;j--)
        {
            if(a[j]<a[i] && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                //不能剪枝 第一个比他小的 不一定是前面最大的 1 2 3 2 5
            }
            cmax=max(cmax,dp[i]);
        }
    }
//    for(i=1;i<=n;i++)
//        printf("%d\n",dp[i]);
    printf("%d",cmax);
    return;
}


void ONlogN()
{
    int ptr=1,pos;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d", &a[i]);
    b[1]=a[1];
    for(i=2;i<=n;i++)
    {
        if(b[ptr]<a[i])
            b[++ptr]=a[i];
        else
        {
            pos=lower_bound(b+1,b+ptr+1,a[i])-b; //[b[1],b[ptr+1]) - b数组的开头位置b[0]

//            这里一定要用lower_bound 因为如果a[i]=b[j] upper_bound会导致b[j+1]被修改 eg:1 3 5 3 4 5 b[2]=b[3]=3 导致多算一次
//            time complexity is of O(logN) by binary search
//            parameter:
//            first iterator,last iterator,value,(compare function/operator <)
//            前开后闭区间 [first,last) 记得 加1/不加1
//            upper_bound 找比val大的第一个数    return iterator
//            lower_bound 找不小于val的第一个数  return iterator
//            binary_search 找和val一样的数     return bool
            b[pos]=a[i];
        }
    }
    printf("%d\n",ptr);
}


int main()
{
    ONlogN();
    return 0;
}