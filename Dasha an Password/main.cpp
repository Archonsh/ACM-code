#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
char ch[55][55];
struct node{
    int val,pos;
    bool operator <  (node a) const
    {
        return a.val>val;
    }
}dmin[55],amin[55],chmin[55];
int ans=0x3f3f3f3f,n,m;
void dfs(int a,int b,int c)
{
    if(a==n || b==n || c==n)
        return;
    if(dmin[a].pos!=amin[b].pos && dmin[a].pos!=chmin[c].pos && amin[b].pos!=chmin[c].pos)
    {
        ans=min(ans,dmin[a].val+amin[b].val+chmin[c].val);
        return;
    }
    dfs(a+1,b,c);
    dfs(a,b+1,c);
    dfs(a,b,c+1);
}
int main() {
    int i,j,a,b,c;
    node tmp;
    scanf("%d%d",&n,&m);
    getchar();///!!!!!!!!
    for(i=1;i<=n;i++)
    {
        gets(ch[i]);
    }

    for(i=1;i<=n;i++)
    {
        a=b=c=0x3f3f3f3f;
        for(j=0;j<m;j++)
        {

            if(isdigit(ch[i][j]))
            {
                a=min(a,min(j,m-j));
            }
            else if(isalpha(ch[i][j]))
            {
                b=min(b,min(j,m-j));

            }
            else if(ch[i][j]=='#' || ch[i][j]=='*' || ch[i][j]=='&')
            {
                c=min(c,min(j,m-j));
            }
        }
        tmp.pos=i;
        tmp.val=a;
        dmin[i]=tmp;
        tmp.val=b;
        amin[i]=tmp;
        tmp.val=c;
        chmin[i]=tmp;
    }
    sort(dmin+1,dmin+n+1);
    sort(amin+1,amin+n+1);
    sort(chmin+1,chmin+n+1);
    dfs(1,1,1);
    printf("%d",ans);
    return 0;
}