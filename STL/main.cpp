#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;
struct node {
    int a,v;
    bool operator < (const node &t) const
    { return a>t.a;}
};
int main() {
    priority_queue<int>v;
//    node v1;
//    v1.a=1;
//    v1.v=1;
//    v.push(v1);
//    v1.a=v1.v=2;
//    v.push(v1);
    v.push(1);
    v.push(2);
    printf("%d",v.top());
    return 0;
}