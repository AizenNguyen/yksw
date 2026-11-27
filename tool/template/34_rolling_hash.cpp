// Rolling Hash 2 modulo chong hack: Build O(N), Lay hash doan [l,r] trong O(1), 1-indexed
#include<iostream>
#include<cstdio>
#include<ctime>
#include<string>
#include<utility>
using namespace std;

const int MAXN=200005;
const long long BASE=311;
const long long MOD1=1000000007;
const long long MOD2=1000000009;
long long pw1[MAXN],pw2[MAXN],h1[MAXN],h2[MAXN];

void build_hash(const string& s){
	int n=(int)s.size()-1;
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=n;i++){
		pw1[i]=pw1[i-1]*BASE%MOD1;
		pw2[i]=pw2[i-1]*BASE%MOD2;
		h1[i]=(h1[i-1]*BASE+s[i])%MOD1;
		h2[i]=(h2[i-1]*BASE+s[i])%MOD2;
	}
}

pair<long long,long long> get_hash(int l,int r){
	long long v1=(h1[r]-h1[l-1]*pw1[r-l+1]%MOD1+MOD1)%MOD1;
	long long v2=(h2[r]-h2[l-1]*pw2[r-l+1]%MOD2+MOD2)%MOD2;
	return {v1,v2};
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	int q;
	if(cin>>s>>q){
		s=" "+s;
		build_hash(s);
		while(q--){
			int l1,r1,l2,r2;
			cin>>l1>>r1>>l2>>r2;
			cout<<(get_hash(l1,r1)==get_hash(l2,r2)?"YES":"NO")<<'\n';
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
