/*
 * divisor of a number is always PAIRED
 * only concern is whether sqrt(N) is a divisor, as it pairs itself
 * O(logN)
 */

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
    if(abs(floor(sq)*floor(sq)-n)<1e-6) //judge whether sqrt(N) is a divisor. IF YES, flag = 1
        flag=1;


    for(i=1;i<=sq;i++)
    {
        if(n%i==0)
        {
            div++;          //number of divisors
            q.push_back(i); //record this divisor in q
            if(div == k)
            {
                cout<<i;
                return 0;
            }
        }
    }

    if(q.size()*2 < k && !flag) //number N has less than 2*q.size() divisors
    {
        printf("-1");
        return 0;
    }

    if(q.size()*2 <= k && flag)
    {
        printf("-1");
        return 0;
    }

    if(flag) //divisors are symmetric about sqrt(N) @ q.end()
    {
        div=q.size()-(k-q.size())-1;
        cout<<n/q[div];
        return 0;
    }
    else
    {
        div=q.size()-(k-(q.size()+1))-1;
        cout<<n/q[div];

    }

    return 0;
}