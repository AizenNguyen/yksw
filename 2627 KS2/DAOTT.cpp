#include<iostream>
#include<algorithm>
using namespace std;
short n,u,v,l,r;
int k;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("DAOTT.INP","r",stdin);
    freopen("DAOTT.OUT","w",stdout);
    cin>>n>>k>>u>>v>>l>>r;
    short a[n+1]={};
    for(int i=1;i<=n;i++)
        a[i]=i;
    for(int i=1;i<=k;i++){
    	reverse(a+u,a+1+v);
    	reverse(a+l,a+1+r);
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<'\n';
}