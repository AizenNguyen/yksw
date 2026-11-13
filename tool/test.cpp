#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
short n,m;
vector<pair<short,int>> ldb;
void brute(){
    int MAX;
    short a[n+10][m+10],pftime[n+10]={};
    int cnt_zero[n+10]={};
    for(short i=1;i<=n;i++){
        for(short j=1;j<=m;j++){
            cin>>a[i][j];
            pftime[i]+=a[i][j];
            if(a[i][j]==0) cnt_zero[i]++;
        }
    }
    for(int i=1;i<=n;i++) cnt_zero[i]=(m-cnt_zero[i])*10;
    sort(cnt_zero+1,cnt_zero+n+1);
    MAX=cnt_zero[n];
    for(int i=n;i>=1;i--)
        if(cnt_zero[i]==MAX)
            ldb.emplace_back(pftime[n-i+1],n-i+1);
    sort(ldb.begin(),ldb.end());
    for(auto x:ldb){
        cout<<x.first<<" "<<x.second<<'\n';
    }
}
int main(){
    if(fopen("team.inp","r")){
        freopen("team.inp","r",stdin);
        freopen("team.out","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    brute();
}