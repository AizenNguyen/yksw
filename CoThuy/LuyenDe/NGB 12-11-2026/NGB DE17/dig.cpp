#include<iostream>
using namespace std;
int t;
long long a,b;
void solve(){
    cin>>a>>b;
    long long len=b-a+1,sum=a+b,rem;
    if(len%2==0) rem=((len/2)%9)*(sum%9)%9;
    else rem=((sum/2)%9)*(len%9)%9;
    cout<<(rem==0?9:rem)<<'\n';
}
int main(){
    if(fopen("DIG.INP","r")){
        freopen("DIG.INP","r",stdin);
        freopen("DIG.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--) solve();
}