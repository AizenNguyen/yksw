// To tien chung gan nhat LCA bang Binary Lifting: Build O(N log N), Query O(log N)
// Ho tro khoang cach 2 dinh tren cay co trong so & tim to tien thu k
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<utility>
using namespace std;

const int MAXN=200005;
const int LOG=18;
int n,q;
vector<pair<int,long long>> adj[MAXN];
int up[MAXN][LOG],h[MAXN];
long long dist_root[MAXN];

void dfs_lca(int u,int p){
	up[u][0]=p;
	for(int j=1;j<LOG;j++) up[u][j]=up[up[u][j-1]][j-1];
	for(auto e:adj[u]){
		int v=e.first;
		long long w=e.second;
		if(v==p) continue;
		h[v]=h[u]+1;
		dist_root[v]=dist_root[u]+w;
		dfs_lca(v,u);
	}
}

int kth_ancestor(int u,int k){
	for(int j=0;j<LOG;j++)
		if((k>>j)&1) u=up[u][j];
	return u;
}

int lca(int u,int v){
	if(h[u]<h[v]) swap(u,v);
	u=kth_ancestor(u,h[u]-h[v]);
	if(u==v) return u;
	for(int j=LOG-1;j>=0;j--)
		if(up[u][j]!=up[v][j]){
			u=up[u][j];
			v=up[v][j];
		}
	return up[u][0];
}

long long dist_uv(int u,int v){
	int w=lca(u,v);
	return dist_root[u]+dist_root[v]-2*dist_root[w];
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n>>q){
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back({v,1});
			adj[v].push_back({u,1});
		}
		dfs_lca(1,1);
		while(q--){
			int u,v;
			cin>>u>>v;
			cout<<lca(u,v)<<" "<<dist_uv(u,v)<<'\n';
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
