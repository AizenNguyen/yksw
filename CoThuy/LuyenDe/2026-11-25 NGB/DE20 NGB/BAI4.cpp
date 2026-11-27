#include<iostream>
using namespace std;
long long n,cnt;
void brute(){
	for(int i=1;i<=-2n;i++)
		for(int j=i+1;j<=n-1;j++)
			for(int k=j+1;k<=n;k++)
				if(1LL*i+j+k==n) cnt++;
	cout<<cnt<<'\n';
}
void solve(){

}
int main(){
	if(fopen("BAI4.INP","r")){
		freopen("BAI4.INP","r",stdin);
		freopen("BAI4.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	brute();
	//solve();
}