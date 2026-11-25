#include<iostream>
using namespace std;
unsigned long long n;
short res;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("tongchuso.inp","r",stdin);
	freopen("tongchuso.out","w",stdout);
	cin>>n;
	while(n){
		res+=n%10;
		n/=10;
	}
	cout<<res;
}