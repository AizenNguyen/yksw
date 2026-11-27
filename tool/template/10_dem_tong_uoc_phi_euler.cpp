// Dem uoc, Tong uoc (O(sqrt(N)) va sang O(N log N)) + Phi ham Euler (O(sqrt(N)) va sang O(N log log N))
#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

const int MAXN=1000005;
int cnt_div_arr[MAXN],phi_arr[MAXN];
long long sum_div_arr[MAXN];

long long count_div(long long n){
	long long res=1;
	for(long long i=2;i<=n/i;i++){
		if(n%i==0){
			int cnt=0;
			while(n%i==0){
				n/=i;
				cnt++;
			}
			res*=(cnt+1);
		}
	}
	if(n>1) res*=2;
	return res;
}

long long sum_div(long long n){
	long long res=1;
	for(long long i=2;i<=n/i;i++){
		if(n%i==0){
			long long p_sum=1,cur=1;
			while(n%i==0){
				n/=i;
				cur*=i;
				p_sum+=cur;
			}
			res*=p_sum;
		}
	}
	if(n>1) res*=(1+n);
	return res;
}

void build_divisors(int limit=MAXN-1){
	for(int i=1;i<=limit;i++)
		for(int j=i;j<=limit;j+=i){
			cnt_div_arr[j]++;
			sum_div_arr[j]+=i;
		}
}

long long phi_single(long long n){
	long long res=n;
	for(long long i=2;i<=n/i;i++){
		if(n%i==0){
			while(n%i==0) n/=i;
			res-=res/i;
		}
	}
	if(n>1) res-=res/n;
	return res;
}

void build_phi(int limit=MAXN-1){
	for(int i=1;i<=limit;i++) phi_arr[i]=i;
	for(int i=2;i<=limit;i++)
		if(phi_arr[i]==i)
			for(int j=i;j<=limit;j+=i)
				phi_arr[j]-=phi_arr[j]/i;
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long n;
	if(cin>>n){
		cout<<"uoc="<<count_div(n)<<" tong="<<sum_div(n)<<" phi="<<phi_single(n)<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
