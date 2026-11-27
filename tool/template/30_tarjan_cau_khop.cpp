// Tarjan tim Cau (Bridges) & Khop (Articulation Points) tren do thi vo huong: O(V + E)
// Dung edge_id de xu ly an toan ca da do thi (nhieu canh song song)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

const int MAXN=200005;
int n,m,timer;
vector<pair<int,int>> adj[MAXN];
int tin[MAXN],low[MAXN];
bool is_cut[MAXN];
vector<pair<int,int>> bridges;

void dfs(int u,int pe_id){
	tin[u]=low[u]=++timer;
	int child=0;
	for(auto e:adj[u]){
		int v=e.first,id=e.second;
		if(id==pe_id) continue;
		if(tin[v]) low[u]=min(low[u],tin[v]);
		else{
			child++;
			dfs(v,id);
			low[u]=min(low[u],low[v]);
			if(low[v]>tin[u]) bridges.push_back({u,v});
			if(pe_id!=-1&&low[v]>=tin[u]) is_cut[u]=true;
		}
	}
	if(pe_id==-1&&child>1) is_cut[u]=true;
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
			adj[u].push_back({v,i});
			adj[v].push_back({u,i});
		}
		for(int i=1;i<=n;i++) if(!tin[i]) dfs(i,-1);
		int cut_cnt=0;
		for(int i=1;i<=n;i++) if(is_cut[i]) cut_cnt++;
		cout<<cut_cnt<<" "<<bridges.size()<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
