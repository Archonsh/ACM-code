#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

#define mm(a,i) memset(a,i,sizeof(a))
int n,m,ind=1,blk=1;
bool vis[5000],instack[5000];
vector<int>map[5000],scc[5000];
stack<int>s;
struct node{int ind,low;}v[5000];

void scctarjan(int q)  //强连通tarjan--dfs
{
    vis[q]=instack[q]=1;
    v[q].ind=v[q].low=ind++;
    s.push(q);
    int len=map[q].size(),i,j,t;
    for(i=0;i<len;i++)
    {
        int w=map[q][i];
        if(!vis[w])
        {
            scctarjan(w);
            v[q].low=min(v[q].low,v[w].low);
        }
        else if(instack[w])
        {
            v[q].low=min(v[q].low,v[w].ind);
        }
    }
    if(v[q].low==v[q].ind)
    {
        t=s.top();
        s.pop();
        scc[blk].push_back(t);
        while(v[t].ind!=v[q].ind)
        {
            t=s.top();
            s.pop();
            scc[blk].push_back(t);
        }
        blk++;
    }
}

int main() {
    int i,j,a,b,c;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        map[a].push_back(b);
    }
    mm(vis,0);
    mm(instack,0);
    for (i=1;i<=n;i++)
    {
        if(!vis[i])
            scctarjan(i);
    }
    printf("%d",blk);
    return 0;
}