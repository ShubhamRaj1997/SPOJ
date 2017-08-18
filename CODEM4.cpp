#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define MAX 30
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
#define MOD 1000000007
using namespace std;
pair<int,int> dp[MAX][MAX];
int n,a[30];
// if they play optimally it is crucial so I chose bottom-up
int solve(){
    loop(i,n){
        dp[i][i].f=a[i];
    }
    int k=1,i=0,j;
    while(k<n){
        for(i=0;k+i<n;i++){
            j=i+k;
            if(a[i]+dp[i+1][j].s>=a[j]+dp[i][j-1].s){
                dp[i][j].f=a[i]+dp[i+1][j].s;dp[i][j].s=dp[i+1][j].f;
            }
            else{
                dp[i][j].f=a[j]+dp[i][j-1].s;dp[i][j].s=dp[i][j-1].f;

            }
        }
        k++;
    }

    return dp[0][n-1].f;
}
int DP[MAX][MAX];
// for dumb lets use top-down approach

int dumb(int i,int j)
{
  if(i>j)
    return 0;
  if(DP[i][j]!=-1)
    return DP[i][j];
  int ans = max(a[i] + max(dumb(i+1,j-1),dumb(i+2,j)),a[j] + max(dumb(i+1,j-1),dumb(i,j-2)));
  DP[i][j] = ans;
  return ans;
}
int main()
{
    int t;cin>>t;
    while(t--){
        mset(dp,0);mset(a,0);mset(DP,-1);
        cin>>n;loop(i,n)cin>>a[i];
        cout<<dumb(0,n-1)<<" "<<solve()<<endl;
    }

    return 0;
}
