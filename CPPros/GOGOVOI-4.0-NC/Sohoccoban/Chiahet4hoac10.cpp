#include<iostream>
using namespace std;
long long l,r,tmpl,tmpr,cnt4,cnt10,res;
void brute(){
	for(long long i=l;i<=r;i++)
		if(i%4==0||i%10==0)
			res++;
	cout<<res;
}
void solve(){
	// if(l%4!=0) tmpl=(l/4+1)*4;
	// else tmpl=l;
	// if(r%4!=0) tmpr=r/4*4;
	// else tmpr=r;
	// cnt4=(tmpr-tmpl)/4+1; 
	// if(l%10!=0) tmpl=(l/10+1)*10;
	// else tmpl=l;
	// if(r%10!=0) tmpr=r/10*10;
	// else tmpr=r;
	// cnt10=(tmpr-tmpl)/10+1;
	// cout<<cnt4<<" "<<cnt10;
	// tmpl=tmpr=0;
	cout<<(r/4+r/10)-(l/4+l/10);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>l>>r;
	brute(); cout<<'\n';
	solve(); cout<<'\n';
}