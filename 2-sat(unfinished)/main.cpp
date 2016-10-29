#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
#include<unordered_map>
#define INF 0x3f3f3f3f
#define eps 1e-9
#define MOD 1000000007
#define MAXN 400005
#define mm(a,x) memset(a,x,sizeof(a))
using namespace std;
vector<short int>mmap[16005],ctr[16005],scc[16005],ncc[16005],xy;
stack<short int>s;
struct node{int low,t;}vis[16005];
int idx=1,np=1,bcc[16005],n,m,tp[16005],bnum;
bool instack[16005],sel[16005];
void tarjan(int x)
{
    vis[x].low=vis[x].t=idx;
    idx++;
    s.push(x);
    instack[x]=1;
    int i,len=mmap[x].size(),k;
    for(i=0;i<len;i++)
    {
        k=mmap[x][i];
        if(!vis[k].t) {tarjan(k);vis[x].low = min(vis[k].low, vis[x].low);}
        else if(instack[k])
            vis[x].low = min(vis[k].t, vis[x].low);
    }
    if(vis[x].t==vis[x].low)
    {
        while(s.top()!=x)
        {
            scc[np].push_back(s.top());
            instack[s.top()]=0;
            bcc[s.top()]=np;
            s.pop();
        }
        scc[np].push_back(x);
        s.pop();
        instack[x]=0;
        bcc[x]=np;
        np++;
    }
    return;
}

void tpsort()
{
    queue<int>q;
    int xin[16005],i,j,k,len,p;
    mm(xin,0);
    for(i=1;i<=2*n+1;i++)  // 第i个联通分量
    {
        len=scc[i].size();
        if(!len) {bnum=i-1;break;}
        for(j=0;j<len;j++) // 分量內第j点
        {
            p=scc[i][j];
            for(k=0;k<mmap[p].size();k++) {
                if (bcc[p] != bcc[mmap[p][k]])
                {ncc[bcc[mmap[p][k]]].push_back(bcc[p]);xin[bcc[p]]++;}   //reverse order 入度+1
            }
        }
    }
    for(i=1;i<=bnum;i++)
    {
        if(xin[i]==0)q.push(i);
    }
    while(!q.empty())
    {
        p=q.front();//p block G(ncc)
        q.pop();
        tp[idx++]=p;
        len=ncc[p].size();
        for(i=0;i<len;i++)
        {
            xin[ncc[p][i]]--;
            if(!xin[ncc[p][i]])q.push(ncc[p][i]);
        }
    }
    return;
}
void bfs(int p)//传递 不选择标记
{
    int i,j,len=ncc[p].size();
    for(i=0;i<len;i++)
        bfs(ncc[p][i]);
    sel[p]=-1;
    return;
}


int main()
{
    int i,j,x,y,len,k;
    mm(scc,0);mm(instack,0);mm(bcc,0);
    scanf("%d%d",&n,&m);
    for(i=1;i<4*n;i+=4)
    {
        mmap[i].push_back(i+3);
        mmap[i+3].push_back(i);
        mmap[i+2].push_back(i+1);
        mmap[i+1].push_back(i+2);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        x=(x+1)/2*4-((x%2)*2+1);
        y=(y+1)/2*4-((y%2)*2+1);
        mmap[x].push_back(y+1);
        mmap[y].push_back(x+1);
        xy.push_back(x);
        xy.push_back(y);
    }
    for(i=1;i<=4*n;i++)
        if(!vis[i].t) {tarjan(i);}//缩点 新图G(V,E)=ncc{tpsort();} 原图-->新图 bcc 新图-->原图 scc

    for(i=1;i<=4*n;i+=2) //判断A和~A的矛盾 初始化矛盾数组ctr
    {
        if (bcc[i] == bcc[i+1]) {printf("NIE");return 0;}
        ctr[bcc[i]].push_back(bcc[i+1]);
        ctr[bcc[i+1]].push_back(bcc[i]);
    }
    for(i=0;i<2*m;i+=2)//判断给定m组矛盾 初始化矛盾数组str
    {
        if( bcc[xy[i]]==bcc[xy[i+1]]){printf("NIE");return 0;} //X&~Y ~X&Y
        ctr[bcc[xy[i]]].push_back(bcc[xy[i+1]]);
        ctr[bcc[xy[i+1]]].push_back(bcc[xy[i]]);
    }
    idx=1;
    tpsort(); //生成反图ncc 并 拓扑排序 结果<queue>tp
    mm(instack,0);mm(sel,0);
    for(k=1;k<=bnum;k++) //生成方案<bool>sel  用<bool>instack 表示是否访问过
    {
        if(instack[tp[k]]) continue;
        x=tp[k];
        instack[x]=1;
        len=ctr[x].size();
        sel[x]=1;
        for(i=0;i<len;i++) //所有矛盾块
            if(!instack[ctr[x][i]]) bfs(ctr[x][i]);
    }
    for(i=1;i<=bnum;i++)
        printf("%d",sel[i]);
    return 0;
}