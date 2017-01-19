/*
 3 2
1 2 0 -100000000
2 3 -100000000 0
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;
#define mm(a,i) memset(a,i,sizeof(a))
int k,m,por[10],tox[10],fei,jian;
struct node{int re,toxic;}dp[1000][260];
int dtb(int q)
{
    int s=0;
    while(q>0)
    {
        s=s*10+q%2;
        q/=2;
    }
    return s;
}

int bcount(int q)
{
    int s=0;
    while(q>0)
    {
        s=s+q%2;
        q/=2;
    }
    return s;
}

int btd(int q)
{
    int s=0,t=1;
    while (q>0)
    {
        s=s+(q%10)*t;
        t*=2;
        q/=10;
    }
    return s;
}

int usepor(int p, int q)//p状态 用第q个药
{
    p=dtb(p);
    q=dtb(1<<(q-1));
    if(p&q)
        return (btd(p)-btd(q));
    if(!bcount(p))
        return btd(p);
    return -1;
}
node xmax(node a,node b)
{
    if(a.re>b.re)
        return a;
    return b;
}
bool val(int q,int p)
{
    q=dtb(q);
    p=dtb(p);
    int flag=0;
    while(flag<2 && p>0 && q>0)
    {
        if(q%10==p%10)
            flag++;
        q/=10;
        p/=10;
    }
}
int main()
{
    int i,j,test,portionnumber,num=0,flag=1;
    node t,t1;
    por[0]=0;
    tox[0]=0;
    scanf("%d",&test);
    while(test--)
    {
        mm(dp,0);
        scanf("%d%d%d",&k, &m,&portionnumber);
        for (i = 1; i<=portionnumber; i++)
            scanf("%d",&por[i]);
        for(i=1;i<=portionnumber;i++)
            scanf("%d",&tox[i]);
        t.re=100;
        t.toxic=0;
        for(i=0;i<=260;i++)
            dp[0][i]=t;
        while(++num && flag) //怪兽
        {
            flag=0;
            for(i=0;i<(1<<portionnumber);i++) //portion 状态i
            {
                if(bcount(i)>num) continue;
                for(j=0;j<=portionnumber;j++) //portion 原状态位置
                {
                    if(num==1 && j!=0) break;
                    if(val(i,j)) break;

                    t.re=por[j];
                    t.toxic=tox[j];



                    t1=dp[num-1][usepor(i,j)];

                    if(t1.re-k<0) continue;
                    t1.re=min(100,t1.re-k+t.re);

                    if(t1.toxic-m+t.toxic>=100) continue;
                    t1.toxic=max(t.toxic,t1.toxic+t.toxic-m);

                    dp[num][i]=xmax(dp[num][i],t1);//num-1-k>0
                    flag=1;
                }

            }
        }
        printf("%d\n",num);
    }

    return 0;
}