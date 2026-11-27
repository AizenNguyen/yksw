// Meet-in-the-middle (Chia doi tap hop, N <= 40): O(2^(N/2) * log(2^(N/2)))
// Dem so tap con co tong bang S (hoac <= S)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=45;
int n;
long long s,a[MAXN];

void gen_sums(int l,int r,vector<long long>& res){
	int len=r-l+1;
	res.clear();
	for(int mask=0;mask<(1<<len);mask++){
		long long sum=0;
		for(int i=0;i<len;i++)
			if((mask>>i)&1) sum+=a[l+i];
		res.push_back(sum);
	}
}

long long count_subset_equal(){
	int mid=n/2;
	vector<long long> left_sums,right_sums;
	gen_sums(1,mid,left_sums);
	gen_sums(mid+1,n,right_sums);
	sort(right_sums.begin(),right_sums.end());
	long long res=0;
	for(long long x:left_sums){
		long long need=s-x;
		auto l_it=lower_bound(right_sums.begin(),right_sums.end(),need);
		auto r_it=upper_bound(right_sums.begin(),right_sums.end(),need);
		res+=(r_it-l_it);
	}
	return res;
}

long long count_subset_le(){
	int mid=n/2;
	vector<long long> left_sums,right_sums;
	gen_sums(1,mid,left_sums);
	gen_sums(mid+1,n,right_sums);
	sort(right_sums.begin(),right_sums.end());
	long long res=0;
	for(long long x:left_sums){
		long long limit=s-x;
		res+=upper_bound(right_sums.begin(),right_sums.end(),limit)-right_sums.begin();
	}
	return res;
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n>>s){
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<count_subset_equal()<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
