// Floyd-Warshall (duong di ngan nhat moi cap dinh) + truy vet: O(N^3), N <= 400
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=405;
const long long INF=2e18;
int n,m;
long long d[MAXN][MAXN];
int nxt[MAXN][MAXN];

void floyd_init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			d[i][j]=(i==j?0:INF);
			nxt[i][j]=(i==j?i:-1);
		}
}

void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			if(d[i][k]==INF) continue;
			for(int j=1;j<=n;j++){
				if(d[k][j]==INF) continue;
				if(d[i][k]+d[k][j]<d[i][j]){
					d[i][j]=d[i][k]+d[k][j];
					nxt[i][j]=nxt[i][k];
				}
			}
		}
}

vector<int> trace_path(int u,int v){
	if(nxt[u][v]==-1) return {};
	vector<int> path;
	path.push_back(u);
	while(u!=v){
		u=nxt[u][v];
		path.push_back(u);
	}
	return path;
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	int q;
	if(cin>>n>>m>>q){
		floyd_init();
		for(int i=1;i<=m;i++){
			int u,v;
			long long w;
			cin>>u>>v>>w;
			if(w<d[u][v]){
				d[u][v]=w;
				nxt[u][v]=v;
			}
			if(w<d[v][u]){
				d[v][u]=w;
				nxt[v][u]=u;
			}
		}
		floyd();
		while(q--){
			int u,v;
			cin>>u>>v;
			cout<<(d[u][v]>=INF/2?-1:d[u][v])<<'\n';
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
