// Tong tien to (Prefix Sum) 1D & 2D, 1-indexed
// Tien xu ly: O(N) / O(N*M), Truy van doan / hinh chu nhat: O(1)
#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

const int MAXN=200005;
const int MAXM=1005;
int n,m;
long long a[MAXN],pf[MAXN];
long long g[MAXM][MAXM],pf2[MAXM][MAXM];

void build_1d(){
	for(int i=1;i<=n;i++) pf[i]=pf[i-1]+a[i];
}

long long sum_1d(int l,int r){
	if(l>r) return 0;
	return pf[r]-pf[l-1];
}

void build_2d(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			pf2[i][j]=pf2[i-1][j]+pf2[i][j-1]-pf2[i-1][j-1]+g[i][j];
}

long long sum_2d(int x1,int y1,int x2,int y2){
	if(x1>x2||y1>y2) return 0;
	return pf2[x2][y2]-pf2[x1-1][y2]-pf2[x2][y1-1]+pf2[x1-1][y1-1];
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	int q,l,r;
	if(cin>>n>>q){
		for(int i=1;i<=n;i++) cin>>a[i];
		build_1d();
		while(q--){
			cin>>l>>r;
			cout<<sum_1d(l,r)<<'\n';
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
