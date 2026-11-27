// Bitmask DP (N <= 20): Bai mau Nguoi du lich TSP / Hamilton ngan nhat O(2^N * N^2)
// Luu y: dung vector<vector<long long>> cap phat dung (1<<n)*n de tiet kiem bo nho tinh
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=20;
const long long INF=2e18;
int n;
long long w[MAXN][MAXN];

long long tsp_min(){
	int full=(1<<n)-1;
	vector<vector<long long>> dp(1<<n,vector<long long>(n,INF));
	dp[1][0]=0;
	for(int mask=1;mask<=full;mask++){
		if(!(mask&1)) continue;
		for(int u=0;u<n;u++){
			if(dp[mask][u]==INF) continue;
			for(int v=0;v<n;v++){
				if((mask>>v)&1) continue;
				if(w[u][v]>=INF/2) continue;
				int nmask=mask|(1<<v);
				dp[nmask][v]=min(dp[nmask][v],dp[mask][u]+w[u][v]);
			}
		}
	}
	long long res=INF;
	for(int u=1;u<n;u++)
		if(dp[full][u]<INF&&w[u][0]<INF/2)
			res=min(res,dp[full][u]+w[u][0]);
	return res>=INF?-1:res;
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) cin>>w[i][j];
		cout<<tsp_min()<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
