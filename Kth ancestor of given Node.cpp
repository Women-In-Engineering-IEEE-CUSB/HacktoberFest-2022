// Kth ancestor
#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<vector<ll>>adj;
vector<ll>depth;
vector<vector<ll>>up;

void treeancestor(ll root,ll parent)
{
    if(root==0)depth[root]=0;
    else depth[root]=depth[parent]+1;
    up[root][0]=parent;
    for(int i=1;i<18;i++)
    {
        ll temp=up[root][i-1];
        if(temp==-1)up[root][i]=-1;
        else up[root][i]=up[temp][i-1];
    }
    for(auto i: adj[root])
    {
        if(i==parent)continue;
        treeancestor(i,root);
    }
}

ll kth(ll node,ll k)
{
    for(int i=0;i<18;i++)
    {
        if(k&(1<<i))
        {
            node=up[node][i];
        }
        if(node==-1)break;
    }
    return node;
}

int main()
{
    ll n;cin>>n;
    adj.resize(n+1);
    for(int i=1;i<n;i++)
    {
        ll x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll tar,k;
    cin>>tar>>k;
    up.resize(n+1,vector<ll>(18));
    depth.resize(n+1);
    treeancestor(1,-1);
    cout<<kth(tar,k)<<endl;
    return 0;
}

