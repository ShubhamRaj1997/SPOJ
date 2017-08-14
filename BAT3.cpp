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
int t,n,m,a[1002];
int solve(){
    int dp[n+1]={-1},allMax=1;
    dp[0]=0;dp[1]=1;                                      
    for(int i=2;i<=n;i++){                                // Just the usual LDS
        int maxi=0;
        loop1(j,i){
            if(a[j]>a[i])maxi=max(maxi,dp[j]);
        }
        dp[i]=maxi+1;
        allMax=max(allMax,dp[i]);
    }
    dp[m+1]=1;int ma=1,allma=1;
    for(int i=m+2;i<=n;i++){                            // Just treat as new array from m+1 onwards
            ma=0;
        for(int j=m+1;j<i;j++){
            if(a[j]>a[i])ma=max(ma,dp[j]);
        }
        dp[i]=ma+1;
        allma=max(allma,dp[i]);
    }
    return max(allMax,dp[m]+allma);                     // return maximum of above 2 Cases :)
}
int main()
{
    cin>>t;while(t--){
        cin>>n>>m;loop1(i,n+1)cin>>a[i];
        m++;                                // since it is 0-Based number of index
        cout<<solve()<<endl;
    }
    return 0;
}
