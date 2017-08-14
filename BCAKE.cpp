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

int main()
{
    /// find all the right-bottom corner cell containing rectangles and number of chocochips
    /// they do have :)
    int t;cin>>t;
    while(t--){
        int n,m,k;cin>>n>>m>>k;
        int chips[31][31];
        string s;
        loop1(i,n+1){
            cin>>s;
            loop1(j,m+1){
                chips[i][j]=chips[i-1][j]+chips[i][j-1]-chips[i-1][j-1]+((s[j-1]=='C')?1:0);
            }
        }
        if(!k){cout<<0<<endl;continue;}
        int ans=31*31;
        loop1(a,n+1){
            for(int b=a+1;b<=n;b++){
                loop1(c,m+1){
                    for(int d=c+1;d<=m;d++){
                            int chip=chips[b][d]-chips[b][c]-chips[a][d]+chips[a][c];
                            if(chip!=k)continue;
                            ans=min(ans,(d-c)*(b-a));
                    }
                }

            }
        }
        if(ans==31*31)
            cout<<"-1"<<endl;
        else
        cout<<ans<<endl;
    }

    return 0;
}
