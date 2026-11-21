#include<iostream>
using namespace std;
long long n,cnt;
void brute(){
	for(int i=1;i<=n;i++)
		if(n%i==0) cnt++;
	cout<<cnt-1;
}
void solve(){
	for(long long i=1;i*i<=n;i++)
		if(n%i==0){
			cnt++;
			if(n/i!=i) cnt++;
		}
	cout<<cnt-1;
}
int main(){
	if(fopen("BAI1.INP","r")){
		freopen("BAI1.INP","r",stdin);
		freopen("BAI1.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	//brute();
	solve();
}