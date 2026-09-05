#include<iostream>
#include<unordered_map>
using namespace std;
int n,m,x,res;
unordered_map<int,int> ump;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("binhchon.inp","r",stdin);
    //freopen("binhchon.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>x;
        ump[x]++;
        res=(res>ump[x]?res:ump[x]);
    }
    cout<<res;
}
