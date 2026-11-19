#include<iostream>
#include<algorithm>
using namespace std;
int a,b;
int gcd(int n,int m){
	return m==0?n:gcd(m,n%m);
}
void mmm(){
	int gcd=__gcd(a,b);
	cout<<gcd<<" "<<1LL*a/gcd*b;
}
void nnn(){
	int gcduse=gcd(a,b);
	cout<<gcduse<<" "<<1LL*a/gcduse*b;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>a>>b;
	nnn();
}