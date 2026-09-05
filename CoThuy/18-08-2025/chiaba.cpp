#include<iostream>
#include<algorithm>
using namespace std;
int n,last,a[1000010];
long long tmp,cnt,pf[1000010];
bool check[1000010];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("chiaba.inp","r",stdin);
    //freopen("chiaba.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        pf[i]=pf[i-1]+a[i];
    }
    if(pf[n]%3!=0){
        cout<<0;
        return 0;
    }
    tmp=pf[n]/3;
    for(int i=1;i<=n-1;++i)
        if(pf[i]==tmp)
            check[i]=true;
    for(int i=1;i<=n-1;++i)
        if(pf[i]==tmp*2){
            cnt+=cnt+count(check+last+1,check+i,true);
            last=i;
        }
    cout<<cnt;
    //8 -2 6 -1 3 -2   4 5 -1
}
