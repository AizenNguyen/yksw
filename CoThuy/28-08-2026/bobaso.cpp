#include<iostream>
#include<vector>
using namespace std;
int k,sntsize,last=3,cnt;
bool dssnt[100010];
vector<int> snt;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("bobaso.inp","r",stdin);
    //freopen("bobaso.out","w",stdout);
    cin>>k;
    dssnt[0]=dssnt[1]=1;
    for(int i=4;i<=k;i+=2)
        dssnt[i]=1;
    for(int i=3;i*i<=k;i+=2)
        if(!dssnt[i])
            for(int j=i*i;j<=k;j+=2*i)
                dssnt[j]=1;
    snt.emplace_back(2);
    for(int i=last;i<=k;i+=2)
        if(!dssnt[i])
            snt.emplace_back(i);
    sntsize=snt.size();
    for(int x=0;x<sntsize;++x)
        for(int y=x;y<sntsize;++y)
            for(int z=y;z<sntsize;++z)
                if(snt[x]+snt[y]+snt[z]==k)
                    cnt++;
    cout<<cnt;
}
