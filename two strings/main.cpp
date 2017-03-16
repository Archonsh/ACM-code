#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
string a,b;
int main() {
    int i,j,ptr=0,front_p=-1,end_p=-1,bfront=-1,bend=-1,visa[100005],ans,xmax=0,visb[100005];
    cin>>a;
    cin>>b;
    for(i=0;i<b.size();i++)
    {
        while(ptr<a.size())
        {
            if(a[ptr]==b[i])
            {
                visa[i]=ptr;   //b[i]出现在ptr位置
                front_p=ptr;
                ptr++;
                bfront=i;
                break;
            }
            ptr++;
        }
    }
    ptr=a.size()-1;
    for(i=b.size()-1;i>=0;i--)
    {
        while(ptr>=0)
        {
            if(a[ptr]==b[i])
            {
                visb[i]=ptr;
                end_p=ptr;
                ptr--;
                bend=i;
                break;
            }
            ptr--;
        }
    }
    if(front_p==end_p &&end_p==-1)
    {
        printf("-");
        return 0;
    }
    else if (front_p==-1)
    {
        for(i=bend;i<b.size();i++)
            printf("%c",b[i]);
        return 0;
    }
    else if (end_p==-1)
    {
        for(i=0;i<=bfront;i++)
            printf("%c",b[i]);
        return 0;
    }
    else if(bfront==b.size()-1 || bend==0)
    {
        cout<<b;
        return 0;
    }

//********************************************************************************************************************
//    xmax=b.size()-bend;
//    front_p=-1;
//    end_p=bend;
//    for(i=0;i<=bfront;i++)
//    {
//        for(j=bend;j<b.size();j++)
//        {
//            if(visa[i]<visb[j])
//            {
//                if(xmax<i+1+b.size()-j)
//                {
//                    xmax=i+1+b.size()-j;
//                    front_p=i;
//                    end_p=j;
//                }
//                else
//                    break;
//            }
//        }
//    }
//    if(xmax<bfront+1)
//    {
//        front_p=bfront;
//        end_p=-1;
//    }
//*******************************************************************************************************************
    xmax=bfront+1;
    front_p=bfront;
    end_p=-1;
    for(i=bend;i<b.size();i++)
    {
        ptr=lower_bound(visa,visa+bfront,visb[i])-visa;
        if(ptr==0 && visa[0]>=visb[i])            //i出现位置比前面任何都早 前面全部不能选
            ans=b.size()-i;
//        else if(!ptr && visa[0]<visb[i])        //只有一个bfront的情况->bfront=ptr=0 被下面的情况包括
//            ans=b.size()-i+1;
        else if(ptr == bfront && visa[bfront]<visb[i])      //前面都可以选
            ans=ptr+1+(b.size()-i);
//      else
//          ans[i]=ans[ptr-1]+b.size()-i;    问题在这一步 如果ptr=bfront 但是最后几个数是连续的都不能选 即出错 {1,2,3,4,5,9,9,9,9,9}
//                                           因为ptr-1依然是非法的: val>数组中的每个数 返回的visa.end()-1也是非法的
        else
            ans=ptr+b.size()-i;
        if(ans>xmax)//>=
        {
            xmax=ans;
            if(ptr==0 && visa[0]>=visb[i])      //前面全部不选
                front_p=-1;
//          else if(!ptr && visa[0]<visb[i]) //只有一个bfront的情况
//                front_p=0;
            else if(ptr == bfront && visa[bfront]<visb[i])  //前面都可以选
                front_p=ptr;
            else
                front_p=ptr-1;
            end_p=i;
        }
    }
//***********************************************************************************************************************
//    xmax=bfront+1;
//    front_p=bfront;
//    end_p=-1;
//    for(i=bend;i<b.size();i++)
//    {
//        for(j=bfront;j>=0;j--)
//        {
//            if(visb[i]>visa[j])
//            {
//                if(j+1+b.size()-i>xmax)
//                {
//                    front_p=j;
//                    end_p=i;
//                    xmax=j+1+b.size()-i;
//                }
//                else
//                    break;
//            }
//        }
//    }
//    if(b.size()-bend>xmax)
//    {
//        front_p=-1;
//        end_p=bend;
//    }
//***********************************************************************************************************************
    if(front_p>=0)
        for(i=0;i<=front_p;i++)
            printf("%c",b[i]);
    if(end_p>=0)
        for(i=end_p;i<b.size();i++)
          printf("%c",b[i]);


//    if(front_p<end_p)
//    {
//        if(bfront<bend)
//        {
//            for(i=0;i<=bfront;i++)
//                printf("%c",b[i]);
//            for(i=bend;i<b.size();i++)
//                printf("%c",b[i]);
//        }
//        else
//            cout<<b;
//    }

//        cf=bfront+1;
//        for(i=front_p+1;i<a.size();i++)
//            if(vis[i])
//                cf++;
//        if(bend!=-1)
//        {
//            cn=b.size()-bend;
//            for(i=end_p-1;i>=0;i--)
//                if(vis[i])
//                    cn++;
//        }
//        else
//            cn=-1;
//
//        if(cf>=cn)
//        {
//            for(i=0;i<=bfront;i++)
//                printf("%c",b[i]);
//            for(i=front_p+1;i<a.size();i++)
//                if(vis[i])
//                    printf("%c",a[i]);
//        }
//        else
//        {
//            for(i=0;i<=end_p-1;i++)
//                if(vis[i])
//                    printf("%c",a[i]);
//            for(i=bend;i<b.size();i++)
//                printf("%c",b[i]);
//        }
//
    return 0;
}