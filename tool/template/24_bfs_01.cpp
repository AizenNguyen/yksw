// 0-1 BFS bang Deque (do thi co trong so canh chi gom 0 va 1): O(V + E), 1-indexed
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<deque>
#include<utility>
using namespace std;

const int MAXN=200005;
const int INF=2e9;
int n,m;
vector<pair<int,int>> adj[MAXN];
int dist_arr[MAXN];

void bfs_01(int s){
	for(int i=1;i<=n;i++) dist_arr[i]=INF;
	deque<int> dq;
	dist_arr[s]=0;
	dq.push_front(s);
	while(!dq.empty()){
		int u=dq.front();
		dq.pop_front();
		for(auto e:adj[u]){
			int v=e.first,w=e.second;
			if(dist_arr[u]+w<dist_arr[v]){
				dist_arr[v]=dist_arr[u]+w;
				if(w==0) dq.push_front(v);
				else dq.push_back(v);
			}
		}
	}
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	int s;
	if(cin>>n>>m>>s){
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			adj[u].push_back({v,w});
			adj[v].push_back({u,w});
		}
		bfs_01(s);
		for(int i=1;i<=n;i++) cout<<(dist_arr[i]==INF?-1:dist_arr[i])<<(i==n?'\n':' ');
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
