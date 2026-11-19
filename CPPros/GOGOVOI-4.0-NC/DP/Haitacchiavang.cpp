#include<iostream>
using namespace std;
short n,vang=100;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	vang-=(n-1)/2;
	cout<<100-(n-1)/2;
	for(int i=2;i<=n;i++) cout<<(i&1?" 1":" 0");
}