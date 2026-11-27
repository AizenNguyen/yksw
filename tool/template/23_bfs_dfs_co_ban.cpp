// BFS / DFS co ban (danh sach ke & luoi 4 huong): TPLT, kiem tra 2 phia, phat hien chu trinh
// Do phuc tap: O(V + E)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<queue>
using namespace std;

const int MAXN=200005;
int n,m;
vector<int> adj[MAXN];
int vis[MAXN],color[MAXN];

void dfs(int u){
	vis[u]=1;
	for(int v:adj[u]){
		if(!vis[v]) dfs(v);
	}
}

void bfs(int s){
	queue<int> q;
	vis[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:adj[u]){
			if(!vis[v]){
				vis[v]=1;
				q.push(v);
			}
		}
	}
}

bool check_bipartite(int s){
	queue<int> q;
	color[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:adj[u]){
			if(color[v]==-1){
				color[v]=color[u]^1;
				q.push(v);
			}
			else if(color[v]==color[u]) return false;
		}
	}
	return true;
}

// Phat hien chu trinh do thi vo huong (vis: 0=chua tham, 1=da tham)
bool has_cycle_undirected(int u,int p){
	vis[u]=1;
	for(int v:adj[u]){
		if(v==p) continue;
		if(vis[v]) return true;
		if(has_cycle_undirected(v,u)) return true;
	}
	return false;
}

// Phat hien chu trinh do thi co huong (vis: 0=chua, 1=dang trong stack, 2=xong)
bool has_cycle_directed(int u){
	vis[u]=1;
	for(int v:adj[u]){
		if(vis[v]==1) return true;
		if(vis[v]==0&&has_cycle_directed(v)) return true;
	}
	vis[u]=2;
	return false;
}

// BFS tren luoi 4 huong (1..R, 1..C)
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
int R,C;
int d_grid[1005][1005];
char grid[1005][1005];

void bfs_grid(int sx,int sy){
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++) d_grid[i][j]=-1;
	queue<pair<int,int>> q;
	d_grid[sx][sy]=0;
	q.push({sx,sy});
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx=x+dx[k],ny=y+dy[k];
			if(nx<1||nx>R||ny<1||ny>C) continue;
			if(grid[nx][ny]=='#'||d_grid[nx][ny]!=-1) continue;
			d_grid[nx][ny]=d_grid[x][y]+1;
			q.push({nx,ny});
		}
	}
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
			adj[v].push_back(u);
		}
		int tplt=0;
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				tplt++;
				bfs(i);
			}
		cout<<tplt<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
