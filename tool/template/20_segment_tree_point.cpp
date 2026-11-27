// Segment Tree co ban (Point Update - Range Sum & Min/Max Query): Build O(N), Query/Update O(log N)
// 1-indexed, bo cuc bam sat style PointUpdate-SumQuery
#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;

const int MAXN=200005;
const long long INF=2e18;
int n,q;
long long an[MAXN],t_sum[4*MAXN],t_min[4*MAXN];

void build(int id,int l,int r){
	if(l==r){
		t_sum[id]=an[l];
		t_min[id]=an[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t_sum[id]=t_sum[id*2]+t_sum[id*2+1];
	t_min[id]=min(t_min[id*2],t_min[id*2+1]);
}

void update(int id,int l,int r,int pos,long long x){
	if(l==r){
		t_sum[id]=x;
		t_min[id]=x;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid) update(id*2,l,mid,pos,x);
	else update(id*2+1,mid+1,r,pos,x);
	t_sum[id]=t_sum[id*2]+t_sum[id*2+1];
	t_min[id]=min(t_min[id*2],t_min[id*2+1]);
}

long long get_sum(int id,int l,int r,int u,int v){
	if(v<l||u>r) return 0;
	if(u<=l&&r<=v) return t_sum[id];
	int mid=(l+r)/2;
	return get_sum(id*2,l,mid,u,v)+get_sum(id*2+1,mid+1,r,u,v);
}

long long get_min(int id,int l,int r,int u,int v){
	if(v<l||u>r) return INF;
	if(u<=l&&r<=v) return t_min[id];
	int mid=(l+r)/2;
	return min(get_min(id*2,l,mid,u,v),get_min(id*2+1,mid+1,r,u,v));
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n>>q){
		for(int i=1;i<=n;i++) cin>>an[i];
		build(1,1,n);
		while(q--){
			short type;
			cin>>type;
			if(type==1){
				int pos;
				long long x;
				cin>>pos>>x;
				update(1,1,n,pos,x);
			}
			else{
				int l,r;
				cin>>l>>r;
				cout<<get_sum(1,1,n,l,r)<<" "<<get_min(1,1,n,l,r)<<'\n';
			}
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
