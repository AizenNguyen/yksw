#include<iostream>
#include<map>
using namespace std;
int n,m,x,res;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("binhchon.inp","r",stdin);
    freopen("binhchon.out","w",stdout);
    cin>>n>>m;
    map<int,int> mp;
    for(int i=1;i<=n;++i){
        cin>>x;
        mp[x]++;
        res=(res>mp[x]?res:mp[x]);
    }
    cout<<res;
}
