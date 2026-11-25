#include<iostream>
using namespace std;
long long n;
void sub1(){
	long long res=0;
	for(int i=1;i<=n;i++)
		res+=i;
	cout<<res<<'\n';
	res=0;
}
void sub2(){
	cout<<n*(n+1)/2<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("DAYSO.INP","r",stdin);
	freopen("DAYSO.OUT","w",stdout);
	cin>>n;
	//sub1();
	sub2();
}