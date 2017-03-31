/*
 * 老老实实的写正常的并查集
 * 开3个数组
 * 分别保存 father father集合的大小和 和连接的点数
 * 路径压缩总是可以连到根或者 根-1节点上
 *
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
#define MAXN 150005  //使用MAXN来表示范围
int f[MAXN],con[MAXN],size[MAXN];

int find(int x)
{
    if(f[x]!=x)
        f[x]=find(f[x]);
    return f[x];
}

int main() {
    int n,m,i,j=0,t,p,len,k,cnt=0,tmp;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        f[i]=i;
        size[i]=1;
    }
    memset(con,0,sizeof(con));

    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&t,&p);
        if(f[t]!=f[p])
        {
            //size[f[find(f[p])]]+=size[f[find(f[t])]];
            f[find(f[t])]=find(f[p]);
        }
        con[t]++;
        con[p]++;

//        if(!f[t] && !f[p])
//        {
//            cnt++;
//            f[t]=f[p]=cnt;
//            uni[cnt].push_back(t);
//            uni[cnt].push_back(p);
//            valid[cnt]=1;
//        }
//
//        else if(f[t]==f[p])
//            continue;
//
//        else if(f[t] && f[p])
//        {
//            tmp=f[p];
//            uni[f[t]].insert(uni[f[t]].begin(),uni[f[p]].begin(),uni[f[p]].end());
//            valid[f[p]]=0;
//            for(k=0;k<uni[f[p]].size();k++)
//                f[ uni[f[p]][k] ] = f[t];  //这一步 合并数组会超时 考虑最坏的情况 约等于150000^2次修改
//            uni[tmp].clear();
//            uni[tmp].shrink_to_fit();
//
//        }
//
//        else if(f[t])
//        {
//            f[p]=f[t];
//            uni[f[t]].push_back(p);
//        }
//
//        else if(f[p])
//        {
//            f[t]=f[p];
//            uni[f[p]].push_back(t);
//        }

    }
    //f是并茶几
    for(i=1;i<=n;i++)
    {
        if(f[i]!=i)
            size[f[find(f[i])]]++;
    }

    for(i=1;i<=n;i++)
    {
        len=size[find(f[i])]-1;
        if(con[i]!=len)
        {
            printf("no\n");
            return 0;
        }
    }
    printf("yes\n");
    return 0;
}
/*
 *
7 9
1 2
3 4
5 6
1 3
1 4
2 4
3 2
5 7
6 7
 * */