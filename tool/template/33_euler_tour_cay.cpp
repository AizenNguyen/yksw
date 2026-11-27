// Euler Tour trai phang cay ket hop Fenwick Tree (BIT): O(log N) moi truy van
// Quy uoc: cay con goc u nam tron trong doan [tin[u], tout[u]]
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
using namespace std;

const int MAXN=200005;
int n,q,timer;
vector<int> adj[MAXN];
int tin[MAXN],tout[MAXN];
long long val[MAXN],bit[MAXN];

void dfs_euler(int u,int p){
	tin[u]=++timer;
	for(int v:adj[u])
		if(v!=p) dfs_euler(v,u);
	tout[u]=timer;
}

void bit_add(int pos,long long delta){
	for(;pos<=n;pos+=pos&-pos) bit[pos]+=delta;
}

long long bit_get(int pos){
	long long res=0;
	for(;pos>0;pos-=pos&-pos) res+=bit[pos];
	return res;
}

void update_node(int u,long long new_val){
	long long delta=new_val-val[u];
	val[u]=new_val;
	bit_add(tin[u],delta);
}

long long query_subtree(int u){
	return bit_get(tout[u])-bit_get(tin[u]-1);
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n>>q){
		for(int i=1;i<=n;i++) cin>>val[i];
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs_euler(1,0);
		for(int i=1;i<=n;i++) bit_add(tin[i],val[i]);
		while(q--){
			short type;
			cin>>type;
			if(type==1){
				int u;
				long long x;
				cin>>u>>x;
				update_node(u,x);
			}
			else{
				int u;
				cin>>u;
				cout<<query_subtree(u)<<'\n';
			}
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
