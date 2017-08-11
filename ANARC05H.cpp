#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define MAX 250*9+1
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
#define dis(a,b) sqrt((a.f-b.f)*(a.f-b.f) +(a.s-b.s)*(a.s-b.s))
using namespace std;

int main()
{
    int t=0;
    while(1){
        t++;
        string num;int pre[255]={0};cin>>num;
        if(num=="bye")break;pre[0]=0;
        loop(i,num.length())
            pre[i+1]=pre[i]+num[i]-'0';
        int dp[26][250];mset(dp,0);
        dp[0][0]=1;dp[1][num[0]-'0']=1;
        for(int i=2;i<=num.length();i++){
           for(int k=1;k<=i;k++){
            for(int l=0;l<=pre[i]-pre[i-k];l++){
                dp[i][pre[i]-pre[i-k]]+=dp[i-k][l];
            }
           }
        }
        int sum=0;
        loop(i,pre[num.length()]+1){
            sum+=dp[num.length()][i];
        }
        cout<<t<<". "<<sum<<endl;
    }
    return 0;
}
