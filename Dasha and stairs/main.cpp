/*
 * note if a==0 && b==0
 * it's NO b/c the 1<=r<=l must contain at least 1 element
 */

#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    int a,b,i,j;
    scanf("%d%d",&a,&b);
    if(a==b && b==0)
    {
        printf("NO\n");
        return 0;
    }
    if(abs(a-b)>1)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}