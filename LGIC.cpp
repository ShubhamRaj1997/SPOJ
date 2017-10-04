#include<bits/stdc++.h>
#define ll long long
using namespace std;
/// as you can see dramatic increase in An with n , so it is related to either exp(n) or n!
/// n! works here.Also An is more than n! ,what is that ? try to figure it out :)
ll f[20]={0},g[20]={0};
void solve(int n){
    f[1]=1LL;
    for(int i=2;i<=n;i++)
        f[i]=f[i-1]*(ll)i;
    g[1]=1LL,g[2]=2LL;
    for(int i=3;i<=n;i++)
        g[i]=3*g[i-1]-2*g[i-2]+1LL;
}
int main(){
    int n;cin>>n;
    solve(n);
    cout<<(f[n]+g[n])<<endl;
}
