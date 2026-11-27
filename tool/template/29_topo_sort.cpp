// Sap xep Topo: Kahn (dung queue / priority_queue lay thu tu tu dien nho nhat) & DFS + DP tren DAG
// Do phuc tap: O(V + E) (hoac O((V + E) log V) neu dung min-heap)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int MAXN=200005;
int n,m,indeg[MAXN],vis[MAXN];
vector<int> adj[MAXN],topo;

bool kahn_topo(bool min_lex=false){
	topo.clear();
	if(!min_lex){
		queue<int> q;
		for(int i=1;i<=n;i++) if(indeg[i]==0) q.push(i);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			topo.push_back(u);
			for(int v:adj[u]){
				indeg[v]--;
				if(indeg[v]==0) q.push(v);
			}
		}
	}
	else{
		priority_queue<int,vector<int>,greater<int>> pq;
		for(int i=1;i<=n;i++) if(indeg[i]==0) pq.push(i);
		while(!pq.empty()){
			int u=pq.top();
			pq.pop();
			topo.push_back(u);
			for(int v:adj[u]){
				indeg[v]--;
				if(indeg[v]==0) pq.push(v);
			}
		}
	}
	return (int)topo.size()==n;
}

bool dfs_topo(int u){
	vis[u]=1;
	for(int v:adj[u]){
		if(vis[v]==1) return false;
		if(vis[v]==0&&!dfs_topo(v)) return false;
	}
	vis[u]=2;
	topo.push_back(u);
	return true;
}

// DP duong di dai nhat tren DAG theo thu tu topo
int dp_dag[MAXN];
int longest_path_dag(){
	int res=0;
	for(int u:topo){
		for(int v:adj[u]) dp_dag[v]=max(dp_dag[v],dp_dag[u]+1);
		res=max(res,dp_dag[u]);
	}
	return res;
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n>>m){
		for(int i=1;i<=m;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			indeg[v]++;
		}
		if(!kahn_topo(false)) cout<<"IMPOSSIBLE\n";
		else{
			for(int u:topo) cout<<u<<" ";
			cout<<'\n';
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
