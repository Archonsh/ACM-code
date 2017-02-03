#include <cstdio>

using namespace std;

int main() {
    int b[200005],n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    if(n%2==1) {
        for (i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                printf("%d ", b[i]);
            }
            else if (i == (n / 2 + 1)) {
                printf("%d ", b[i]);
            }
            else {
                printf("%d ", b[n - i + 1]);
            }

        }
    }
    else
    {
        for(i=1;i<=n/2;i++)
        {
            if (i % 2 == 0) {
                printf("%d ", b[i]);
            }
            else {
                printf("%d ", b[n - i + 1]);
            }
        }
        for(i=n/2+1;i<=n;i++)
        {
            if (i % 2 == 1) {
                printf("%d ", b[i]);
            }
            else {
                printf("%d ", b[n - i + 1]);
            }
        }
    }
    return 0;
}