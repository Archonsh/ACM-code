/*
 * just simple greedy
 * always pick the cheapest mouse to fulfil the requirement
 *
 */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int>usb,ps,remain;
int main() {
    int a, b, c, m, i, j;
    long long cost = 0, num = 0;
    char ch,ch1[100];
    scanf("%d%d%d%d", &a, &b, &c, &m);
    for (i = 1; i <= m; i++)
    {
        scanf("%d", &j);
        scanf("%c", &ch);
        scanf("%c", &ch);
        if (ch == 'U')
            usb.push_back(j);
        else
            ps.push_back(j);
        gets(ch1);
    }
    sort(usb.begin(), usb.end());
    sort(ps.begin(), ps.end());

    if (a > usb.size())
    {for (i = 0; i < usb.size(); i++)
            cost += usb[i];
        num+=usb.size();}
    else {
        for (i = 0; i < a; i++)
            cost += usb[i];
        for (i = a; i < usb.size(); i++)
            remain.push_back(usb[i]);
        num+=a;
    }
    if (b > ps.size())
    {for (i = 0; i < ps.size(); i++)
            cost += ps[i];
        num+=ps.size();}
    else {
        for (i = 0; i < b; i++)
            cost += ps[i];
        for (i=b;i<ps.size();i++)
            remain.push_back(ps[i]);
        num+=b;
    }

    sort(remain.begin(),remain.end());
    if(c>remain.size())

    {for (i = 0; i < remain.size(); i++)
            cost += remain[i];
        num+=remain.size();
    }
    else {
        for (i = 0; i < c; i++)
            cost += remain[i];
        num+=c;
    }
    cout<<num<<' '<<cost<<endl;
    return 0;
}