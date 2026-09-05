#include<iostream>
using namespace std;
int main(){
    int n,q,l,r;
    cin>>n>>q;
    int a[n+1];
    long long pf[n+1];
    a[0]=pf[0]=0;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
        pf[i]=pf[i-1]+a[i];
    while(q--){
        cin>>l>>r;
        cout<<pf[r]-pf[l-1]<<'\n';
    }
}
