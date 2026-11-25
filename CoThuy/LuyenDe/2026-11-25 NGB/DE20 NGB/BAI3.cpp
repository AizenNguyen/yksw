#include<iostream>
using namespace std;
int m,n,lendiff,a[1000006];
long long mindiff,diffnow,s,smax;
void solve(){
	lendiff=m-n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		s+=a[i];
	}
	for(int i=1;i<=lendiff;i++) diffnow+=a[i];
	mindiff=diffnow;
	for(int i=lendiff+1;i<=n;i++){
		diffnow=diffnow+a[i]-a[i-lendiff];
		mindiff=mindiff<diffnow?mindiff:diffnow;
	}
	cout<<s-mindiff;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>m>>n;
	solve();
}