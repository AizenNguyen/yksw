#include<iostream>
using namespace std;
int n;
void brute(){
    int a[n+1]; a[0]=0;
    long long s,MAX=-1e18;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        s=0;
        for(int j=i;j<=n;j++){
            s+=a[j];
            if(MAX<s) MAX=s;
        }
    }
    cout<<MAX<<'\n';
    MAX=0;
}
void solve_pf(){
    int x,MAXpos;
    long long MIN=1e18,MAX=-1e18,res,pf[n+1];
    pf[0]=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        pf[i]=pf[i-1]+x;
        if(MAX<pf[i]){
            MAX=pf[i];
            MAXpos=i;
        }
    }
    for(int i=1;i<=MAXpos;i++)
        if(MIN>pf[i])
            MIN=pf[i];
    res=MAX-MIN;
    res=(res>pf[n]?res:pf[n]);
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    //brute();
    solve_pf();
}