#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
const int maxn=4e4+50;

int n,m;
int num;
int head[maxn];
struct Edge
{
    int to;
    ll w;
    int next;
}G[maxn<<1];
void addEdge(int u,int v,int w)
{
    G[num]={v,w,head[u]};
    head[u]=num++;
}
struct LCA
{
    int fa[30][maxn];///fa[i][j]:节点j沿着其父结点向上走2^i步所到的节点（超过根节点时记为-1）
    ll dis[maxn];///dis[i]:节点i的与根节点的距离
    ll dep[maxn];///dep[i]:节点i的深度，根节点深度为0
    void DFS(int u,int f,ll Dis,ll Dep)
    {
        fa[0][u]=f;///节点u向上走2^0步来到的节点便是其父节点
        dis[u]=Dis;
        dep[u]=Dep;
        for(int i=head[u];~i;i=G[i].next)
        {
            int v=G[i].to;
            int w=G[i].w;
            if(v != f)
                DFS(v,u,Dis+w,Dep+1);
        }
    }
    void Init()
    {
        DFS(1,-1,0,0);///默认1为根节点
        for(int k=1;k <= 20;++k)
            for(int u=1;u <= n;++u)
                if(fa[k-1][u] == -1)
                    fa[k][u]=-1;
                else
                    fa[k][u]=fa[k-1][fa[k-1][u]];
    }
    int lca(int u,int v)///返回u,v的最近公共祖先
    {
        if(dep[u] > dep[v])
            swap(u,v);

        for(int i=0;i <= 20;++i)
            if((dep[v]-dep[u])>>i&1)
                v=fa[i][v];
        if(u == v)
            return u;

        for(int i=20;i >= 0;--i)
            if(fa[i][u] != fa[i][v])
            {
                u=fa[i][u];
                v=fa[i][v];
            }
        return fa[0][u];
    }
}_lca;
