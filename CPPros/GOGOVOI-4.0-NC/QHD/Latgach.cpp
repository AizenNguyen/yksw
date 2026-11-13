#include<iostream>
using namespace std;
const int MOD=1e9+7;
int n;
long long a[100010];
long long ans(long long x){
	if(x==0||x==1) return 1;
	if(a[x]) return a[x];
	return a[x]=((ans(x-2)%MOD)+(ans(x-1)%MOD))%MOD;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	cout<<ans(n);
}