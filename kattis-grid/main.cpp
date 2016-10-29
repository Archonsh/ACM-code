/*
根据点的关系来建图
SPFA或者Dj都可以过

run time error通常是内存超界/爆炸了
注意数据范围:500*500=250000

https://open.kattis.com/problems/grid
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define mm(a,i) memset(a,i,sizeof(a))
using namespace std;
int d[250005],n,m,vis[250005];
vector<int>mmap[250005];
queue<int>q;
struct node {
    int point;
    bool operator < (const node &a) const
        {return d[a.point]<d[point];}
};
//priority_queue<node>q;
void spfa(int s)
{
    int i,j,p,total=n*m,len,to;
    d[s]=0;
    q.push(s);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        len=mmap[p].size();
        for(i=0;i<len;i++)
        {
            to=mmap[p][i];
            if(d[to]>d[p]+1)
            {
                d[to]=d[p]+1;
                q.push(to);
            }
        }
    }
}
/*void dj(int s)
{
    int i,p,len,to;
    node poi;
    d[s]=0;
    vis[s]=1;
    poi.point=s;
    q.push(poi);
    while(!q.empty())
    {
        poi=q.top();
        p=poi.point;
        q.pop();
        len=mmap[p].size();
        for(i=0;i<len;i++)
        {
            to=mmap[p][i];
            if(d[to]>d[p]+1)
            {
                d[to]=d[p]+1;
                if(!vis[to])
                {
                    poi.point=to;
                    q.push(poi);
                    vis[to]=1;
                }
            }
        }
    }
}*/
int main() {
    int i,j,k,tmp,p;
    char ch;
    mm(d,63);
    mm(vis,0);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) {
        scanf("%c",&ch);
        for (j = 1; j <= m; j++)
        {
            scanf("%c", &ch);
            tmp=ch-48;
            if(!tmp) continue;
            p = (i - 1) * m + j;
            if (i - tmp >= 1) mmap[p].push_back(p - tmp * m);
            if (i + tmp <= n) mmap[p].push_back(p + tmp * m);
            if (j - tmp >= 1) mmap[p].push_back(p - tmp);
            if (j + tmp <= m) mmap[p].push_back(p + tmp);
        }
    }
    spfa(1);
    //dj(1);
    if(d[m*n]<0x3f3f3f3f)
        printf("%d",d[m*n]);
    else
        printf("-1");
    return 0;
}