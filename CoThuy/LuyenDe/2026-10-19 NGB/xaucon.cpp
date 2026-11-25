#include<iostream>
using namespace std;
int ssz,cnt,res;
string s;
void sub1(){
	ssz=s.size();
	for(int i=1;i<=ssz;i++){
		if(s[i]=='0') cnt++;
		else{
			res=res>cnt?res:cnt;
			cnt=0;
		}
	}
	cout<<res<<'\n';
	res=0;
}
void sub2(){
	int ssz=s.size(),l=0,r=0;
	while(r<=ssz){
		if(s[l]=='0'&&s[r]=='1'){
			cnt=r-l;
			res=res>cnt?res:cnt;
			l=r;
		}
		else if(s[l]=='1'&&s[r]=='0')
			l=r;
		r++;
	}
	cout<<res<<'\n';
	res=0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("XAUCON.INP","r",stdin);
	freopen("XAUCON.OUT","w",stdout);
	cin>>s;
	//sub1();
	sub2();
}