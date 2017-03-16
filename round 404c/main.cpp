#include <cstdio>
#include<iostream>
using namespace std;

int main() {
    unsigned long long n,m,diff,xmax=10000000000,xmin=0,mid;
    cin>>n>>m;
    if(n<=m)
    {
        cout<<n<<endl;
        return 0;
    }
    diff=n-m;
    while(xmin<=xmax)
    {
        mid=(xmax+xmin)/2;
        if(diff == ((mid+1)*mid)/2 ) //right
        {
            cout<<mid+m;
            return 0;
        }
        else if( diff < ((mid+1)*mid)/2) //bigger
        {
            xmax=mid-1;
        }
        else
            xmin=mid+1;
    }
    cout<<xmax+1+m;
    return 0;
}