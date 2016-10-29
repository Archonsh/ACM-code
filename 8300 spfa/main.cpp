#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN 10
#define INF 0x3f3f3f3f
#define l(i) -log(i)
int vis[MAXN],n=6;
double d[MAXN],w[MAXN][MAXN];
void SPFA(int s)
{
    d[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=1; v<=n; v++)
        {
            if(d[v]>d[u]+w[u][v])
            {
                d[v]=d[u]+w[u][v];
                //printf("u:%d->v:%d d[%d]:%f\n",u,v,d[v],v);
                q.push(v);

            }
        }
    }
}
void bf(int s)
{
    d[s]=0;
    int round=5,i,j,k;
    while(round--)
    {
        printf("round:%d\n",5-round);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                 if(d[i]>d[j]+w[j][i])
                     d[i]=d[j]+w[j][i];
            }
        for(i=1;i<=n;i++)
        {
            printf("i:%d %f\n",i,d[i]);
        }
        printf("\n");
    }
}
int main()
{
    int i,j;
    memset(vis,0,sizeof(vis));
    for(i=0;i<=10;i++)
        for(j=0;j<=10;j++)
        {w[i][j]=1000000000;d[i]=1000000000;}
    w[1][2]=l(0.693);
    w[1][4]=l(0.501);
    w[1][6]=l(4.671);
    w[2][1]=l(1.382);
    w[2][4]=l(0.696);
    w[2][5]=l(10076.400);
    w[3][1]=l(0.330);
    w[4][1]=l(1.947);
    w[4][2]=l(1.387);
    w[4][6]=l(9.141);
    w[5][1]=l(0.00008);
    w[5][3]=l(0.0005);
    w[6][1]=l(0.204);
    w[6][4]=l(0.1);
    //SPFA(1);
    bf(1);
    for(i=1;i<=6;i++)
        printf("%f\n",d[i]);
    return 0;

}