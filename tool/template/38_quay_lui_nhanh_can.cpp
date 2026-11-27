// Quay lui (sinh hoan vi, to hop) & Nhanh can (TSP co danh gia can duoi)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;

const int MAXN=20;
const long long INF=2e18;
int n,k;
int x[MAXN];
bool used[MAXN];

void back_comb(int i,int start){
	if(i>k){
		for(int j=1;j<=k;j++) cout<<x[j]<<(j==k?'\n':' ');
		return;
	}
	for(int v=start;v<=n-k+i;v++){
		x[i]=v;
		back_comb(i+1,v+1);
	}
}

void back_perm(int i){
	if(i>n){
		for(int j=1;j<=n;j++) cout<<x[j]<<(j==n?'\n':' ');
		return;
	}
	for(int v=1;v<=n;v++){
		if(!used[v]){
			used[v]=true;
			x[i]=v;
			back_perm(i+1);
			used[v]=false;
		}
	}
}

// Nhanh can TSP: quay ve dinh 1
long long cost[MAXN][MAXN],cmin=INF,best_tsp=INF;
int path_tsp[MAXN];
bool vis_tsp[MAXN];

void branch_bound(int step,long long cur_cost){
	if(cur_cost+(n-step+1)*cmin>=best_tsp) return;
	if(step==n){
		if(cost[path_tsp[n]][1]<INF)
			best_tsp=min(best_tsp,cur_cost+cost[path_tsp[n]][1]);
		return;
	}
	int u=path_tsp[step];
	for(int v=2;v<=n;v++){
		if(!vis_tsp[v]&&cost[u][v]<INF){
			vis_tsp[v]=true;
			path_tsp[step+1]=v;
			branch_bound(step+1,cur_cost+cost[u][v]);
			vis_tsp[v]=false;
		}
	}
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n>>k){
		back_comb(1,1);
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
