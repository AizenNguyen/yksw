// Tarjan tim Thanh phan lien thong manh (SCC) & nen do thi DAG: O(V + E), 1-indexed
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN=200005;
int n,m,timer,scc_cnt;
vector<int> adj[MAXN],dag[MAXN];
int tin[MAXN],low[MAXN],scc_id[MAXN];
bool on_stack[MAXN];
stack<int> st;

void dfs(int u){
	tin[u]=low[u]=++timer;
	st.push(u);
	on_stack[u]=true;
	for(int v:adj[u]){
		if(!tin[v]){
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if(on_stack[v]) low[u]=min(low[u],tin[v]);
	}
	if(low[u]==tin[u]){
		scc_cnt++;
		while(true){
			int v=st.top();
			st.pop();
			on_stack[v]=false;
			scc_id[v]=scc_cnt;
			if(v==u) break;
		}
	}
}

void build_dag(){
	for(int u=1;u<=n;u++)
		for(int v:adj[u])
			if(scc_id[u]!=scc_id[v])
				dag[scc_id[u]].push_back(scc_id[v]);
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
		}
		for(int i=1;i<=n;i++) if(!tin[i]) dfs(i);
		cout<<scc_cnt<<'\n';
		for(int i=1;i<=n;i++) cout<<scc_id[i]<<(i==n?'\n':' ');
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
