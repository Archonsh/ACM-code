#include <cstdio>
#include <queue>
using namespace std;
#define MAXN 10000
int root[MAXN];
struct node{
    int u,v,len;
    bool operator < (const node &t) const
    {return len>t.len;}};
priority_queue<node>q;//默认大根堆
int unionset(int x) {return root[x]==x?root[x]:root[x]=unionset(root[x]);}
int main()
{
    node tmp;
    int n,m,i,sum=0,t=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        root[i]=i;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&tmp.u,&tmp.v,&tmp.len);
        q.push(tmp);
    }
    for(i=1;i<=m;i++)
    {
        tmp=q.top();
        q.pop();
        if(unionset(root[tmp.u])!=unionset(root[tmp.v])){
            root[unionset(root[tmp.u])]=unionset(root[tmp.v]);
            sum+=tmp.len;t++;}
        if(t==n-1) break;
    }
    printf("%d",sum);
    return 0;
}