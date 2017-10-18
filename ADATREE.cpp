#include<bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;i++)
#define MAX 300001
#define vi vector<int>
#define lc 2*node+1
#define rc 2*node+2
#define pb push_back
using namespace std;
int n,a[MAX];
vi tree[4*MAX];
void buildTree(int node,int st,int e){
    if(st==e){
        tree[node].pb(a[st]);return;
    }
    int mid=(st+e)/2;
    buildTree(lc,st,mid);
    buildTree(rc,mid+1,e);
    merge(tree[lc].begin(),tree[lc].end(),tree[rc].begin(),tree[rc].end(),back_inserter(tree[node]));
}
int queryTree(int node,int st,int e,int l,int r,int h){
    if(r< st || e <l)return 0;
    if(st>=l && e<=r){
        int siz=tree[node].size();
        if(h>=tree[node][siz-1])return tree[node][siz-1];
        int idx=lower_bound(tree[node].begin(),tree[node].end(),h)-tree[node].begin();
        if(idx<0)return 0;
        if(tree[node][idx]>h)idx--;

        return tree[node][idx];
    }
    int mid=(st+e)/2;
    return max(queryTree(lc,st,mid,l,r,h),queryTree(rc,mid+1,e,l,r,h));
}
int main(){
    int q,h,l,r;
    cin>>n>>q;
    loop(i,n)cin>>a[i];
    buildTree(0,0,n-1);
    loop(i,q){
        cin>>l>>r>>h;
        cout<<queryTree(0,0,n-1,l,r,h)<<endl;
    }



}
