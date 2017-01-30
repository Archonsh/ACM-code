#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>a[30];
int main() {
    int n,i,j,k,t,count=1,ptr[30];
    while(scanf("%d",&t))
    {
        if(t<97)
            break;
        a[t-97].push_back(count);
    }
    while(scanf("%d",&t))
    {
        if(t<97)
            break;
        if(ptr[t]>a[t].size())
            break;
        ptr[t]++;
    }
    return 0;
}