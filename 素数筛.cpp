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
