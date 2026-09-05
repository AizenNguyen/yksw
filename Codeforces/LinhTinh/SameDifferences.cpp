#include<iostream>
#include<vector>
using namespace std;
short t;
int n;
vector<int> a(200010,0);
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=1;i<=n;++i)
            cout<<a[i]<<'\n';
        a.clear();
    }
}

