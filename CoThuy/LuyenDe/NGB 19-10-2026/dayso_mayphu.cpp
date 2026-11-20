#include<iostream>
using namespace std;
int n;
long long res;
void sub1(){
    for(int i=1;i<=n;i++)
        res+=i;
    cout<<res<<'\n';
}
void sub2(){
    cout<<1LL*n*(n+1)/2<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("DAYSO.INP","r",stdin);
    freopen("DAYSO.OUT","w",stdout);
    cin>>n;
    //sub1();
    sub2();
}