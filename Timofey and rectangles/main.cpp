/*
 * 充分利用题目中odd的条件
 * 对于任意两个相邻矩形 其右下角点 x y 坐标的奇偶性 一定不同
 * 因为边长为odd
 * odd+(odd)=even
 * even+(odd)=odd
 *
 * 所以   相邻 ----> 奇偶性不同
 * 所以   奇偶性相同 -----> 不相邻 (by contrapositive)
 *
 * 所以只需 4个颜色 分别对应右下角坐标
 * (odd,odd)
 * (odd,even)
 * (even,odd)
 * (even,even)
 *
 */

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	printf("YES\n");
	int n, a, b, c, d;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (!(a % 2) && !(b % 2))  //(0,0)
			printf("3\n");
		else if (!(a % 2) && (b % 2))  //(0,1)
			printf("4\n");
		else if ((a % 2) && !(b % 2))  //(1,0)
			printf("2\n");
		else                          //(1,1)
			printf("1\n");
	}
	return 0;
}