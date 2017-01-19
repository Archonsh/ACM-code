#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define mm(a,i) memset(a,i,sizeof(a))
long long T,n,ch[20005],i,j,sum,op[20005],diff,ans,offset=0,tans;

int main() {
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>ch[i];
        sum=0;mm(op,0);
        sort(ch,ch+n+1);//!!!!!从1~n排序是ch,ch+n+1!!!!!

        for(i=2;i<=n;i++)
        {
            diff=ch[i]-ch[i-1]+sum;
            sum=0;
            op[i]=op[i]+(diff/5)*5;diff%=5;
            op[i]=op[i]+(diff/2)*2;diff%=2;
            op[i]+=diff;diff=0;
            sum=op[i];

        }
        ans=0;tans=0x3f3f3f3f;offset=0;
        while(offset<5)
        {
            for(i=1;i<=n;i++)
            {
                ans=ans+(op[i]+offset)/5+((op[i]+offset)%5)/2+(((op[i]+offset)%5)%2);
            }
            tans=min(tans,ans);
            offset++;ans=0;
        }
        cout<<tans<<endl;
    }
    return 0;
}