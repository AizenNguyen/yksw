// Bai toan Cai tui (Knapsack): 0/1 toi uu 1D, 0/1 co truy vet, Unbounded (chon vo han lan)
// Do phuc tap: O(N * W)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=1005;
const int MAXW=10005;
int n,W;
int w[MAXN];
long long v[MAXN];
long long dp1[MAXW],dp2[MAXN][MAXW];

// 0/1 Knapsack: duyet nguoc tu W ve w[i]
long long knapsack_01_1d(){
	for(int j=0;j<=W;j++) dp1[j]=0;
	for(int i=1;i<=n;i++)
		for(int j=W;j>=w[i];j--)
			dp1[j]=max(dp1[j],dp1[j-w[i]]+v[i]);
	return dp1[W];
}

// 0/1 Knapsack co truy vet cac mon duoc chon
vector<int> knapsack_01_trace(long long& ans){
	for(int i=1;i<=n;i++)
		for(int j=0;j<=W;j++){
			dp2[i][j]=dp2[i-1][j];
			if(j>=w[i]) dp2[i][j]=max(dp2[i][j],dp2[i-1][j-w[i]]+v[i]);
		}
	ans=dp2[n][W];
	vector<int> chosen;
	int cur_w=W;
	for(int i=n;i>=1;i--){
		if(cur_w>=w[i]&&dp2[i][cur_w]==dp2[i-1][cur_w-w[i]]+v[i]){
			chosen.push_back(i);
			cur_w-=w[i];
		}
	}
	reverse(chosen.begin(),chosen.end());
	return chosen;
}

// Unbounded Knapsack: duyet xuoi tu w[i] len W
long long knapsack_unbounded(){
	for(int j=0;j<=W;j++) dp1[j]=0;
	for(int i=1;i<=n;i++)
		for(int j=w[i];j<=W;j++)
			dp1[j]=max(dp1[j],dp1[j-w[i]]+v[i]);
	return dp1[W];
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n>>W){
		for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
		cout<<knapsack_01_1d()<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
