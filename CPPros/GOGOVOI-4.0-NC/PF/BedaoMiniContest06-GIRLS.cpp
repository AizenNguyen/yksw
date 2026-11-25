#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int m,n,k,a[1000006];
long long res=-2,pf[1000006];
void solve(){
	map<int,int> freq; freq[0]=1;
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