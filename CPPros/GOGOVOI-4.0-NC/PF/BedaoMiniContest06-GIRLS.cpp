#include<iostream>
using namespace std;
int m,n,k,a[1000006];
long long pf[1000006];
void solve(){
	for(int i=1;i<=m;i++){
		cin>>a[i];
		pf[i]=pf[i-1]+a[i];
	}

}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>m>>n>>k;
	//brute();
	solve();
}