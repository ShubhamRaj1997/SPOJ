#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAX 2000001
using namespace std;
ll power(ll x,ll y,ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main(){
    ll a[10][MAX];//memset(a,0,sizeof(a));
    
    char s[2000001] ;scanf("%s",s);
    ll n=strlen(s),ans=0;
    a[1][0]=1;
    for(ll j=1;j<n+1;j++){
           a[1][j]=(a[1][j-1]+(1*power(10,j,MOD))%MOD)%MOD;
        }
    for(ll i=2;i<10;i++){
        a[i][0]=i;
        for(ll j=1;j<n+1;j++){
           a[i][j]=(a[1][j]*i)%MOD;
        }
    }
    for(ll i=0;i<n;i++){
        ans=(ans+((i+1)*a[s[i]-'0'][n-i-1])%MOD)%MOD;
    }
    printf("%lld\n",ans);
}
