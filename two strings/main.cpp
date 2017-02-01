#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
string a,b;
int main() {
    int n,i,j,k,t,count=1,ptr=0,front_p,end_p,bfront,bend;
    cin>>a;
    cin>>b;
    for(i=0;i<b.size();i++)
    {
        while(ptr<a.size())
        {
            if(a[ptr]==b[i])
            {
                front_p=ptr++;
                bfront=i;
                break;
            }
            ptr++;
        }
    }
    ptr=a.size()-1;
    for(i=b.size()-1;i>=0;i--)
    {
        while(ptr>=0)
        {
            if(a[ptr]==b[i])
            {
                end_p=ptr--;
                bend=i;
                break;
            }
            ptr--;
        }
    }
    if(bfront>=bend)
        cout<<b;
    if(end_p<front_p)
        if(b.size()-bend>bfront)
            cout<<b+bend;
        else
            for(i=0;i<bfront;i++)
                cout<<b[i];
    if(end_p>front_p)



    return 0;
}