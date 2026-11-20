#include<iostream>
using namespace std;
string s;
long long cnt,res;
void sub1(){
	for(char c:s){
		if(c=='0') cnt++;
		else{
			res=(res>cnt?res:cnt);
			cnt=0;
		}
	}
	cout<<res;
}
void sub2(){
	int ssz=s.size(),l=0,r=0;
	while(r<=ssz){
		if(s[r-1]=='0'&&s[r]=='1'){
			res=(res>r-l?res:r-l);
			l=r;
		}
		else if(s[r-1]=='1'&&s[r]=='0') l=r;
		r++;
	}
	cout<<res;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("XAUCON.INP","r",stdin);
	freopen("XAUCON.OUT","w",stdout);
	cin>>s;
	// if(s.size()<=1000)
	// 	sub1();
	// else
		sub2();
}