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
int solve(int *a,int n){
    stack<int> s;int ans=0,i=0,tp,tpArea;
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
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;int row[m+1]={0},a[m+1];char c;int ans=0;
        loop1(i,n+1){
            loop(j,m){
                cin>>c;
                if(c=='R'){
                    row[j]=i;a[j]=0;
                }
                if(c=='F'){
                  a[j]=i-row[j];
                }
            }
            //loop(j,m)cout<<a[j]<<" ";
           ans=max(ans,solve(a,m));
        }
        cout<<ans*3<<endl;
    }

    return 0;
}
