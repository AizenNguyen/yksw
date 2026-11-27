// Tree DP co ban: (1) Tap doc lap lon nhat (chon dinh sao cho 2 dinh ke khong cung duoc chon); (2) Duong kinh cay
// Do phuc tap: O(N), 1-indexed
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=200005;
int n;
vector<int> adj[MAXN];
long long w[MAXN],dp[MAXN][2];
int down[MAXN],diam;

void dfs_indep(int u,int p){
	dp[u][0]=0;
	dp[u][1]=w[u];
	for(int v:adj[u]){
		if(v==p) continue;
		dfs_indep(v,u);
		dp[u][0]+=max(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][0];
	}
}

void dfs_diam(int u,int p){
	int mx1=0,mx2=0;
	for(int v:adj[u]){
		if(v==p) continue;
		dfs_diam(v,u);
		int len=down[v]+1;
		if(len>=mx1){
			mx2=mx1;
			mx1=len;
		}
		else if(len>mx2) mx2=len;
	}
	down[u]=mx1;
	diam=max(diam,mx1+mx2);
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n){
		for(int i=1;i<=n;i++) cin>>w[i];
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs_indep(1,0);
		dfs_diam(1,0);
		cout<<max(dp[1][0],dp[1][1])<<" "<<diam<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
