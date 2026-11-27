// Quy hoach dong tren doan [l,r] (Interval DP): O(N^3), N <= 500
// Bai mau: Gop N dong soi ke nhau voi chi phi min (chi phi gop = tong kich thuoc 2 dong)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;

const int MAXN=505;
const long long INF=2e18;
int n;
long long a[MAXN],pf[MAXN],dp[MAXN][MAXN];

long long interval_dp(){
	for(int i=1;i<=n;i++){
		pf[i]=pf[i-1]+a[i];
		dp[i][i]=0;
	}
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			dp[l][r]=INF;
			long long cost_lr=pf[r]-pf[l-1];
			for(int k=l;k<r;k++)
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+cost_lr);
		}
	}
	return dp[1][n];
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n){
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<interval_dp()<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
