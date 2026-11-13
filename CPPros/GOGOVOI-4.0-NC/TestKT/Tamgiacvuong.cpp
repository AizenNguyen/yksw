#include<iostream>
using namespace std;
long long a,b,c;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>a>>b>>c;
	if(a+b>c&&a+c>b&&b+c>a){
		a=a*a;
		b=b*b;
		c=c*c;
		if(a+b==c||a+c==b||b+c==a) cout<<"YES";
		else cout<<"NO";
	}
	else cout<<"NO";
}