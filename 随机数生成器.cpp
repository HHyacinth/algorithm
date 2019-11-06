#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define ul unsigned long

int random(int a,int b)///随机生成[a,b]之间的小随机数
{
    return a+(b-a+1)*rand()/(RAND_MAX+1.0);
}
ul ulrand(int a,int b)///随机生成[a,b]之间的超大随机数
{
    return ((((ul)rand()<<24)&0xFF000000ul) |
           (((ul)rand()<<12)&0x00FFF000ul) |
           (((ul)rand())&0x00000FFFul))%(b-a+1)+a;
}

stringstream ss;
int main(int argc,char *argv[])
{
    int seed=time(NULL);
    if(argc > 1)///如果有参数
    {
        ss.clear();
        ss<<argv[1];
        ss>>seed;///把参数转换成整数赋值给seed
    }
    srand(seed);///用来设置rand()产生随机数时的随机数种子
    /*****上述代码照抄，目的是加快随机数的产生******/
    /**
        以下代码为所需要的随机数据
        如果需要T组数据，令T=1
    */
   
}
