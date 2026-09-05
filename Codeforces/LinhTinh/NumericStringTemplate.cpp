#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
string s;
short t;
int n,m,a[200010];
bool check;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        cin>>m;
        while(m--){
            unordered_map<int,char> umpn;
            unordered_map<char,int> umpc;
            cin>>s;
            if(s.size()!=n){
                cout<<"NO"<<'\n';
                continue;
            }
            check=true;
            for(int i=0;i<n;++i){
                if(umpc.count(s[i]))
                    if(umpc[s[i]]!=a[i+1]){
                        check=false;
                        break;
                    }
                if(umpn.count(a[i+1]))
                    if(umpn[a[i+1]]!=s[i]){
                        check=false;
                        break;
                    }
                umpc[s[i]]=a[i+1];
                umpn[a[i+1]]=s[i];
            }
            cout<<(check==true?"YES":"NO")<<'\n';
        }
    }
}
