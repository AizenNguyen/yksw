#include<iostream>
using namespace std;
bool prime[1000006];
int n,x;
long long pf,maxs=-1e18;
long long pre[1000006];
void sieve(){
    prime[0]=prime[1]=1;
    for(int i=4;i<=1000000;i+=2) prime[i]=1;
    for(int i=3;i*i<=1000000;i++)
        if(!prime[i])
            for(int j=i*i;j<=1000000;j+=i)
                prime[j]=1;
}
void brute(){
    for(int i=1;i<=n;i++){
        cin>>x;
        pre[i]=pre[i-1]+x;
    }
    //for(int i=1;i<=n;i++) cout<<pre[i]<<" ";
    for(int i=2;i<=n;i++){
        if(!prime[i])
            for(int j=i;j<=n;j++)
                if(!prime[j]){
                    maxs=maxs>pre[j]-pre[i-1]?maxs:pre[j]-pre[i-1];
                    //cout<<i<<" "<<j<<" "<<pre[j]-pre[i-1]<<'\n';
                }
    }
    cout<<maxs<<'\n';
}
void solve(){
    long long minpf=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        pf+=x;
        if(i==2){
            maxs=x;
            minpf=pf-x;
        }
        else if(!prime[i]){
            maxs=maxs>pf-minpf?maxs:pf-minpf;
            maxs=maxs>x?maxs:x;
            minpf=minpf<pf-x?minpf:pf-x;
        }
    }
    cout<<maxs<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    sieve();
    //brute();
    solve();
}