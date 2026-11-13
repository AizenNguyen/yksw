#include<iostream>
using namespace std;
short a,b,c,d;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>a>>b>>c>>d;
	if((a==c&&b==d)||(b==c&&a==d)) cout<<"YES";
	else cout<<"NO";
}