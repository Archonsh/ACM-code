/*
 * 不要只focus on vertices
 * 考虑边的关系
 *
 * 如果一条边两端颜色不相同  那么一定 不可能在一个子树
 * 即其中一定有一点为root
 *
 */
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int>map[100005];
int root[100005];
int main() {
    int n,i,j,a,b,pair=0;
    scanf("%d",&n);
    memset(root,0,sizeof(root));
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        map[a].push_back(b);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        map[i].push_back(a);   //map[i][map[i].size()-1] is color of the node
    }
    for(i=1;i<=n;i++)
    {
        a=map[i].size();
        for(j=0;j<a-1;j++)
        {
            b=map[i][j];
            if(map[i][a-1]!=map[b][map[b].size()-1])
            {
                root[i]++;
                root[b]++;
                pair++;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(root[i]==pair)
        {
            printf("YES\n%d",i);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}