#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%d",&t);
    while(t--){
        char s[500005];int k;
        scanf("%s ",&s);scanf("%d",&k);
        int n=strlen(s);//cout<<n<<endl;
        int a[n]={0},i=1,j=0;a[0]=0;
        while(i<n){
            if(s[i]==s[j]){
                a[i]=j+1;
                i++;j++;
            }
            else if(j==0){
                a[i]=0;i++;
            }
            else{
                j=a[j-1];
            }
        }
        int x=n-a[n-1];

        printf("%lld\n",1LL*(k-1)*x+n);

    }
}
