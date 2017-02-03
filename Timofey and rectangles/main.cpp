#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
    int x,y,a,b;
}cd[500005];
vector<int>map[500005];
struct ins{
    int v,pos;
    bool operator <  (const ins &a) const
    {
        return a.v<v;
    }

}ind[500005];
int n,color[500005],flag=0;

void bfs(int p)
{
    if(color[p]==0)
    {
        color[p]=1;
    }
    int i,j,len=map[p].size();
    for(i=0;i<len;i++)
    {
        if(!color[map[p][i]])
        {
            color[p]=2;
        }
        else
        {
            if(color[p]==color[map[p][i]])
            {
                color[map[p][i]]++;
                if(color[map[p][i]>4])
                {
                    printf("NO\n");
                    return;
                }
            }
        }
    }
}
int main() {
    int i,j;
    scanf("%d",&n);
    memset(ind,0,sizeof(ind));
    memset(color,0,sizeof(color));
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&cd[i].x,&cd[i].y,&cd[i].a,&cd[i].b);
        ind[i].pos=i;
    }

    for(i=1;i<n;i++) {
        for (j = i + 1; j <= n; j++) {
            if (!(cd[i].x - cd[j].x) || !(cd[i].x - cd[j].a) || !(cd[i].a - cd[j].x) || !(cd[i].a - cd[i].x)) {
                if ( (cd[i].x <= cd[j].x && cd[j].x < cd[i].a) || (cd[i].x < cd[j].a && cd[j].a <= cd[i].a)) {
                    map[i].push_back(j);
                    map[j].push_back(i);
                    ind[i].v++;
                    ind[j].v++;
                }
            }
            else if (!(cd[i].y - cd[j].b) || !(cd[i].y - cd[j].y) || !(cd[i].b - cd[j].b) || !(cd[i].b - cd[j].y)) {
                if ( (cd[i].y <= cd[j].y && cd[j].y < cd[i].b) || (cd[i].y < cd[j].b && cd[j].b <= cd[i].b)) {
                    map[i].push_back(j);
                    map[j].push_back(i);
                    ind[i].v++;
                    ind[j].v++;
                }
            }

        }
    }
    sort(ind+1,ind+n+1);
    for(i=1;i<=n;i++)
    {
        flag=0;
        bfs(ind[i].pos);
    }
    for(i=1;i<=n;i++)
        printf("%d\n",color[i]);
    return 0;
}