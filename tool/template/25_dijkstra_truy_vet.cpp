// Dijkstra + Truy vet duong di ngan nhat (trong so khong am): O((V + E) log V), 1-indexed
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

const int MAXN=200005;
const long long INF=2e18;
int n,m;
vector<pair<int,long long>> adj[MAXN];
long long dist_arr[MAXN];
int par[MAXN];

void dijkstra(int s){
	for(int i=1;i<=n;i++){
		dist_arr[i]=INF;
		par[i]=-1;
	}
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	dist_arr[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		long long d=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(d>dist_arr[u]) continue;
		for(auto e:adj[u]){
			int v=e.first;
			long long w=e.second;
			if(dist_arr[u]+w<dist_arr[v]){
				dist_arr[v]=dist_arr[u]+w;
				par[v]=u;
				pq.push({dist_arr[v],v});
			}
		}
	}
}

vector<int> restore_path(int s,int t){
	vector<int> path;
	if(dist_arr[t]==INF) return path;
	for(int v=t;v!=-1;v=par[v]) path.push_back(v);
	reverse(path.begin(),path.end());
	if(path.empty()||path[0]!=s) return {};
	return path;
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	int s,t;
	if(cin>>n>>m>>s>>t){
		for(int i=1;i<=m;i++){
			int u,v;
			long long w;
			cin>>u>>v>>w;
			adj[u].push_back({v,w});
		}
		dijkstra(s);
		if(dist_arr[t]==INF) cout<<-1<<'\n';
		else{
			cout<<dist_arr[t]<<'\n';
			vector<int> path=restore_path(s,t);
			for(int u:path) cout<<u<<" ";
			cout<<'\n';
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
