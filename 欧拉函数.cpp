/**
    欧拉函数求解
    O(sqrt(n))时间内求解φ(n)
*/
#include<bits/stdc++.h>
using namespace std;

int getPhi(int x)
{
    int ans=1;
    for(int i=2;i*i <= x;++i)///质因子分解
    {
        if(x%i == 0)
        {
            ans *= i-1;
            x /= i;
            while(x%i == 0)
            {
                ans *= i;
                x /= i;
            }
        }
    }
    if(x > 1)
        ans *= x-1;
    return ans;
}

int main()
{
    int a=rand()%20+2;
    printf("φ(%d)=%d\n",a,getPhi(a));
}
