// Fenwick Tree (BIT) 1-indexed: O(log N) moi thao tac
// Gom: (1) Cap nhat diem - truy van doan, (2) Cap nhat doan - truy van doan (2 BIT)
#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

const int MAXN=200005;
int n;
long long bit1[MAXN],bit2[MAXN];

void add_point(long long bit[],int pos,long long val){
	for(;pos<=n;pos+=pos&-pos) bit[pos]+=val;
}

long long get_prefix(long long bit[],int pos){
	long long res=0;
	for(;pos>0;pos-=pos&-pos) res+=bit[pos];
	return res;
}

// Cap nhat diem + truy van tong [l,r] chi dung bit1
long long query_point_range(int l,int r){
	return get_prefix(bit1,r)-get_prefix(bit1,l-1);
}

// Cap nhat cong val vao doan [l,r] (dung 2 BIT)
void range_add(int l,int r,long long val){
	add_point(bit1,l,val);
	add_point(bit1,r+1,-val);
	add_point(bit2,l,val*(l-1));
	add_point(bit2,r+1,-val*r);
}

long long prefix_sum_range(int pos){
	return get_prefix(bit1,pos)*pos-get_prefix(bit2,pos);
}

long long range_sum(int l,int r){
	return prefix_sum_range(r)-prefix_sum_range(l-1);
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	int q;
	if(cin>>n>>q){
		for(int i=1;i<=n;i++){
			long long x;
			cin>>x;
			range_add(i,i,x);
		}
		while(q--){
			short type;
			int l,r;
			cin>>type>>l>>r;
			if(type==1){
				long long val;
				cin>>val;
				range_add(l,r,val);
			}
			else cout<<range_sum(l,r)<<'\n';
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
