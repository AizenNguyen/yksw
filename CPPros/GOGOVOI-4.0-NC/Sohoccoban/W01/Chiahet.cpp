#include<iostream>
using namespace std;
bool check6=true;
short tmp;
int ssz;
long long sum,sle,schan;
string s,stmp;
void solve(){
	ssz=s.size();
	for(int i=0;i<ssz;i++){
		tmp=s[i]-'0';
		sum+=tmp;
		if((i+1)&1) sle+=tmp;
		else schan+=tmp;
	}
	//2
	if(!((s[ssz-1]-'0')&1)) cout<<"YES\n";
	else{
		cout<<"NO\n";
		check6=false;
	}
	//3
	if(sum%3==0) cout<<"YES\n";
	else{
		cout<<"NO\n";
		check6=false;
	}
	//4
	if(ssz==1) cout<<(((s[ssz-1]-'0')%4==0)?"YES\n":"NO\n");
	else{
		tmp=s[ssz-2]-'0';
		tmp*=10;
		tmp+=s[ssz-1]-'0';
		cout<<((tmp%4==0)?"YES\n":"NO\n");
	}
	//5
	cout<<(((s[ssz-1]-'0')%5==0)?"YES\n":"NO\n");
	//6
	cout<<(check6?"YES\n":"NO\n");
	//8
	if(ssz<=2){
		if(s=="8"||s=="16") cout<<"YES\n";
		else cout<<"NO\n";
	}
	else{
		tmp=s[ssz-3]-'0';
		tmp*=10;
		tmp+=s[ssz-2]-'0';
		tmp*=10;
		tmp+=s[ssz-1]-'0';
		cout<<((tmp%8==0)?"YES\n":"NO\n");
	}
	//9
	cout<<((sum%9==0)?"YES\n":"NO\n");
	//10
	cout<<((s[ssz-1]=='0')?"YES\n":"NO\n");
	//11
	cout<<(((sle-schan)%11==0)?"YES\n":"NO\n");
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	solve();
}