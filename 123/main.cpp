#include<cstdio>
using namespace std;
int main()
{
    int n[100];
    int *a;
    scanf("%d",&n[1]);
    a=&n[0];
    printf("%p\n",&n);
    printf("%p\n",a);
    printf("%d",*(a+1));
    return 0;
}