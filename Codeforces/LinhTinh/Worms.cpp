#include<iostream>
#include<algorithm>
using namespace std;
int n,m,q,pf[1000010];
short a[1000010];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        pf[i]=pf[i-1]+a[i];
    }
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>q;
        auto it=lower_bound(pf,pf+n+1,q);
        cout<<it-pf<<'\n';
    }
}
