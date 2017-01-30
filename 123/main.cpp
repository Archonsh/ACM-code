#include<cstdio>
using namespace std;
int main()
{
    int x=3,y=8,w=5,r;
    x=y%x;
    w*= ++x + y--;
    r*= --x + y++;
    printf("%d",r);
    return 0;
}