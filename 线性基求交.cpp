#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long

void Insert(ll *base,ll x)
{
    for(int i=32;i >= 0;--i)
        if(x>>i&1)
        {
            if(!base[i])
            {
                base[i]=x;
                return ;
            }
            x ^= base[i];
        }
}
void Merge(ll *a,ll *b,ll *c)///c = a ∩ b
{
    ll all[40];
    ll B[40];
    for(int i=0;i <= 32;++i)
        all[i]=a[i];
    mem(B,0);
    mem(c,0);


    for(int i=32;i >= 0;--i)
    {
        ll x=b[i];
        ll y=b[i];

        for(int j=32;j >= 0;--j)
            if(x>>j&1)
            {
                if(!all[j])
                {
                    all[j]=x;
                    B[j]=y;
                    break;
                }
                x ^= all[j];
                y ^= B[j];///消除B的影响，使得y仅由基A表示
            }

        if(!x)///如果x未插入到all中，那么 y ∈ c
            Insert(c,y);
    }
}
ll a[40],b[40],c[40];

int main()
{
    Insert(a,5);
    Insert(b,1);
    Insert(b,4);

    Merge(a,b,c);

    ///输出 5
    for(int i=0;i <= 32;++i)
        if(c[i])
            printf("%lld ",c[i]);
}
