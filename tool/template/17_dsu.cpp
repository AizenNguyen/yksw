// Disjoint Set Union (DSU) - Path Compression + Union by Size: O(alpha(N)) moi thao tac
#include<iostream>
#include<cstdio>
#include<ctime>
#include<utility>
using namespace std;

const int MAXN=200005;
int n,m,comp_cnt;
int par[MAXN],sz[MAXN];

void dsu_init(int n_nodes){
	comp_cnt=n_nodes;
	for(int i=1;i<=n_nodes;i++){
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
	comp_cnt--;
	return true;
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n>>m){
		dsu_init(n);
		while(m--){
			short type;
			int u,v;
			cin>>type>>u>>v;
			if(type==1) unite(u,v);
			else cout<<(find_set(u)==find_set(v)?"YES":"NO")<<'\n';
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
