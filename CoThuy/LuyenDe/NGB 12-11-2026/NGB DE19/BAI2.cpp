#include<iostream>
using namespace std;
string s,name;
int main(){
	if(fopen("BAI2.INP","r")){
		freopen("BAI2.INP","r",stdin);
		freopen("BAI2.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	while(cin>>s) name=s;
	cout<<name;
}