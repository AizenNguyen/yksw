#include<iostream>
using namespace std;
short k;
int x,ssz;
string s,tmp;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("DADANG.INP","r",stdin);
	//freopen("DADANG.OUT","w",stdout);
	cin>>k>>x>>s;
	ssz=s.size();
	for(int i=1;i<=ssz;i++){
		tmp="";
		for(int j=i;j<=ssz;j++)
			tmp+=s[j];
	}
}