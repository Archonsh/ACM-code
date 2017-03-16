#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
string a,b;
int main() {
    int i, ptr = 0, front_p = -1, end_p = -1, bfront = -1, bend = -1, cf, cn, visa[200005], ans[200005], xmax = 0, visb[200005];
    cin >> a;
    cin >> b;
    for (i = 0; i < b.size(); i++) {
        while (ptr < a.size()) {
            if (a[ptr] == b[i]) {
                visa[i] = ptr;   //b[i]出现在ptr位置
                front_p = ptr++;
                bfront = i;
                break;
            }
            ptr++;
        }
    }
    ptr = a.size() - 1;
    for (i = b.size() - 1; i >= 0; i--) {
        while (ptr >= 0) {
            if (a[ptr] == b[i]) {
                visb[i] = ptr;
                end_p = ptr--;
                bend = i;
                break;
            }
            ptr--;
        }
    }
    if (front_p == end_p && end_p == -1) {
        printf("-");
        return 0;
    }
    else if (front_p == -1) {
        for (i = bend; i < b.size(); i++)
            printf("%c", b[i]);
        return 0;
    }
    else if (end_p == -1) {
        for (i = 0; i <= bfront; i++)
            printf("%c", b[i]);
        return 0;
    }
    else if (bfront == b.size() - 1 || bend==0 ) {
        cout<<b;
        return 0;
    }

    for (i = 0; i <= bfront; i++)
        ans[i] = i + 1;

    xmax = bfront+1;
    front_p = bfront;
    end_p = -1;
    for (i = bend; i < b.size(); i++) {
        ptr = lower_bound(visa, visa + bfront, visb[i]) - visa;
        if (ptr==0 && visa[0] >= visb[i])            //i出现位置比前面任何都早 前面全部不能选
            ans[i] = b.size() - i;
//        else if (ptr==0 && visa[0] < visb[i])        //只有一个bfront的情况
//            ans[i] = b.size() - i + 1;
        else if (ptr == bfront && visa[bfront] < visb[i])      //前面都可以选
            ans[i] = ans[ptr] + (b.size() - i);
        else
        {
            if(ptr-1<0)
                printf("!!!!!!!!!!!!!!!");
            ans[i] = ans[ptr] -1 + b.size() - i;
        }

        if (ans[i] > xmax) {
            xmax = ans[i];
            if (ptr==0 && visa[0] >= visb[i])      //前面全部不选
                front_p = -1;
//            else if (ptr==0 && visa[0] < visb[i]) //只有一个bfront的情况
//                front_p = 0;
            else if (ptr == bfront && visa[bfront] < visb[i])  //前面都可以选
                front_p = ptr;
            else
                front_p = ptr - 1;
            end_p = i;
        }
    }
    if (front_p >= 0)
        for (i = 0; i <= front_p; i++)
            printf("%c", b[i]);
    if (end_p >= 0)
        for (i = end_p; i < b.size(); i++)
            printf("%c", b[i]);

    return 0;
}
