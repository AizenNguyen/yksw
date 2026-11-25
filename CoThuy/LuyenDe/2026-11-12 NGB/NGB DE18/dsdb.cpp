#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int main(){
	if(fopen("dsdb.inp","r")){
		freopen("dsdb.inp","r",stdin);
		freopen("dsdb.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
	for(int i=n;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			dp[i][j]=(a[i]==a[j])?dp[i+1][j-1]:(min(dp[i+1][j],dp[i][j-1])+1);
	cout<<dp[1][n];
}
