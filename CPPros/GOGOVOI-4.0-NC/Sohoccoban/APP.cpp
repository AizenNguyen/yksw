#include<iostream>
using namespace std;
long long a,p;
void brute(){
	for(int i=a;i<=1000000000000;i++)
		if(i%p==0){
			cout<<i;
			break;
		}
	cout<<'\n';
}
void solve(){
	cout<<((a/p)+1)*p<<'\n';
	//cout<<(a/p*p)+p<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>a>>p;
	if(a<=10000000) brute();
	else solve();
}