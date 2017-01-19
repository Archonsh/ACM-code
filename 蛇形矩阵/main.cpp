#include <cstdio>
using namespace std;
int map[105][105],cout=1;
int main() {
    int n, m, i, j, x, y;
    scanf("%d", &n);
    m = n * n;
    x=y=n/2;
    i=1;
    map[x][y] = cout++;
    while (i) {
        i+=1;
        while (x + 1 <= i ) //right
        {
            map[++x][y] = cout++;

        }if (cout > m) break;
        while (y - 1 >= n-i-1)//up
        {
            map[x][--y] = cout++;

        }if (cout > m) break;
        while (x - 1 >= n-i-1)//left
        {
            map[--x][y] = cout++;

        }if (cout > m) break;
        while (y + 1 <= i)//down
        {
            map[x][++y] = cout++;
        }if (cout > m) break;
    }
    x=0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
        {printf("%d ", map[j][i]);if(i==j || i==n-j-1)x+=map[i][j];}
        printf("\n");
    }
    printf("%d",x);
    return 0;
}