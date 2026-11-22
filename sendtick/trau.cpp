#include<iostream>
#include<map>
using namespace std;
int n;
void brute(){
    int a[n+1];
    long long s,cnt;
    a[0]=cnt=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        s=0;
        for(int j=i;j<=n;j++){
            s+=a[j];
            if(s==0) cnt++;
        }
    }
    cout<<cnt<<'\n';
}
void solve_pf(){
    int x;
    long long cnt=0,pf[n+1]; pf[0]=0;
    map<long long,int> freq; freq[0]=1;
    for(int i=1;i<=n;i++){
        cin>>x;
        pf[i]=pf[i-1]+x;
        freq[pf[i]]++;
    }
    for(auto x:freq) cnt+=x.second*(x.second-1)/2;
    cout<<cnt<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    //brute();
    solve_pf();
}