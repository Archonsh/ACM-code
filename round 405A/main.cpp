#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    long long a,b,i,j;
    cin>>a>>b;
    i=0;
    while(a<=b)
    {
        i++;
        a*=3;
        b*=2;
    }
    cout<<i;
    return 0;
}