#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define STATE 3
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll foo(int a,int b,ll n){
    ll ans=0LL;
    ans=n/(ll)a;
    //cout<<ans;
    ans+=n/(ll)b;
    ans-=(n)/(ll)((int)(a*b)/gcd(a,b));
    return ans;

}
int main(){
    int t;cin>>t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        ll low=0LL,high=100000000000000;
        //cout<<low<<" "<<high<<endl;
        while(low<high){
            ll mid=(low+high)/(ll)2;
            //cout<<foo(a,b,mid)<<endl;
            if(foo(a,b,mid)>=(ll)n){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        cout<<high<<endl;
    }
}
