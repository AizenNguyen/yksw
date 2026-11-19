#include<iostream>
using namespace std;
long long n;
bool primecheck(int n){
	if(n<=1) return false;
	if(n==2||n==3) return true;
	if(n%2==0||n%3==0) return false;
	for(int i=5;1LL*i*i<=n;i+=6)
		if(n%i==0||n%(i+2)==0)
			return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	cout<<(primecheck(n)?"YES":"NO");
}