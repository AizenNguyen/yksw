// Cay khung nho nhat Kruskal (DSU + sort canh): O(E log E), 1-indexed
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

struct Edge{
	int u,v;
	long long w;
	bool operator<(const Edge& o) const{
		return w<o.w;
	}
};

const int MAXN=200005;
int n,m;
int par[MAXN],sz[MAXN];
vector<Edge> edges,mst;

void dsu_init(){
	for(int i=1;i<=n;i++){
		par[i]=i;
		sz[i]=1;
	}
}

int find_set(int u){
	if(par[u]==u) return u;
	return par[u]=find_set(par[u]);
}

bool unite(int u,int v){
	u=find_set(u);
	v=find_set(v);
	if(u==v) return false;
	if(sz[u]<sz[v]) swap(u,v);
	par[v]=u;
	sz[u]+=sz[v];
	return true;
}

long long kruskal(){
	sort(edges.begin(),edges.end());
	dsu_init();
	mst.clear();
	long long total=0;
	for(const auto& e:edges){
		if(unite(e.u,e.v)){
			total+=e.w;
			mst.push_back(e);
			if((int)mst.size()==n-1) break;
		}
	}
	if((int)mst.size()!=n-1) return -1;
	return total;
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
		long long res=kruskal();
		if(res==-1) cout<<"IMPOSSIBLE\n";
		else cout<<res<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
