#include<iostream>
#include<cmath>
using namespace std;
long long n,sqrtn;
int snt(int x){
	if(x<2) return false;
	if(x==2||x==3) return true;
	if(x%2==0||x%3==0) return false;
	for(int i=5;i*i<=x;i+=6)
		if(x%i==0)
			return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("nguyento.inp","r",stdin);
	//freopen("nguyento.out","w",stdout);
	cin>>n;
	sqrtn=sqrt(n);
	if(sqrtn*sqrtn!=n) sqrtn++;
	
}