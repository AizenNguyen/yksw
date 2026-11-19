#include<iostream>
using namespace std;
int n;
string s;
void solve_ifelse(){
    int res,len,lastpos;
    s=" "+s;
    res=n; lastpos=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='L'){
            len=i-lastpos;
            if(lastpos==0) res-=i;
            else if(s[lastpos]=='L') res-=len;
            else if(s[lastpos]=='R'){
                if((len+1)%2!=0) res-=len;
                else res-=len+1;
            }
            lastpos=i;
        }
        else if(s[i]=='R'){
            if(s[lastpos]=='R') res-=i-lastpos;
            lastpos=i;
        }
    }
    if(s[lastpos]=='R') res-=n-lastpos+1;
    cout<<res<<'\n';
    res=0;
}
void solve_sentinel(){
    int res,lastpos,newsz;
    res=lastpos=0;
    newsz=n+1;
    s="L"+s+"R";
    for(int i=1;i<=newsz;i++){
        if(s[i]=='.') continue;
        if(s[i]=='R'&&s[lastpos]=='L'){
            res+=i-lastpos-1;
        }
        else if(s[i]=='L'&&s[lastpos]=='R'){
            if((i-lastpos)%2==0)
                res++;
        }
        lastpos=i;
    }
    cout<<res<<'\n';
    res=0;
}
int main(){
    if(fopen("BAI4.INP","r")){
        freopen("BAI4.INP","r",stdin);
        freopen("BAI4.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>s;
    //solve_ifelse();
    solve_sentinel();
}