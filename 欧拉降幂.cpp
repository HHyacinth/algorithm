int getPhi(int p)
{
    int ans=1;
    for(int i=2;i*i <= p;++i)
    {
        if(p%i)
            continue;
        ans *= i-1;
        p /= i;
        while(p%i == 0)
        {
            ans *= i;
            p /= i;
        }
    }
    if(p > 1)
        ans *= p-1;
    return ans;
}
ll modulo(ll x,ll mod)
{
    return x > mod ? x%mod+mod:x;
}
ll qPow(ll a,ll b,ll mod)
{
    ll ans=1;
    for(;b;b>>=1)
    {
        if(b&1)
            ans=modulo(ans*a,mod);
        a=modulo(a*a,mod);
    }
    return ans;
}
int Calc(int a,int b,int p)///b个a的组成的幂对p取模
{
    if(p == 1 || a == 1 || b == 0)
        return 1;

    int t=getPhi(p);
    return qPow(a,Calc(a,b-1,t),p);
}
