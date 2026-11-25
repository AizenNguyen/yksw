#include<iostream>
using namespace std;
long long x,y,res;
void Try(long long n){
    if(n>y)
        return;
    if(x<=n)
        res++;
    Try(10*n+7);
    Try(10*n+9);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("hoahong.inp","r",stdin);
    //freopen("hoahong.out","w",stdout);
    cin>>x>>y;
    Try(0);
    cout<<res;
}
