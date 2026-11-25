#include<iostream>
#include<algorithm> //solve
#include<vector>
using namespace std;
const int MAXN=1e6+6;
int n,m;
void solve_pf(){
    int x,MINlen=n-m;
    long long MIN=1e18;
    vector<long long> pf(n+1);
    for(int i=1;i<=n;i++){
        cin>>x;
        pf[i]=pf[i-1]+x;
    }
    for(int i=0;i<=m;i++) MIN=min(MIN,pf[MINlen+i]-pf[i]);
    cout<<pf[n]-MIN<<'\n';
}
void solve_sw(){
    int MINlen=n-m;
    long long MIN,snow,res;
    snow=res=0;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        res+=a[i];
        if(i<=MINlen) snow+=a[i];
    }
    MIN=snow;
    for(int l=1,r=MINlen+1;r<=n;++l,++r){
        snow=snow-a[l]+a[r];
        if(snow<MIN) MIN=snow;
    }
    cout<<res-MIN<<'\n';
}
int main(){
    if(fopen("BAI3.INP","r")){
        freopen("BAI3.INP","r",stdin);
        freopen("BAI3.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    //solve_pf();
    solve_sw();
}