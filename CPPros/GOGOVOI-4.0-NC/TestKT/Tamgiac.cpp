#include<iostream>
using namespace std;
short a,b,c;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>a>>b>>c;
	if(a+b+c!=180){
		cout<<0;
		return 0;
	}
	if(a==b&&a==c) cout<<"DEU";
	else if(a==b||a==c||b==c) cout<<"CAN";
	else if(a==90||b==90||c==90) cout<<"VUONG";
	else cout<<"THUONG";
}