#include<iostream>
using namespace std;
string s;
int cnt,cnt0,cnt1;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>s;
    for(char c:s){
        if(c=='0')
            cnt0++;
        else
            cnt1++;
        if(cnt0==cnt1 || cnt0-1==cnt1 || cnt0==cnt1-1)
            //cnt++;
            cout<<cnt0<<" "<<cnt1<<'\n';
    }
    //cout<<cnt;
}
