#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define MAX 10010
#define INF INT_MAX
#define INFLL LONG_LONG_MAX
#define pii pair<int,int>
#define pll pair<long,long>
#define pid pair<int,double>
#define mset(a,val) memset(a,val,sizeof(a))
#define loop(i,n)  for(int i=0;i<n;i++)
#define loop1(i,n) for(int i=1;i<n;i++)
#define loopll(i,n) for(ll i=0;i<n;i++)
#define ld long double
#define vi vector<int>
#define MOD 1000000007
using namespace std;
vi adj[MAX];
int s,t;
ll dp[MAX];
ll solve(int v){
    if(v==s)return 1;
    if(dp[v]!=0)
        return dp[v];
    loop(i,adj[v].size()){
        dp[v]=(dp[v]+solve(adj[v][i]))%MOD;
    }
    return dp[v];
}
int main()
{
    int d;cin>>d;
    while(d--){
       loop(i,MAX){
           adj[i].clear();dp[i]=0;
       }
       int c,b,x,y;
       cin>>c>>b>>s>>t;
       loop(i,b){
           cin>>x>>y;
           adj[y].pb(x);
       }
       cout<<solve(t)<<endl;

    }
}
