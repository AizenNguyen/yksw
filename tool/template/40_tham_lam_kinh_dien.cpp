// Tham lam kinh dien: (1) Lap lich chon doan khong giao nhau; (2) Noi day chi phi nho nhat (Huffman)
// Do phuc tap: O(N log N)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Seg{
	long long l,r;
	bool operator<(const Seg& o) const{
		if(r!=o.r) return r<o.r;
		return l<o.l;
	}
};

int max_non_overlapping(vector<Seg>& a){
	sort(a.begin(),a.end());
	int cnt=0;
	long long last_r=-2e18;
	for(const auto& s:a){
		if(s.l>=last_r){
			cnt++;
			last_r=s.r;
		}
	}
	return cnt;
}

long long huffman_min_cost(const vector<long long>& a){
	priority_queue<long long,vector<long long>,greater<long long>> pq;
	for(long long x:a) pq.push(x);
	long long res=0;
	while((int)pq.size()>1){
		long long u=pq.top();pq.pop();
		long long v=pq.top();pq.pop();
		res+=u+v;
		pq.push(u+v);
	}
	return res;
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	if(cin>>n){
		vector<Seg> segs(n);
		for(int i=0;i<n;i++) cin>>segs[i].l>>segs[i].r;
		cout<<max_non_overlapping(segs)<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
