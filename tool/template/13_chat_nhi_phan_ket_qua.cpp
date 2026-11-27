// Chat nhi phan tren mang & Chat nhi phan ket qua (Binary Search on Answer)
// Do phuc tap: O(log N * chi phi check)
#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

const int MAXN=200005;
int n;
long long k,a[MAXN];

// Tim chi so dau tien i trong [1..n] ma a[i]>=x (tra ve n+1 neu khong co)
int tim_dau_ge(long long x){
	int l=1,r=n,pos=n+1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(a[mid]>=x){
			pos=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return pos;
}

// Vi du check(mid): voi thoi gian mid, tong san pham >= k hay khong
bool check(long long mid){
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=mid/a[i];
		if(cnt>=k) return true;
	}
	return false;
}

// Tim gia tri nho nhat thoa man check(mid)==true (dang FFFFTTTT)
long long bs_min(long long l,long long r){
	long long res=-1;
	while(l<=r){
		long long mid=l+(r-l)/2;
		if(check(mid)){
			res=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return res;
}

// Tim gia tri lon nhat thoa man check(mid)==true (dang TTTTFFFF)
long long bs_max(long long l,long long r){
	long long res=-1;
	while(l<=r){
		long long mid=l+(r-l)/2;
		if(check(mid)){
			res=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return res;
}

// Chat nhi phan so thuc (80 buoc cho do chinh xac ~ 1e-12)
double bs_real(double l,double r){
	for(int it=1;it<=80;it++){
		double mid=(l+r)/2.0;
		if(mid*mid>=k) r=mid;
		else l=mid;
	}
	return r;
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n>>k){
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<bs_min(1,1e18)<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
