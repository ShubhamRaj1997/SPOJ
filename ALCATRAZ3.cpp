#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> adj[10001];
int k,sparent;                                          // sparent is supreme parent or source vertex
bool dfs(int v,vector<int> visited,int c){
    visited[v]=1;
    for(int i=0;i!=adj[v].size();i++){
        if(visited[adj[v][i]]==0){
            if(dfs(adj[v][i],visited,c+1))
                return true;
        }
        else if(c>=k && adj[v][i]==sparent)             // retur true only if this cycle has length atleast k
            return true;
    }
    return false;
}
int main(){

    int n,m,x,y;cin>>n>>m>>k>>x>>y;int v=m*(x-1)+y,num;char c,ar[10202];    // formula : m*(x-1)+y gives me number of cell with coordinates (x,y)
    /*  (1,1)  (1,2)  (1,3) (1,4)        -------->   1  2  3  4
        (2,1)  (2,2)  (2,3) (2,4)                    5  6  7  8
    
    */
    sparent=v;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c;num=m*(i-1)+j;ar[num]=c;
            if(c=='.'){
                if(num>m){                                    // check if we can go above
                    if(ar[num-m]=='.'){
                        adj[num-m].pb(num);
                        adj[num].pb(num-m);
                    }
                }
                if((num-1)%m!=0){                           // check if we can go to the left
                    if(ar[num-1]=='.'){
                        adj[num-1].pb(num);
                        adj[num].pb(num-1);
                    }
                }
                if(num%m!=0){                              // check if we can go to the right
                    if(ar[num+1]=='.'){
                        adj[num].pb(num+1);
                        adj[num+1].pb(num);
                    }
                }
                if(num<=(n-1)*m){                         // check if we can go to below
                    if(ar[num+m]=='.'){
                        adj[num+m].pb(num);
                        adj[num].pb(num+m);
                    }
                }
            }
        }
    }
    vector<int> visited;                                // use vector to pass by value(not refrence)
    visited.assign(n*m+1,0);
    if(dfs(v,visited,1))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
