#include <iostream>
#include <queue>
using namespace std;
struct edge{
    int x,y,v;
    bool operator < (const edge &a) const
        {return v<a.v;}
};
priority_queue<edge>q;
int map[20][20],fa[20];
void unionset(int s)
{
    if (fa[s]==s) return s;
    return
}
int main() {
    int i,j,k;
    edge tmp;
    for(i=1;i<=10;i++) {
        fa[i]=i;
        for (j = 1; j <= 10; j++) {
            scanf("%d", &map[i][j]);
            tmp.x=i;
            tmp.y=j;
            tmp.v=map[i][j];
            q.push(tmp);
        }
    }
    kruskal();
    return 0;
}