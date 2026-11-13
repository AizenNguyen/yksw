#include<iostream>
using namespace std;
short ssz,prime[8];
string s;
int main(){
	if(fopen("BAI2.INP","r")){
		freopen("BAI2.INP","r",stdin);
		freopen("BAI2.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	ssz=s.size();
	for(short i=0;i<ssz;i++)
		if(s[i]=='2'||s[i]=='3'||s[i]=='5'||s[i]=='7')
			prime[s[i]-'0']++;
	ssz=0;
	for(short i=2;i<=7;i++)
		if(prime[i]){
			cout<<i<<" ";
			ssz++;
		}
	if(ssz==0) cout<<0;
}