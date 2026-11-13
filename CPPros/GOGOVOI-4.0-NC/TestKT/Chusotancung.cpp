#include<iostream>
using namespace std;
long long a,b,c;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>a>>b>>c;
	for(int i=a+1;i<=b;i++)
		a*=i%c;
	cout<<a%c;
}