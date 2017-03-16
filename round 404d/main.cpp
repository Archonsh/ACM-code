#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
//#include <iostream>
#define MAXN 1000000007
using namespace std;
bool map[200005];
vector<int>v0,v1;

int arg(int n,int m)
{
    if(n<m)
        return 0;
    int i,ans=1,p=m;
    for(i=n;i>=n-m+1;i--)
    {
        ans=(ans*i/p)%MAXN;
        p--;
        if(p<1) p=1;
    }
    return ans;
}

int main() {
    char ch;
    int i,j,len=0,v0len,p,tmp,v1len,ans=0;
    while(scanf("%c",&ch),ch!='\n')
    {
        if(ch=='(')
        {
            map[len]=0;
            v0.push_back(len);
        }
        else
        {
            map[len]=1;
            v1.push_back(len);
        }
        len++;
    }
    // 后面0的个数 v0.size()-i
    v0len=v0.size();
    v1len=v1.size();
    for(i=0;i<v0len;i++)
    {
        p=v0[i]; //position of current 0
        tmp=upper_bound(v1.begin(),v1.end(),p)-v1.begin();
        tmp=v1len-tmp;//后面的1
        for(j=1;j<=i+1;j++)
        {
            if(tmp<j) break;
            ans=ans+arg(tmp,j)%MAXN;
        }
    }
    printf("%d",ans%MAXN);
    return 0;
}