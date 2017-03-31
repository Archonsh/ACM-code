#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAXN 7005
#define WIN 99999
#define LOSE -99999
using namespace std;

int m[MAXN],r[MAXN],obj;
vector<int>s1, s2;

void s(int p, int who)
{
    if(who)//mortys turn
    {

    }
    else  //rick
    {

    }
}
int main()
{
    int i,j,k,t,len,flag;
    scanf("%d",&obj);
    scanf("%d",&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d",&t);
        s1.push_back(t);
        m[obj-t+1]=WIN;
    }
    scanf("%d",&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d",&t);
        s2.push_back(t);
        r[obj-t+1]=WIN;
    }
    for(i=2;i<=obj;i++) // cur position
    {
        if(m[i]!=WIN || m[i]!=LOSE)
        {
            flag=1;
            len=s2.size();
            for(j=0;j<len;j++)
            {
                if(r[i+s2[j]]==WIN)
                    continue;
                else{
                    flag=0;
                    dfs(i+s2[j],0);
                }
            }
            if(flag)
                m[i]=LOSE;
        }
    }
    return 0;
}