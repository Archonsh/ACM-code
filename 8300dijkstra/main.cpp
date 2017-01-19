#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define mm(a,i) memset(a,i,sizeof(a))
#define MAXN 10000
int n,m,dis[MAXN];
struct node{
    int u;
    bool operator < (const node &t) const
    {return dis[u]>dis[t.u];}};
priority_queue<node>q;
struct mymap {int v,dis;};
vector<mymap>mmap[MAXN];
void dj()
{
    mymap tmp;
    node t1;
    int i,v,len,u;
    while(!q.empty())
    {
        u=q.top().u;
        q.pop();
        len=mmap[u].size();
        for(i=0;i<len;i++)
        {
            tmp=mmap[u][i];
            if(dis[u]+tmp.dis<dis[tmp.v])
            {dis[tmp.v]=dis[u]+tmp.dis;
             t1.u=tmp.v;q.push(t1);}
        }
    }
}
int main() {
    mm(dis,0x3f);
    dis[1]=0;
    mymap tmp;
    int i,t1,t2;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&t1,&tmp.v,&tmp.dis);
        mmap[t1].push_back(tmp);
        t2=tmp.v;tmp.v=t1;t1=t2;
        mmap[t1].push_back(tmp);
    }
    node u1;u1.u=1;q.push(u1);
    dj();
    printf("%d",dis[n]);
    return 0;
}