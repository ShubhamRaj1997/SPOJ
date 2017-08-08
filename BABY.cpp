#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define MAX (1<<17)+1
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
int dp[MAX],a[17],b[17],n;
int foo(int mask,int idx){
    if(idx==n)return 0;
    if(dp[mask]!=-1)return dp[mask];
    int ans=INT_MAX;
    loop(i,n){
        if(!(mask&(1<<i))){
            ans=min(ans,foo(mask|(1<<i),idx+1)+abs(b[idx]-a[i])+abs(idx-i));
        }
    }
    return dp[mask]=ans;
}
int main()
{
    while(1){
        cin>>n;if(!n)break;
        mset(dp,-1);mset(a,0);mset(b,0);
        loop(i,n){cin>>a[i];}
        loop(i,n){cin>>b[i];}
        cout<<foo(0,0)<<endl;
    }
    return 0;
}
