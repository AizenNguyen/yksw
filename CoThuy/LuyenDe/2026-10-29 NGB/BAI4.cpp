#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<long long> a;
long long solve(int i) {
    if (i>=n) return 0;
    long long MAX,cur,nxt;
    MAX=-1e18;
    for (int x=1;x<=3;x++){
        cur=0;
        for (int k=i;k<min(n,i+x);k++)
            cur+=a[k];
        nxt=solve(i+2*x);
        MAX=max(MAX,cur+nxt);
    }
    return MAX;
}
int main(){
	if(fopen("BAI4.INP","r")){
		freopen("BAI4.INP","r",stdin);
		freopen("BAI4.OUT","w",stdout);
	}
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    a.resize(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    cout<<solve(0)<<"\n";
}