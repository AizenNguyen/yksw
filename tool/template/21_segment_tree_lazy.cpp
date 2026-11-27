// Segment Tree Lazy Propagation: Cap nhat doan (cong val / gan x) & Truy van Sum / Max trong O(log N)
// Luu y: uu tien day lazy gan (has_set) truoc lazy cong (lz_add) trong push()
#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;

const int MAXN=200005;
const long long NEG_INF=-2e18;
int n,q;
long long a[MAXN],t_sum[4*MAXN],t_max[4*MAXN],lz_add[4*MAXN],lz_set[4*MAXN];
bool has_set[4*MAXN];

void apply_set(int id,int l,int r,long long x){
	t_sum[id]=x*(r-l+1);
	t_max[id]=x;
	lz_set[id]=x;
	lz_add[id]=0;
	has_set[id]=true;
}

void apply_add(int id,int l,int r,long long val){
	t_sum[id]+=val*(r-l+1);
	t_max[id]+=val;
	if(has_set[id]) lz_set[id]+=val;
	else lz_add[id]+=val;
}

void push(int id,int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	if(has_set[id]){
		apply_set(id*2,l,mid,lz_set[id]);
		apply_set(id*2+1,mid+1,r,lz_set[id]);
		has_set[id]=false;
	}
	if(lz_add[id]!=0){
		apply_add(id*2,l,mid,lz_add[id]);
		apply_add(id*2+1,mid+1,r,lz_add[id]);
		lz_add[id]=0;
	}
}

void build(int id,int l,int r){
	has_set[id]=false;
	lz_add[id]=0;
	if(l==r){
		t_sum[id]=t_max[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t_sum[id]=t_sum[id*2]+t_sum[id*2+1];
	t_max[id]=max(t_max[id*2],t_max[id*2+1]);
}

void update_add(int id,int l,int r,int u,int v,long long val){
	if(v<l||u>r) return;
	if(u<=l&&r<=v){
		apply_add(id,l,r,val);
		return;
	}
	push(id,l,r);
	int mid=(l+r)/2;
	update_add(id*2,l,mid,u,v,val);
	update_add(id*2+1,mid+1,r,u,v,val);
	t_sum[id]=t_sum[id*2]+t_sum[id*2+1];
	t_max[id]=max(t_max[id*2],t_max[id*2+1]);
}

void update_set(int id,int l,int r,int u,int v,long long x){
	if(v<l||u>r) return;
	if(u<=l&&r<=v){
		apply_set(id,l,r,x);
		return;
	}
	push(id,l,r);
	int mid=(l+r)/2;
	update_set(id*2,l,mid,u,v,x);
	update_set(id*2+1,mid+1,r,u,v,x);
	t_sum[id]=t_sum[id*2]+t_sum[id*2+1];
	t_max[id]=max(t_max[id*2],t_max[id*2+1]);
}

long long get_sum(int id,int l,int r,int u,int v){
	if(v<l||u>r) return 0;
	if(u<=l&&r<=v) return t_sum[id];
	push(id,l,r);
	int mid=(l+r)/2;
	return get_sum(id*2,l,mid,u,v)+get_sum(id*2+1,mid+1,r,u,v);
}

long long get_max(int id,int l,int r,int u,int v){
	if(v<l||u>r) return NEG_INF;
	if(u<=l&&r<=v) return t_max[id];
	push(id,l,r);
	int mid=(l+r)/2;
	return max(get_max(id*2,l,mid,u,v),get_max(id*2+1,mid+1,r,u,v));
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n>>q){
		for(int i=1;i<=n;i++) cin>>a[i];
		build(1,1,n);
		while(q--){
			short type;
			int l,r;
			cin>>type>>l>>r;
			if(type==1){
				long long val;
				cin>>val;
				update_add(1,1,n,l,r,val);
			}
			else if(type==2){
				long long x;
				cin>>x;
				update_set(1,1,n,l,r,x);
			}
			else cout<<get_sum(1,1,n,l,r)<<" "<<get_max(1,1,n,l,r)<<'\n';
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
