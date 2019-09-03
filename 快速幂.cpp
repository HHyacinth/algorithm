/**
    O(log(b))求解a^b%mod
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll qPow1(ll a,ll b,ll mod)///a^b%mod
{
    ll ans=1;
    a %= mod;
    while(b)
    {
        if(b&1)
            ans=ans*a%mod;

        a=a*a%mod;
        b >>= 1;
    }
    return ans;
}
///另一种简洁写法
ll qPow2(ll a,ll b,ll mod)
{
    ll ans=1;
    a %= mod;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)
            ans=ans*a%mod;
    return ans;
}
int main()
{
    int a=rand()%100+1;
    int b=rand()%100+1;
    int c=rand()%1000+1;

    cout<<a<<'^'<<b<<" mod "<<c<<endl;
    cout<<qPow1(a,b,c)<<endl;
    cout<<qPow2(a,b,c)<<endl;
}
/**
    [快速幂详解](https://www.cnblogs.com/CXCXCXC/p/4641812.html)
*/
