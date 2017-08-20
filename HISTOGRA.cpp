// good technique :)
// stacks
// watch : https://www.youtube.com/watch?v=ZmnqCZp9bBs


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
ll solve(ll *a,ll n){
    stack<ll> s;ll ans=0,i=0,tp,tpArea;
    while(i<n){
        if(s.empty() || a[s.top()]<=a[i])
            s.push(i++);
        else{
            tp=s.top();s.pop();
            tpArea=a[tp]*(s.empty()?i:i-s.top()-1);
            ans=max(ans,tpArea);
        }
    }
    while(s.empty()==false){
        tp=s.top();s.pop();
        tpArea=a[tp]*(s.empty()?i:i-s.top()-1);
            ans=max(ans,tpArea);
    }
    return ans;
}
int main()
{
    while(1){
        ll n;cin>>n;if(n==0)break;ll a[n+1];
        loop(i,n)cin>>a[i];
        cout<<solve(a,n)<<endl;
    }

    return 0;
}
