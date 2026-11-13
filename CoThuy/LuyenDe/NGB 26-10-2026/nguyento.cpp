#include<iostream>
#include<cmath>
using namespace std;
long long n,sqrtn;
bool prime(long long x){
	if(x<2) return false;
	if(x==2||x==3) return true;
	if(x%2==0||x%3==0) return false;
	for(long long i=5;i*i<=x;i+=6)
		if(x%i==0||x%(i+2)==0)
			return false;
	return true;
}
void solve(){
	if(n<=4){
		cout<<4<<'\n';
		return;
	}
	sqrtn=sqrtl(n);
	while(sqrtn*sqrtn<n) sqrtn++;
	if(sqrtn%2==0) sqrtn++;
	for(long long i=sqrtn; ;i+=2)
		if(prime(i)){
			cout<<i*i<<'\n';
			break;
		}
}
int main(){
	if(fopen("nguyento.inp","r")){
		freopen("nguyento.inp","r",stdin);
		freopen("nguyento.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	solve();
}