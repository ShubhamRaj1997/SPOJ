#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define MAX 19
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
bool dFloor[MAX][MAX],dummy[MAX][MAX];
int n,m;                                        /// n rows m columns
void flip(int x,int y){
    dFloor[x][y]=!dFloor[x][y];
    if(x>0)dFloor[x-1][y]=!dFloor[x-1][y];
    if(x<n-1)dFloor[x+1][y]=!dFloor[x+1][y];
    if(y>0)dFloor[x][y-1]=!dFloor[x][y-1];
    if(y<m-1)dFloor[x][y+1]=!dFloor[x][y+1];
    return;
}
int main(){
    while(1){
        cin>>m>>n;bool found=0;
        if(m==0 && n==0)break;
        mset(dFloor,0);                         /// all lights off
        loop(i,n){
            string ss;cin>>ss;                  /// Input
            loop(j,m){
                dFloor[i][j]=(ss[j]=='1')?1:0;
            }
        }
        memcpy(dummy,dFloor,sizeof(dummy));
        loop(mask,1<<m){
            vector<pii > v;
            memcpy(dFloor,dummy,sizeof(dFloor));
            loop(j,m){
                if(mask & (1<<j)){
                   flip(0,j);
                   v.pb(mp(0,j));
                }
            }
            loop1(i,n){
                loop(j,m){
                    if(!dFloor[i-1][j]){
                        flip(i,j);
                        v.pb(mp(i,j));
                    }
                }
            }bool is=1;
            loop(i,n){
                loop(j,m){
                   is&=dFloor[i][j];
                   if(!is)break;
                }
            }
            if(is){
                found=1;int size=v.size();
                cout<<size<<endl;
                loop(i,size){
                    cout<<(v[i].s+1)<<" "<<(v[i].f+1)<<endl;
                }break;
            }
        }
       if(!found)cout<<-1<<endl;
    }
}
