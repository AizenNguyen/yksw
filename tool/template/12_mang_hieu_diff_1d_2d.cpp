// Mang hieu (Difference Array) 1D & 2D, 1-indexed
// Cap nhat doan / hinh chu nhat: O(1), Khoi phuc mang goc: O(N) / O(N*M)
#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

const int MAXN=200005;
const int MAXM=1005;
int n,m;
long long d1[MAXN],a[MAXN];
long long d2[MAXM][MAXM],g[MAXM][MAXM];

void add_1d(int l,int r,long long val){
	d1[l]+=val;
	d1[r+1]-=val;
}

void build_1d(){
	for(int i=1;i<=n;i++){
		d1[i]+=d1[i-1];
		a[i]+=d1[i];
	}
}

void add_2d(int x1,int y1,int x2,int y2,long long val){
	d2[x1][y1]+=val;
	d2[x2+1][y1]-=val;
	d2[x1][y2+1]-=val;
	d2[x2+1][y2+1]+=val;
}

void build_2d(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			d2[i][j]+=d2[i-1][j]+d2[i][j-1]-d2[i-1][j-1];
			g[i][j]+=d2[i][j];
		}
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	int q,l,r;
	long long v;
	if(cin>>n>>q){
		for(int i=1;i<=n;i++) cin>>a[i];
		while(q--){
			cin>>l>>r>>v;
			add_1d(l,r,v);
		}
		build_1d();
		for(int i=1;i<=n;i++) cout<<a[i]<<(i==n?'\n':' ');
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
