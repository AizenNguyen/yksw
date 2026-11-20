#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int MAX=15485863;
short t;
int n,pos=2,last;
long long sum[100010];
bool dssnt[MAX+10];
void ssnt(){
    sum[1]=2;
    dssnt[0]=dssnt[1]=1;
    for(int i=4;i<=MAX;i+=2)
        dssnt[i]=1;
    for(int i=3;i*i<=MAX;i+=2)
        if(!dssnt[i]){
            sum[pos]=sum[pos-1]+i;
            pos++;
            last=i;
            for(int j=i*i;j<=MAX;j+=i)
                dssnt[j]=1;
        }
    for(int i=last+1;i<=MAX;++i)
        if(!dssnt[i]){
            sum[pos]=sum[pos-1]+i;
            pos++;
        }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("nguyento.inp","r",stdin);
    freopen("nguyento.out","w",stdout);
    cin>>t;
    ssnt();
    for(int i=1;i<=t;++i){
        cin>>n;
        cout<<sum[n]<<'\n';
    }
}