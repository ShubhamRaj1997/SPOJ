#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define MAX 1000000
#define f first
#define s second
#define INF INT_MAX
#define INFLL LONG_LONG_MAX
#define pii pair<int,int>
#define pll pair<long,long>
#define mset(a,val) memset(a,val,sizeof(a))
#define loop(i,n)  for(int i=0;i<n;i++)
#define loop1(i,n) for(int i=1;i<n;i++)
#define loopll(i,n) for(ll i=0;i<n;i++)
#define ld long double

using namespace std;
ll n,dp[100001],a[100001];
ll solve(ll i){
    ll ans=0;
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
    ans=a[i]+solve(i+2);
    if(i+1<n)ans=max(ans,a[i]+a[i+1]+solve(i+4));
    if(i+2<n)ans=max(ans,a[i]+a[i+2]+a[i+1]+solve(i+6));
    return dp[i]=ans;
}
int main()
{
    int t;cin>>t;
    while(t--){
        mset(dp,-1);mset(a,0);
        cin>>n;loop(i,n)cin>>a[i];
        cout<<solve(0)<<endl;
    }

    return 0;
}
