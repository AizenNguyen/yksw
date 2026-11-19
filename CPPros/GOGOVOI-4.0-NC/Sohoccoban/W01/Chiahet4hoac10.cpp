#include<iostream>
using namespace std;
long long l,r,cnt;
void brute(){
	for(int i=l;i<=r;i++)
		if(i%4==0&&i%10==0)
			cnt++;
	cout<<cnt<<'\n';
	cnt=0;
}
void solve(){
	
	cout<<cnt<<'\n';
	cnt=0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>l>>;r
	brute();
	//solve();
}