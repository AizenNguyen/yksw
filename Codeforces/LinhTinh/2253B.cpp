#include<iostream>
#include<map>
#include<vector>
using namespace std;
short t;
int n;
vector<int> a;
map<int,int> mp;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>a[i];
            mp[a[i]]++;
        }
        cout<<mp.size()<<'\n';
    }
}
