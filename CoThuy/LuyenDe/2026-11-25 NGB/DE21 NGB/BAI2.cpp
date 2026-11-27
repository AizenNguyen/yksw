#include<iostream>
using namespace std;
long long n,a;
int main(){
	if(fopen("BAI2.INP","r")){
		freopen("BAI2.INP","r",stdin);
		freopen("BAI2.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>a;
	cout<<1*n+(a*n*(n-1))/2;
}