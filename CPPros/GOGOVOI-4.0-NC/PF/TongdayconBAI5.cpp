#include<iostream>
using namespace std;
short t;
int n;
void solve(){
    int x;
    long long pf,minpf,maxneg,maxsub1,maxsub2;
    pf=minpf=maxsub1=0;
    maxneg=maxsub2=-1e18;
    for(int i=1;i<=n;i++){
        cin>>x;
        pf=pf+x;
        if(x>0) maxsub1+=x;
        else if(x<=0) maxneg=maxneg>x?maxneg:x;
        maxsub2=maxsub2>pf-minpf?maxsub2:pf-minpf;
        minpf=minpf<pf?minpf:pf;
    }
    if(maxsub1==0&&maxneg!=-1e18) maxsub1=maxneg;
    cout<<maxsub1<<" "<<maxsub2<<'\n';
}
void solve_kadane(){
    int x;
    long long s,maxneg,maxsub1,maxsub2;
    s=maxsub1=0;
    maxneg=maxsub2=-1e18;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x>0) maxsub1+=x;  
        else if(x<=0) maxneg=maxneg>x?maxneg:x;
        s=s>=0?s+x:x;
        maxsub2=maxsub2>s?maxsub2:s;
    }
    if(maxsub1==0&&maxneg!=-1e18) maxsub1=maxneg;
    cout<<maxsub1<<" "<<maxsub2<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        //brute();
        //solve();
        solve_kadane();
    }
}