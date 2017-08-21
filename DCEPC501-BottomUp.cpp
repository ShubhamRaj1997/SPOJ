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
int main()
{
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll a[n+10]={0},dp[n+10]={0};
        loop(i,n)cin>>a[i];
        for(int i=n-1;i>=0;i--){
            dp[i]=max(max(a[i]+dp[i+2],a[i]+a[i+1]+dp[i+4]),a[i]+a[i+1]+a[i+2]+dp[i+6]);
        }
        cout<<dp[0]<<endl;
    }

    return 0;
}
