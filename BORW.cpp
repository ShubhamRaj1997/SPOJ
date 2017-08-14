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
int n,a[203];
int dp[203][203][203];
int solve(int pos,int x,int y){
    if(pos==n+1)return 0;
    if(dp[pos][x][y]!=-1)return dp[pos][x][y];
    int &ret=dp[pos][x][y];
    if(a[pos]>a[x]){
        ret=max(ret,solve(pos+1,pos,y)+1);
    }
    if(a[pos]<a[y]){
        ret=max(ret,solve(pos+1,x,pos)+1);
    }
    return ret=max(ret,solve(pos+1,x,y));
}
int main()
{
    while(1){
        cin>>n;if(n==-1)break;int maxx=0;mset(dp,-1);
            loop1(i,n+1){
            cin>>a[i];
            maxx=max(maxx,a[i]);
        }
        a[0]=0;
         a[n+1]=maxx+1;
        cout<<(n-solve(1,0,n+1))<<endl;
    }


    return 0;
}
