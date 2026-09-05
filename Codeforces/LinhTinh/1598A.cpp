#include<iostream>
#include<string>
using namespace std;
short t,n,last,a[110];
string s;
bool check;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        check=1;
        cin>>n;
        cin>>s;
        for(short i=1;i<=n;++i)
            a[i]+=s[i]-'0';
        cin>>s;
        for(short i=1;i<=n;++i){
            a[i]+=s[i]-'0';
            if(a[i]==2)
                check=0;
            a[i]=0;
        }
        if(!check){
            cout<<"NO"<<'\n';
            continue;
        }
        cout<<"YES"<<'\n';
    }
}
