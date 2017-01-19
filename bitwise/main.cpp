//Hackerank "https://www.hackerrank.com/challenges/30-bitwise-and"
//看清楚数据范围 可以直接暴力


#include <cstdio>
#include <cstdlib>
using namespace std;
int T,n,k,bit1,hi;
void MSB(int num)
{
    int flag=1;
    bit1=0;
    while(flag < 1<<11)
    {
        if(num&flag)
        {
            bit1++;
            hi=flag;
        }
        flag<<=1;
    }
    return;
}

int main() {
    int flag=1,xmax=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        //MSB(k);
        if(k<n)
        {printf("%d\n",k-1);continue;}
        printf("0\n");
    }
    return 0;
}