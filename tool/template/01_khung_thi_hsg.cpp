// Khung bai thi chuan HSG Tinh C++14 (file I/O + brute doi chieu + timer)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

#ifdef LOCAL
#define debug(x) cerr<<#x<<"="<<(x)<<'\n'
#else
#define debug(x)
#endif

const int MAXN=200005;
const long long MOD=1000000007;
int n;
long long a[MAXN];

void brute(){
	long long res=0;
	for(int i=1;i<=n;i++) res+=a[i];
	cout<<res<<'\n';
}

void solve(){
	long long res=0;
	for(int i=1;i<=n;i++) res+=a[i];
	cout<<res<<'\n';
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	//brute();
	solve();
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
