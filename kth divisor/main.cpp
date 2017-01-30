#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
vector<long long>q;
int main() {
    long long n,k,i,j,div=0,flag=0;
    cin>>n>>k;
    if(k==1) {printf("1");return 0;}
    double sq=sqrt(n);
    if(abs(floor(sq)*floor(sq)-n)<1e-6)
        flag=1;
    q.push_back(0);
    for(i=1;i<=sq;i++)
    {
        if(n%i==0)
        {
            div++;
            q.push_back(i);
            if(div == k)
            {
                cout<<i;
                return 0;
            }
        }
    }

    if((q.size()-1)*2 < k && !flag)
    {
        printf("-1");
        return 0;
    }

    if((q.size()-1)*2 <= k && flag)
    {
        printf("-1");
        return 0;
    }

    if(flag) //对称
    {
        div=(q.size()-1)-(k-(q.size()-1));
        cout<<n/q[div];
        return 0;
    }
    else
    {
        div=2*(q.size()-1)+1-k;
        cout<<n/q[div];

    }

    return 0;
}