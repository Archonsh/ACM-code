#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int n,i,j;
    long long ans=0;

    scanf("%d",&n);
    char a[1000];
    gets(a);
    for(i=1;i<=n;i++)
    {
        char ch[1000];
        gets(ch);
        if(ch[0]=='T')
            ans+=4;
        if(ch[0]=='C')
            ans+=6;
        if(ch[0]=='O')
            ans+=8;
        if(ch[0]=='D')
            ans+=12;
        if(ch[0]=='I')
            ans+=20;
    }
    cout<<ans<<endl;
    return 0;
}