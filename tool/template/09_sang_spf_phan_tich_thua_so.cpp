// Sang uoc nguyen to nho nhat (SPF: O(N log log N) build, O(log N) phan tich)
// Kem phan tich thua so nguyen to O(sqrt(N)) cho N lon (<= 1e14)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<utility>
using namespace std;

const int MAXN=1000005;
int spf[MAXN];

void build_spf(int limit=MAXN-1){
	for(int i=1;i<=limit;i++) spf[i]=i;
	for(int i=2;1LL*i*i<=limit;i++)
		if(spf[i]==i)
			for(int j=i*i;j<=limit;j+=i)
				if(spf[j]==j) spf[j]=i;
}

vector<pair<int,int>> factor_spf(int x){
	vector<pair<int,int>> res;
	while(x>1){
		int p=spf[x],cnt=0;
		while(x%p==0){
			x/=p;
			cnt++;
		}
		res.push_back({p,cnt});
	}
	return res;
}

vector<pair<long long,int>> factor_sqrt(long long n){
	vector<pair<long long,int>> res;
	for(long long i=2;i<=n/i;i++){
		if(n%i==0){
			int cnt=0;
			while(n%i==0){
				n/=i;
				cnt++;
			}
			res.push_back({i,cnt});
		}
	}
	if(n>1) res.push_back({n,1});
	return res;
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	build_spf(1000000);
	long long n;
	if(cin>>n){
		auto f=factor_sqrt(n);
		for(auto it:f) cout<<it.first<<"^"<<it.second<<" ";
		cout<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
