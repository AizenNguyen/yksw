#include<iostream>
#include<vector>
using namespace std;
int k,last,cnt,sntsize;
bool dssnt[100010];
vector<int> snt;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("bobaso.inp","r",stdin);
    //freopen("bobabso.out","w",stdout);
    cin>>k;
    snt.emplace_back(2);
    dssnt[0]=dssnt[1]=1;
    for(int i=4;i<=k;i+=2)
        dssnt[i]=1;
    for(int i=3;i*i<=k;++i)
        if(dssnt[i]==0){
            snt.emplace_back(i);
            last=i;
            for(int j=i+i;j<=k;j+=i)
                dssnt[j]=1;
        }
    for(int i=last+1;i<=k;++i)
        if(!dssnt[i]&&i!=2)
            snt.emplace_back(i);
    sntsize=snt.size();
    for(int x=0;x<sntsize;++x)
        for(int y=x;y<sntsize;++y)
            for(int z=y;z<sntsize;++z)
               if(snt[x]+snt[y]+snt[z]==k)
                   cnt++;
    cout<<cnt;
}
