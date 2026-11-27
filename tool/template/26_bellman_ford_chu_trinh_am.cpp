// Bellman-Ford (canh am) & Phat hien + truy vet chu trinh am: O(V * E), 1-indexed
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
	int u,v;
	long long w;
};

const int MAXN=2505;
const long long INF=2e18;
int n,m;
vector<Edge> edges;
long long dist_arr[MAXN];
int par[MAXN];

// Tim chu trinh am bat ky (khong phu thuoc dinh nguon khi khoi tao dist=0)
vector<int> find_negative_cycle(){
	for(int i=1;i<=n;i++){
		dist_arr[i]=0;
		par[i]=-1;
	}
	int last=-1;
	for(int step=1;step<=n;step++){
		last=-1;
		for(const auto& e:edges){
			if(dist_arr[e.u]+e.w<dist_arr[e.v]){
				dist_arr[e.v]=dist_arr[e.u]+e.w;
				par[e.v]=e.u;
				last=e.v;
			}
		}
	}
	if(last==-1) return {};
	for(int i=1;i<=n;i++) last=par[last];
	vector<int> cycle;
	for(int v=last;;v=par[v]){
		cycle.push_back(v);
		if(v==last&&cycle.size()>1) break;
	}
	reverse(cycle.begin(),cycle.end());
	return cycle;
}

// Bellman-Ford tu dinh nguon s (tra ve false neu co chu trinh am den duoc tu s)
bool bellman_ford(int s){
	for(int i=1;i<=n;i++){
		dist_arr[i]=INF;
		par[i]=-1;
	}
	dist_arr[s]=0;
	for(int step=1;step<n;step++){
		bool changed=false;
		for(const auto& e:edges){
			if(dist_arr[e.u]!=INF&&dist_arr[e.u]+e.w<dist_arr[e.v]){
				dist_arr[e.v]=dist_arr[e.u]+e.w;
				par[e.v]=e.u;
				changed=true;
			}
		}
		if(!changed) break;
	}
	for(const auto& e:edges)
		if(dist_arr[e.u]!=INF&&dist_arr[e.u]+e.w<dist_arr[e.v]) return false;
	return true;
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n>>m){
		edges.resize(m);
		for(int i=0;i<m;i++) cin>>edges[i].u>>edges[i].v>>edges[i].w;
		vector<int> cyc=find_negative_cycle();
		if(cyc.empty()) cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(int u:cyc) cout<<u<<" ";
			cout<<'\n';
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
