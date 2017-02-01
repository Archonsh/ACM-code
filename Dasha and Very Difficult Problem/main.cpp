#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;

struct Node {
    int v, p;
    bool operator < (const Node& another) const {
        return p < another.p;
    }
};
Node a[maxn], a_copy[maxn];
int n, l, r, b[maxn], c[maxn];

bool solve(int cur) {
    c[cur] = c[cur-1] + 1;
    b[cur] = c[cur] + a[cur].v;
    if(b[cur] > r) return false;
    if(b[cur] >= l) return true;
    c[cur] += l - b[cur];
    b[cur] += l - b[cur];
    return b[cur] >= l && b[cur] <= r;
}

int main() {
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++) cin >> a[i].v;
    for(int i = 0; i < n; i++) cin >> a[i].p;
    memcpy(a_copy, a, sizeof(a));
    sort(a, a+n);
    b[0] = l; c[0] = l - a[0].v;
    for(int i = 1; i < n; i++)
        if(!solve(i)) { cout << -1 << endl; return 0;}
    cout << b[a_copy[0].p-1];
    for(int i = 1; i < n; i++) cout << ' ' << b[a_copy[i].p-1];
    cout << endl;
    return 0;
}