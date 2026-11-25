#include<iostream>
using namespace std;
int n;
void brute(){
	long long cnt=0;
	for(int i=1;i<=n-2;i++)
		for(int j=i+1;j<=n-1;j++)
			for(int k=j+1;k<=n;k++)
				if(i+j+k==n) cnt++;
	cout<<cnt;
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