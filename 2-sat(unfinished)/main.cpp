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
vector<int>mmap[16005],ctr[16005],scc[16005],ncc[16005],xy;
stack<int>s;
struct node{int low,t;}vis[16005];
int idx=1,np=1,bcc[16005],n,m,tp[16005],sel[16005];
bool instack[16005];
void ini()
{
    for(int i=0;i<16005;i++)
    {mmap[i].clear();
    ctr[i].clear();
    scc[i].clear();
    ncc[i].clear();
    }
    xy.clear();
    mm(tp,0);
    mm(sel,0);
    mm(vis,0);
    mm(instack,0);
}

void tarjan(int x)
{
    vis[x].low=vis[x].t=idx++;
    s.push(x);
    instack[x]=1;
    int i,len=mmap[x].size(),k;
    for(i=0;i<len;i++)
    {
        k=mmap[x][i];
        if(!vis[k].t)
            {tarjan(k);vis[x].low = min(vis[k].low, vis[x].low);}
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
        np++;//np是新联通块的计数器
    }
    return;
}

void tpsort()
{
    queue<int>q;
    int xin[16005],i,j,k,len,p;
    mm(xin,0);
    for(i=1;i<np;i++)  // 第i个联通分量
    {
        len=scc[i].size();
        for(j=0;j<len;j++) // 分量內第j点
        {
            p=scc[i][j];        //p是原图中的某个点
            for(k=0;k<mmap[p].size();k++)   //原图中p可以到的点
            {
                if (bcc[p] != bcc[mmap[p][k]]) //不在同一联通分量
                    {ncc[bcc[mmap[p][k]]].push_back(bcc[p]);xin[bcc[p]]++;}   //reverse order 入度+1
            }
        }
    }
    for(i=1;i<np;i++)
    {
        if(!xin[i])q.push(i); //入度为0
    }
    while(!q.empty())
    {
        p=q.front();        //p=一个联通block
        q.pop();
        tp[idx++]=p;
        len=ncc[p].size(); //(ncc保存的联通块之间的路径)
        for(i=0;i<len;i++)
        {
            xin[ncc[p][i]]--;  //入度-1
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

    while(~scanf("%d%d",&n,&m))
    {
      ini();
        for(i=1;i<=2*n;i+=2)
    {
        mmap[2*i].push_back(2*i+1);
        mmap[2*i+1].push_back(2*i);
        mmap[2*i+2].push_back(2*i-1);
        mmap[2*i-1].push_back(2*i+2);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        x*=2;
        y*=2;
        mmap[x].push_back(y-1);
        mmap[y].push_back(x-1);
        xy.push_back(x);
        xy.push_back(y);
    }
    mm(vis,0);
    for(i=1;i<=4*n;i++)
        if(!vis[i].t) {tarjan(i);}//缩点 新图G(V,E)=ncc{tpsort();} 原图-->新图 bcc 新图-->原图 scc
//    for (i=1;i<np;i++)
//    {
//        printf("\n");
//        for (j=0;j<scc[i].size();j++)
//            printf("%d ",scc[i][j]);
//    }
    k=0;
    for(i=1;i<=4*n;i+=2) //判断A和~A的矛盾 初始化矛盾数组ctr
    {
        if (bcc[i] == bcc[i + 1]) {printf("NIE1\n");k = 1;break;}
        ctr[bcc[i]].push_back(bcc[i + 1]);
        ctr[bcc[i + 1]].push_back(bcc[i]);
    }
    if(k) continue;
    for(i=0;i<2*m;i+=2)//判断给定m组矛盾 初始化矛盾数组ctr  (ctr里面有重复的矛盾)
    {
        if( bcc[xy[i]]==bcc[xy[i+1]]){printf("NIE2\n");k=1;break;} //X&~Y ~X&Y
        ctr[bcc[xy[i]]].push_back(bcc[xy[i+1]]);
        ctr[bcc[xy[i+1]]].push_back(bcc[xy[i]]);
    }
    if(k) continue;

    idx=1;
    tpsort(); //生成反图ncc 并 拓扑排序 结果存在tp里面 tp[1]是逻辑最先的
    mm(sel,0);
    for(i=1;i<np;i++) //生成方案<bool>sel  用<bool>instack 表示是否访问过 从tp[1]开始遍历
    {
        if(sel[tp[i]]) continue; //已经标为选/不选了
        x=tp[i];
        //instack[x]=1;
        len=ctr[x].size();  //第x号联通分量的矛盾
        sel[x]=1;           //选x
        for(j=0;j<len;j++)  //所有矛盾块
            if(!sel[ctr[x][j]]) bfs(ctr[x][j]);
    }
    xy.clear();
    for(i=1;i<np;i++)
    {
        if(sel[i]==1)
            for(j=0;j<scc[i].size();j++)
                if(scc[i][j]%2==0)
                    xy.push_back(scc[i][j]/2);
    }
    sort(xy.begin(),xy.end());
    for(i=0;i<xy.size();i++)
        printf("%d\n",xy[i]);
    }
    return 0;
}