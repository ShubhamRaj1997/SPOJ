// Segment-Tree 
// Easy Wisy

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define MAX 100001
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
int a[MAX];
pii tree[4*MAX];
int n,q,x,y;
pii mergeTree(pii ff,pii ss){       // mergeTree is used to get 2 largest numbers in left and right half subarrays
    pii ans=mp(0,0);
    int m=ff.f,m1=ff.s;
    if(m<m1)swap(m,m1);
    if(ss.f>=m){
        m1=m;
        m=ss.f;
    }
    else if(ss.f>m1){
        m1=ss.f;
    }
    if(ss.s>=m){
        m1=m;
        m=ss.s;
    }
    else if(ss.s>m1){
        m1=ss.s;
    }
    ans.f=m;ans.s=m1;
    return ans;
}
void buildTree(int node,int st,int e){
    if(st==e){
        tree[node].s=a[st];
        tree[node].f=0;

    }
    else{
        int mid=(st+e)/2;
        buildTree(2*node,st,mid);
        buildTree(2*node+1,mid+1,e);
        tree[node]=mergeTree(tree[2*node],tree[2*node+1]);
        }
}
void updateTree(int node,int st,int e,int idx,int val){
    if(st==e){
        a[st]=val;
        tree[node].s=a[st];
        tree[node].f=0;

    }
    else{
        int mid=(st+e)/2;
        if(st<=idx && idx<=mid)
            updateTree(2*node,st,mid,idx,val);
        else
            updateTree(2*node+1,mid+1,e,idx,val);
        tree[node]=mergeTree(tree[2*node],tree[2*node+1]);

    }
}
pii query(int node,int st,int e,int l,int r){
    if(st>r || e<l){
        pii q=mp(0,0);
        return q;
    }
    if(l<=st && r>=e){

        return tree[node];
    }
    int mid=(st+e)/2;
    pii p,q,ss;
    p=query(2*node,st,mid,l,r);
    q=query(2*node+1,mid+1,e,l,r);
    ss=mergeTree(p,q);

    return ss;
}
int main()
{
    cin>>n;
    loop1(i,n+1)cin>>a[i];
    char c;buildTree(1,1,n);
    cin>>q;
    loop(i,q){
        cin>>c>>x>>y;
        if(c=='U'){
            updateTree(1,1,n,x,y);
        }
        else{
            pii p=query(1,1,n,x,y);
            cout<<(p.f+p.s)<<endl;
        }
    }

    return 0;
}
