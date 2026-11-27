// Toi uu chuyen trang thai DP:
// (1) Dung Segment Tree O(N log N): Day con tang co tong trong so lon nhat (Weighted LIS)
// (2) Dung Monotonic Deque O(N): Nhay buoc do dai toi da k dat tong lon nhat
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

const int MAXN=200005;
int n,k;
long long a[MAXN],w[MAXN],t_max[4*MAXN],dp_seg[MAXN],dp_dq[MAXN];

void update_max(int id,int l,int r,int pos,long long val){
	if(l==r){
		t_max[id]=max(t_max[id],val);
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid) update_max(id*2,l,mid,pos,val);
	else update_max(id*2+1,mid+1,r,pos,val);
	t_max[id]=max(t_max[id*2],t_max[id*2+1]);
}

long long get_max(int id,int l,int r,int u,int v){
	if(u>v||v<l||u>r) return 0;
	if(u<=l&&r<=v) return t_max[id];
	int mid=(l+r)/2;
	return max(get_max(id*2,l,mid,u,v),get_max(id*2+1,mid+1,r,u,v));
}

long long weighted_lis(){
	vector<long long> vals;
	for(int i=1;i<=n;i++) vals.push_back(a[i]);
	sort(vals.begin(),vals.end());
	vals.erase(unique(vals.begin(),vals.end()),vals.end());
	int sz=vals.size();
	for(int i=1;i<=4*sz;i++) t_max[i]=0;
	long long res=0;
	for(int i=1;i<=n;i++){
		int id=lower_bound(vals.begin(),vals.end(),a[i])-vals.begin()+1;
		dp_seg[i]=w[i]+get_max(1,1,sz,1,id-1);
		update_max(1,1,sz,id,dp_seg[i]);
		res=max(res,dp_seg[i]);
	}
	return res;
}

long long max_jump_k(){
	deque<int> dq;
	dp_dq[1]=a[1];
	dq.push_back(1);
	for(int i=2;i<=n;i++){
		while(!dq.empty()&&dq.front()<i-k) dq.pop_front();
		dp_dq[i]=a[i]+dp_dq[dq.front()];
		while(!dq.empty()&&dp_dq[dq.back()]<=dp_dq[i]) dq.pop_back();
		dq.push_back(i);
	}
	return dp_dq[n];
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n>>k){
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<max_jump_k()<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
