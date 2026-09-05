#include<iostream>
using namespace std;
const int maxn=1000001;
int n,a[maxn];
long long tmp,pf[maxn],cntmin,cntmax=-100000000000000000;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    a[0]=pf[0]=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        pf[i]=pf[i-1]+a[i];
        cntmin=(cntmin>pf[i]?pf[i]:cntmin);
        tmp=pf[i]-cntmin;
        cntmax=(cntmax>tmp?cntmax:tmp);
    }
    cout<<cntmax;
}
