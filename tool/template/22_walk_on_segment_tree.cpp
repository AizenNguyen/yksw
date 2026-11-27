// Walk on Segment Tree: O(log N)
// (1) Tim vi tri dau tien >= x trong [u,v]; (2) Tim phan tu thu k tren cay tan so
#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;

const int MAXN=200005;
int n;
long long a[MAXN],t_max[4*MAXN],t_cnt[4*MAXN];

void build_max(int id,int l,int r){
	if(l==r){
		t_max[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build_max(id*2,l,mid);
	build_max(id*2+1,mid+1,r);
	t_max[id]=max(t_max[id*2],t_max[id*2+1]);
}

void update_max(int id,int l,int r,int pos,long long x){
	if(l==r){
		t_max[id]=x;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid) update_max(id*2,l,mid,pos,x);
	else update_max(id*2+1,mid+1,r,pos,x);
	t_max[id]=max(t_max[id*2],t_max[id*2+1]);
}

// Tra ve chi so nho nhat trong [u,v] co a[pos]>=x (-1 neu khong co)
int find_first_ge(int id,int l,int r,int u,int v,long long x){
	if(v<l||u>r||t_max[id]<x) return -1;
	if(l==r) return l;
	int mid=(l+r)/2;
	int res=find_first_ge(id*2,l,mid,u,v,x);
	if(res!=-1) return res;
	return find_first_ge(id*2+1,mid+1,r,u,v,x);
}

// Cay tan so: them delta vao gia tri pos (1<=pos<=n)
void add_freq(int id,int l,int r,int pos,long long delta){
	if(l==r){
		t_cnt[id]+=delta;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid) add_freq(id*2,l,mid,pos,delta);
	else add_freq(id*2+1,mid+1,r,pos,delta);
	t_cnt[id]=t_cnt[id*2]+t_cnt[id*2+1];
}

// Tim gia tri nho thu k (1-indexed), tra ve -1 neu tong tan so < k
int kth_order(int id,int l,int r,long long k){
	if(t_cnt[id]<k) return -1;
	if(l==r) return l;
	int mid=(l+r)/2;
	if(t_cnt[id*2]>=k) return kth_order(id*2,l,mid,k);
	return kth_order(id*2+1,mid+1,r,k-t_cnt[id*2]);
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	int q;
	if(cin>>n>>q){
		for(int i=1;i<=n;i++) cin>>a[i];
		build_max(1,1,n);
		while(q--){
			int l,r;
			long long x;
			cin>>l>>r>>x;
			cout<<find_first_ge(1,1,n,l,r,x)<<'\n';
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
