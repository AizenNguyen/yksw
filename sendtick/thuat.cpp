#include<bits/stdc++.h>
using namespace std;
long long n,k,mina,maxa,len,len_max=1;
int a[200005];
void brute(){
    for(int i=1;i<=n;i++){
        mina=maxa=a[i];
        for(int j=i;j<=n;j++){
            mina=mina<a[j]?mina:a[j];
            maxa=maxa>a[j]?maxa:a[j];
            if(maxa-mina>k) break;
            else{
                len=j-i+1;
                len_max=len_max>len?len_max:len;
                //for(int l=i;l<=j;l++) cout<<a[l]<<" ";
                //cout<<'\n';
            }
        }
    }
    cout<<len_max;
}
void solve(){
    long long l,r;
    l=r=1;
    mina=maxa=a[r];
    while(r<=n){
        mina=mina<a[r]?mina:a[r];
        maxa=maxa>a[r]?maxa:a[r];
        if(maxa-mina>k){
            mina=maxa=a[r];
            len_max=len_max>r-l?len_max:r-l;
            l++;
        }
        else r++;
    }
    len_max=len_max>r-l?len_max:r-l;
    cout<<len_max;
}
int main(){
    if(fopen("CAU2.INP","r")){
        freopen("CAU2.INP","r",stdin);
        freopen("CAU2.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    //brute();
    solve();
}