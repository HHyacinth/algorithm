#include <bits/stdc++.h>
using namespace std;
#define LL __int128

template<class _R>
inline bool read(_R &x)
{
    int f=1;
    char in=getchar();

    if(in == EOF)
        return false;

    while(in != '-' && (in < '0' || in > '9'))
        in=getchar();

    if(in == '-')
    {
        f=-1;
        x=0;
    }
    else
        x=in-'0';
    while(in=getchar(),in >= '0' && in<='9')
        x=x*10+(in-'0');

    x *= f;
    return true;
}
template<class _W>
inline void write(_W x)
{
    if(x < 0)
    {
        putchar('-');
        x=-x;
    }
    if(x > 9)
        write(x/10);
    putchar(x%10+'0');
}

int main()
{
    LL a,b;
    while(read(a))
    {
        read(b);
        write(a+b);
        printf("\n");
    }
}
