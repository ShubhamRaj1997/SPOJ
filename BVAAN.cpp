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
string a,b;
int dp[102][102][102];
int solve(int i,int j,int k){
    if(k<=0)return 0;
    if(i==-1 || j==-1)return -INT_MAX;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    if(a[i]==b[j]){
        return dp[i][j][k]=max(solve(i-1,j-1,k-1)+a[i],solve(i-1,j-1,k));
    }
    return dp[i][j][k]=max(solve(i,j-1,k),solve(i-1,j,k));

}
int main()
{
    int t,k;cin>>t;
    while(t--){
       mset(dp,-1);
       cin>>a>>b;
       cin>>k;
       int ans=solve(a.length()-1,b.length()-1,k);
       if(ans<0)ans=0;
       cout<<ans<<endl;
    }


    return 0;
}
