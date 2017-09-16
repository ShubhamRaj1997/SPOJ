#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    while(1){
        cin>>k;
        if(!k)break;
        string a,b;cin>>a>>b;
        int n=a.length(),m=b.length();
        int dp[1001][1001],cmn[1001][1001];
        cmn[0][0]=0;
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++)dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(a[i-1]==b[j-1])cmn[i][j]=cmn[i-1][j-1]+1;
                else cmn[i][j]=0;
                if(cmn[i][j]>=k){
                    for(int p=k;p<=cmn[i][j] && i>=p && j>=p;p++)
                    dp[i][j]=max(dp[i][j],dp[i-p][j-p]+p);
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
}
