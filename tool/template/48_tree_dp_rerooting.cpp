// Tree DP Rerooting (Ky thuat doi goc cay): O(N), 1-indexed
// Bai mau: Voi moi dinh u, tinh tong khoang cach tu u den tat ca dinh con lai
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
using namespace std;

const int MAXN=200005;
int n,sz[MAXN];
vector<int> adj[MAXN];
long long sub[MAXN],ans[MAXN];

void dfs1(int u,int p){
	sz[u]=1;
	sub[u]=0;
	for(int v:adj[u]){
		if(v==p) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		sub[u]+=sub[v]+sz[v];
	}
}

void dfs2(int u,int p){
	for(int v:adj[u]){
		if(v==p) continue;
		ans[v]=ans[u]-sz[v]+(n-sz[v]);
		dfs2(v,u);
	}
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n){
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs1(1,0);
		ans[1]=sub[1];
		dfs2(1,0);
		for(int i=1;i<=n;i++) cout<<ans[i]<<(i==n?'\n':' ');
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
