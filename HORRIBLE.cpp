#include<bits/stdc++.h>
#define mset(a,val) memset(a,val,sizeof(a))
#define N 100005
#define ll long long
using namespace std;
ll  n;
void update(ll  *BIT,ll  idx,ll  val,ll  n){
    for(;idx<=n;idx+=idx&(-idx))
        BIT[idx]+=val;
}
ll  query(ll  *BIT,ll  idx){
    ll  ans=0;
    for(;idx>0;idx-=idx&(-idx))
        ans+=BIT[idx];
    return ans;
}
int  main(){
    ll  t;cin>>t;
    while(t--){
        ll  n,c,z,p,q,v;cin>>n>>c;
        ll  BIT[N]={0},BIT1[N]={0};
        while(c--){
            cin>>z;
            if(z){
            cin>>p>>q;
            cout<<((query(BIT,q)*q-query(BIT1,q))-(query(BIT,p-1)*(p-1)-query(BIT1,p-1)))<<endl;

        }
        else{
           cin>>p>>q>>v;
            update(BIT,p,v,n);
            update(BIT,q+1,-v,n);
            update(BIT1,p,v*(p-1),n);
            update(BIT1,q+1,-v*q,n);
        }
        }

    }

}
