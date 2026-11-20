#include<iostream>
using namespace std;
short ssz;
string s;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	s=" "+s;
	ssz=s.size();
	if(ssz>10){
		cout<<10;
		return 0;
	}
	for(int i=1;i<=ssz;++i){
		if((i==1||i==2)&&!(s[i]>='A'&&s[i]<='Z')){
			cout<<i;
			return 0;
		}
		if(i==3&&s[i]!='-'){
			cout<<i;
			return 0;
		}
		if((i==4||i==5||i==6)&&!(s[i]>='0'&&s[i]<='9')){
			cout<<i;
			return 0;
		}
		if(i==7&&s[i]!='.'){
			cout<<i;
			return 0;
		}
		if((i==8||i==9)&&!(s[i]>='0'&&s[i]<='9')){
			cout<<i;
			return 0;
		}
	}
	cout<<0;
}