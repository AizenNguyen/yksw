// Sparse Table (RMQ tinh): Build O(N log N), Query Min/Max/GCD O(1), 1-indexed
// Luu y: chi dung cho mang khong thay doi va phep toan luy dang (min, max, gcd, &, |)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;

const int MAXN=200005;
const int LOG=18;
int n,lg2[MAXN];
long long a[MAXN],st[MAXN][LOG];

void build_rmq(){
	lg2[1]=0;
	for(int i=2;i<=n;i++) lg2[i]=lg2[i/2]+1;
	for(int i=1;i<=n;i++) st[i][0]=a[i];
	for(int j=1;j<LOG;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}

long long query_min(int l,int r){
	int j=lg2[r-l+1];
	return min(st[l][j],st[r-(1<<j)+1][j]);
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
		build_rmq();
		while(q--){
			cin>>l>>r;
			cout<<query_min(l,r)<<'\n';
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
