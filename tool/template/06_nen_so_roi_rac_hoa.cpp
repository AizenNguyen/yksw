// Nen so / Roi rac hoa (Coordinate Compression): O(N log N), 1-indexed
// Gia tri sau nen nam trong [1..sz], dung vals[id] de lay lai gia tri goc
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=200005;
int n,sz;
long long a[MAXN];
int b[MAXN];
vector<long long> vals;

void compress(){
	vals.clear();
	for(int i=1;i<=n;i++) vals.push_back(a[i]);
	sort(vals.begin(),vals.end());
	vals.erase(unique(vals.begin(),vals.end()),vals.end());
	sz=vals.size();
	for(int i=1;i<=n;i++){
		b[i]=lower_bound(vals.begin(),vals.end(),a[i])-vals.begin()+1;
	}
}

int get_id(long long x){
	return lower_bound(vals.begin(),vals.end(),x)-vals.begin()+1;
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n){
		for(int i=1;i<=n;i++) cin>>a[i];
		compress();
		for(int i=1;i<=n;i++) cout<<b[i]<<(i==n?'\n':' ');
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
