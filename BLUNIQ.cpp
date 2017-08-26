// implicit segment tree ,create node only when needed :)
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define MAX 1000001
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
#define pNode node*                            /// node pointer pNode(node*)
using namespace std;

struct node{
    int val;
    node *l,*r;
};
pNode init(int val){
    pNode nod=new node;                         /// Create new node
    nod->val=val;
    nod->l=NULL;
    nod->r=NULL;
    return nod;
}
void update(pNode &root ,int st,int e,int i,int val){
    if(!root)root=init(e);                      /// if node doesn't exist create and set to high value of node
    if(st==e && i==st){
        root->val=val;return;                   /// whatever is value there return that
    }
    int mid=(e-st)/2+st;

    if(i<=mid)update(root->l,st,mid,i,val);     /// recurse to the left if position i is lesser
    else update(root->r,mid+1,e,i,val);

    if(!root->l)root->l=init(mid);              /// Initialize left child with value mid
    if(!root->r)root->r=init(e);                /// Initialize right child with value e

    /// this is crucial coz if my pos i val is already used then the value of that
    /// must have become -INF so just return just higher value in right child
    root->val=max((root->l)?(root->l)->val:-INF,(root->r)?(root->r)->val:-INF);

}
int query(pNode & root,int st,int e,int i){
    if(st==e) return st;                        /// leaf node
    if(!root) root=init(e);
    int mid=(e-st)/2+st;
    if(!root->l)root->l=init(mid);              /// Initialize left child with value mid
    if(!root->r)root->r=init(e);                /// Initialize right child with value e
    if((root->l)->val>=i)return query(root->l,st,mid,i);
    else return query(root->r,mid+1,e,i);

}
int main(){
    pNode root=NULL;
    int n;cin>>n;char c;
    while(n--){
        cin>>c;int x;
        if(c-'0'==1){
            cin>>x;
            int ans=query(root,1,INF,x);
            update(root,1,INF,ans,-INF);
            cout<<ans<<endl;
        }
        else{
            cin>>x;update(root,1,INF,x,x);
        }
    }

}
