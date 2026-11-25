#include<iostream>
using namespace std;
short cnt;
string s;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("matxich.inp","r",stdin);
	//freopen("matxich.out","w",stdout);
	cin>>s;
	for(char c:s)
		if(c=='0')
			cnt++;
	cout<<cnt;
}