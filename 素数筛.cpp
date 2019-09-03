/**
    欧拉筛法（时间复杂度O(n)，n为需要筛的最大的数）
    [1~n)有cnt个素数
*/
#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int maxn=1e5+50;

int cnt;
int prime[maxn];///素数表，存储[1~n)中的所有素数
bool isPrime[maxn];///isPrime[i]:判断i是否为素数
void Prime(int n)
{
    mem(isPrime,true);
    isPrime[1]=false;

    cnt=0;
    for(int i=2;i < n;++i)
    {
        if(isPrime[i])///判断i是否为素数,如果是，加入素数表
            prime[++cnt]=i;

        ///筛出由已有的素数确定的合数
        for(int j=1;j <= cnt && prime[j]*i < n;++j)
        {
            ///筛去素数prime[j]的i倍
            isPrime[i*prime[j]]=false;
            if(i%prime[j] == 0)///优化的关键语句，确保每个合数只被一个素数筛去
                break;
        }
    }
}
int main()
{
    Prime(20);
    for(int i=1;i <= cnt;++i)
        printf("%d%c",prime[i],i == cnt ? '\n':' ');
}
/**
疑惑：
　　如何确保任意合数只被筛去一次？
　　例如：12 = 2*6 = 3*4
　　怎样才能确保12只被 2*6 筛去，而不被 3*4 筛去？
　　确保的关键就是
　　　　if(i%prime[j] == 0)
　　　　　　break;
对欧拉筛法优化语句的理解：
    引理1：
        假设 x*y = a*b，其中 x,a 为质数，那么有 x | b , a | y.
    例如：
        2*6 = 3*4
        2 | 4 , 3 | 6
    引理2：
        任何一个合数都可以表示成一个质数和一个整数的乘积。

    对于一个合数 A
        如果 A 只能分解成一个 素数×整数 的形式，那么这个整数必为素数，这也就意味着 i 为素数；
        那么语句 if(i%prime[j] == 0) 始终为false.
        例如：假设A=21=3*7
        当 i = 7 是，会与之前求出的所有的素数相乘，使得 isPirme[ 7×3 ] =false
        那么对于所有的只能分解成 素数×素数 形式的合数会全部筛去。
    
        如果 A 可以分解成多个 素数×整数 的形式
        不妨假设 A = a1*b1 = a2*b2 ，并且 a1,a2 为素数，a1 < a2;
        那么由引理1可得
            a1 | b2 , a2 | b1
        由于 a1 < a2，所以 b1 > b2，
        当 i = b2时，在执行完 isPrime[ a1*b2 ]=false 后，一定会执行 if(b2%a1 == 0) 这条语句，
        那么就不会执行 isPrime[ a2*b2 ]=false 这条语句。
        所以，这句话确保了每个合数只被筛去一次。

另一种理解：
    如果 i%prime[j] = 0;
    那么，不妨令 i = prime[j]×q;
    对于比 prime[j] 大的素数 prime[k]：
    i×prime[k] = prime[j]×q×prime[k];
    完全可以在 i'=q×prime[k] 时通过prime[j]筛去prime[k]×i；
*/
