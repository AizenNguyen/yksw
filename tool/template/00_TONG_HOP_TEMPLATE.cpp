// TONG HOP TOAN BO TEMPLATE ON THI HSG TINH C++14
// Moi thuat toan duoc boc trong 1 namespace rieng de tranh xung dot ten bien/ham
// Bam Ctrl+F va nhap ten namespace (vd: SegTreeLazy, Dijkstra, DigitDP) de nhay nhanh

/*
==================== MUC LUC TRA CUU NHANH ====================
[01] KhungThiHSG          - Khung bai thi chuan HSG Tinh (brute + solve + fopen + timer)
[02] SinhTestStress       - Bo sinh test ngau nhien (mang, hoan vi, cay, do thi) & stress test
[03] LuyThuaMulMod        - Luy thua nhi phan fast_pow & Nhan An Do mul_mod
[04] GcdExtGcdInv         - GCD, LCM, Euclid mo rong ext_gcd & Nghich dao modulo
[05] ToHopNcrMod          - To hop nCr modulo (giai thua O(1) & tam giac Pascal)
[06] NenSoCompress        - Nen so / Roi rac hoa (Coordinate Compression)
[07] SoLonBigInt          - So lon BigInt (cong, tru, nhan, chia lay du voi long long)
[08] SangNguyenTo         - Sang Eratosthenes bitset & Kiem tra nguyen to O(sqrt(N))
[09] SangSPF              - Sang uoc nguyen to nho nhat SPF & Phan tich thua so
[10] UocVaPhiEuler        - Dem uoc, Tong uoc & Phi ham Euler
[11] PrefixSum            - Tong tien to (Prefix Sum) 1D & 2D
[12] MangHieuDiff         - Mang hieu (Difference Array) 1D & 2D
[13] ChatNhiPhan          - Chat nhi phan tren mang, tren ket qua & so thuc
[14] HaiConTro            - Hai con tro (Two Pointers) O(N)
[15] SlidingWindowDeque   - Cua so truot Min / Max bang Deque O(N)
[16] MonotonicStack       - Ngan xep don dieu & Hinh chu nhat lon nhat Histogram
[17] DSU                  - Disjoint Set Union (Path Compression + Union by Size)
[18] SparseTableRMQ       - Sparse Table RMQ truy van O(1)
[19] FenwickBIT           - Fenwick Tree (BIT) 1D diem & doan
[20] SegTreePoint         - Segment Tree co ban (Point Update - Range Sum/Min)
[21] SegTreeLazy          - Segment Tree Lazy Propagation (Add/Set + Sum/Max)
[22] WalkOnSegTree        - Walk on Segment Tree (first >= x, k-th order)
[23] BfsDfsCoBan          - BFS / DFS, TPLT, 2 phia, chu trinh & luoi 4 huong
[24] Bfs01                - 0-1 BFS bang Deque O(V + E)
[25] Dijkstra             - Dijkstra + Truy vet duong di ngan nhat
[26] BellmanFord          - Bellman-Ford & Phat hien + truy vet chu trinh am
[27] FloydWarshall        - Floyd-Warshall moi cap dinh + truy vet
[28] KruskalMST           - Cay khung nho nhat Kruskal
[29] TopoSort             - Sap xep Topo (Kahn / DFS) & DP tren DAG
[30] TarjanCauKhop        - Tarjan tim Cau & Khop (an toan da do thi)
[31] TarjanSCC            - Tarjan tim Thanh phan lien thong manh SCC & nen DAG
[32] LCABinaryLifting     - LCA Binary Lifting + khoang cach & to tien thu k
[33] EulerTourCay         - Euler Tour trai phang cay + BIT
[34] RollingHash          - Rolling Hash 2 modulo chong hack
[35] KMP                  - Thuat toan KMP (Prefix Function)
[36] ZFunction            - Thuat toan Z-function
[37] CayTrie              - Trie xau ky tu & Binary Trie Max XOR
[38] QuayLuiNhanhCan      - Quay lui (to hop, hoan vi) & Nhanh can TSP
[39] MeetInTheMiddle      - Meet-in-the-middle chia doi tap hop (N <= 40)
[40] ThamLamKinhDien      - Tham lam lap lich chon doan & Noi day Huffman
[41] Kadane1D2D           - Kadane 1D & 2D (hinh chu nhat tong lon nhat)
[42] Knapsack             - Cai tui 0/1 (1D, 2D truy vet) & Unbounded
[43] LisLcsEdit           - LIS O(N log N) truy vet, LCS truy vet & Edit Distance
[44] DpKhoang             - Quy hoach dong tren doan [l,r] (Interval DP)
[45] BitmaskDP            - Bitmask DP (TSP N <= 20)
[46] DigitDP              - Digit DP dem so trong [L, R]
[47] TreeDPCoBan          - Tree DP tap doc lap & duong kinh cay
[48] TreeDPRerooting      - Tree DP Rerooting (doi goc cay O(N))
[49] DpToiUu              - Toi uu DP bang Segment Tree & Monotonic Deque
===============================================================
*/

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<bitset>
#include<random>
#include<chrono>
#include<fstream>
using namespace std;

#ifdef LOCAL
#define debug(x) cerr<<#x<<"="<<(x)<<'\n'
#else
#define debug(x)
#endif

// [01] Khung bai thi chuan HSG Tinh (brute + solve + fopen + timer)
namespace KhungThiHSG{
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
}

// [02] Bo sinh test ngau nhien (mang, hoan vi, cay, do thi) & stress test
namespace SinhTestStress{
	mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

	long long Rand(long long l,long long r){
		if(l>r) swap(l,r);
		return uniform_int_distribution<long long>(l,r)(rd);
	}

	void sinh_mang(ofstream& out,int n,long long l,long long r){
		out<<n<<'\n';
		for(int i=1;i<=n;i++) out<<Rand(l,r)<<(i==n?'\n':' ');
	}

	void sinh_hoan_vi(ofstream& out,int n){
		vector<int> p(n);
		for(int i=0;i<n;i++) p[i]=i+1;
		shuffle(p.begin(),p.end(),rd);
		out<<n<<'\n';
		for(int i=0;i<n;i++) out<<p[i]<<(i+1==n?'\n':' ');
	}

	void sinh_cay(ofstream& out,int n,long long min_w=1,long long max_w=100,bool co_trong_so=false){
		vector<int> p(n+1);
		for(int i=1;i<=n;i++) p[i]=i;
		shuffle(p.begin()+1,p.end(),rd);
		out<<n<<'\n';
		for(int i=2;i<=n;i++){
			int cha=p[Rand(1,i-1)];
			int con=p[i];
			if(Rand(0,1)) swap(cha,con);
			out<<cha<<" "<<con;
			if(co_trong_so) out<<" "<<Rand(min_w,max_w);
			out<<'\n';
		}
	}

	void sinh_do_thi(ofstream& out,int n,int m,bool co_trong_so=false,long long min_w=1,long long max_w=100){
		m=max(m,n-1);
		set<pair<int,int>> used;
		vector<pair<int,int>> edges;
		for(int i=2;i<=n;i++){
			int u=Rand(1,i-1),v=i;
			if(u>v) swap(u,v);
			used.insert({u,v});
			edges.push_back({u,v});
		}
		while((int)edges.size()<m){
			int u=Rand(1,n),v=Rand(1,n);
			if(u==v) continue;
			if(u>v) swap(u,v);
			if(used.count({u,v})) continue;
			used.insert({u,v});
			edges.push_back({u,v});
		}
		shuffle(edges.begin(),edges.end(),rd);
		out<<n<<" "<<edges.size()<<'\n';
		for(auto e:edges){
			int u=e.first,v=e.second;
			if(Rand(0,1)) swap(u,v);
			out<<u<<" "<<v;
			if(co_trong_so) out<<" "<<Rand(min_w,max_w);
			out<<'\n';
		}
	}

	void sinh(){
		ofstream out("sinh.inp");
		int n=Rand(2,15);
		sinh_mang(out,n,-100,100);
	}
}

// [03] Luy thua nhi phan fast_pow & Nhan An Do mul_mod
namespace LuyThuaMulMod{
	const long long MOD=1000000007;

	long long mul_mod(long long a,long long b,long long m){
		long long res=0;
		a=(a%m+m)%m;
		b=(b%m+m)%m;
		while(b>0){
			if(b&1){
				res+=a;
				if(res>=m) res-=m;
			}
			a+=a;
			if(a>=m) a-=m;
			b>>=1;
		}
		return res;
	}

	long long fast_pow(long long a,long long b,long long m){
		long long res=1%m;
		a=(a%m+m)%m;
		while(b>0){
			if(b&1) res=(1LL*res*a)%m;
			a=(1LL*a*a)%m;
			b>>=1;
		}
		return res;
	}

	long long fast_pow_safe(long long a,long long b,long long m){
		long long res=1%m;
		a=(a%m+m)%m;
		while(b>0){
			if(b&1) res=mul_mod(res,a,m);
			a=mul_mod(a,a,m);
			b>>=1;
		}
		return res;
	}
}

// [04] GCD, LCM, Euclid mo rong ext_gcd & Nghich dao modulo
namespace GcdExtGcdInv{
	long long gcd(long long a,long long b){
		if(a<0) a=-a;
		if(b<0) b=-b;
		while(b!=0){
			long long r=a%b;
			a=b;
			b=r;
		}
		return a;
	}

	long long lcm(long long a,long long b){
		if(a==0||b==0) return 0;
		return a/gcd(a,b)*b;
	}

	long long ext_gcd(long long a,long long b,long long& x,long long& y){
		if(b==0){
			x=1;
			y=0;
			return a;
		}
		long long x1,y1;
		long long d=ext_gcd(b,a%b,x1,y1);
		x=y1;
		y=x1-(a/b)*y1;
		return d;
	}

	long long mod_inv(long long a,long long m){
		long long x,y;
		long long d=ext_gcd((a%m+m)%m,m,x,y);
		if(d!=1) return -1;
		return (x%m+m)%m;
	}

	long long fast_pow(long long a,long long b,long long m){
		long long res=1%m;
		a=(a%m+m)%m;
		while(b>0){
			if(b&1) res=(res*a)%m;
			a=(a*a)%m;
			b>>=1;
		}
		return res;
	}

	long long mod_inv_prime(long long a,long long p){
		return fast_pow(a,p-2,p);
	}
}

// [05] To hop nCr modulo (giai thua O(1) & tam giac Pascal)
namespace ToHopNcrMod{
	const int MAXN=1000005;
	const long long MOD=1000000007;
	long long fact[MAXN],inv_fact[MAXN];

	long long fast_pow(long long a,long long b,long long m){
		long long res=1%m;
		a%=m;
		while(b>0){
			if(b&1) res=res*a%m;
			a=a*a%m;
			b>>=1;
		}
		return res;
	}

	void build_comb(int limit=MAXN-1){
		fact[0]=1;
		for(int i=1;i<=limit;i++) fact[i]=fact[i-1]*i%MOD;
		inv_fact[limit]=fast_pow(fact[limit],MOD-2,MOD);
		for(int i=limit-1;i>=0;i--) inv_fact[i]=inv_fact[i+1]*(i+1)%MOD;
	}

	long long nCr(int n,int k){
		if(k<0||k>n) return 0;
		return fact[n]*inv_fact[k]%MOD*inv_fact[n-k]%MOD;
	}

	// Dung khi n<=2000 va mod khong phai so nguyen to
	const int MAXP=2005;
	long long C[MAXP][MAXP];

	void build_pascal(int n,long long m){
		for(int i=0;i<=n;i++){
			C[i][0]=1%m;
			for(int j=1;j<=i;j++){
				C[i][j]=C[i-1][j-1]+C[i-1][j];
				if(C[i][j]>=m) C[i][j]-=m;
			}
		}
	}
}

// [06] Nen so / Roi rac hoa (Coordinate Compression)
namespace NenSoCompress{
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
}

// [07] So lon BigInt (cong, tru, nhan, chia lay du voi long long)
namespace SoLonBigInt{
	string chuan_hoa(string s){
		if(s.empty()) return "0";
		bool am=(s[0]=='-');
		int i=(s[0]=='-'||s[0]=='+')?1:0;
		while(i<(int)s.size()-1&&s[i]=='0') i++;
		string res=s.substr(i);
		if(res=="0") return "0";
		return am?"-"+res:res;
	}

	int cmp_abs(const string& a,const string& b){
		if(a.size()!=b.size()) return a.size()<b.size()?-1:1;
		if(a==b) return 0;
		return a<b?-1:1;
	}

	string add_abs(const string& a,const string& b){
		string res="";
		int i=(int)a.size()-1,j=(int)b.size()-1,carry=0;
		while(i>=0||j>=0||carry){
			int sum=carry;
			if(i>=0) sum+=a[i--]-'0';
			if(j>=0) sum+=b[j--]-'0';
			res+=char(sum%10+'0');
			carry=sum/10;
		}
		reverse(res.begin(),res.end());
		return chuan_hoa(res);
	}

	// Gia su a>=b>=0
	string sub_abs(const string& a,const string& b){
		string res="";
		int i=(int)a.size()-1,j=(int)b.size()-1,borrow=0;
		while(i>=0){
			int d=(a[i--]-'0')-borrow-(j>=0?b[j--]-'0':0);
			if(d<0){
				d+=10;
				borrow=1;
			}
			else borrow=0;
			res+=char(d+'0');
		}
		reverse(res.begin(),res.end());
		return chuan_hoa(res);
	}

	string add_big(string a,string b){
		a=chuan_hoa(a);b=chuan_hoa(b);
		bool neg_a=(a[0]=='-'),neg_b=(b[0]=='-');
		if(neg_a) a=a.substr(1);
		if(neg_b) b=b.substr(1);
		if(neg_a==neg_b){
			string res=add_abs(a,b);
			return (neg_a&&res!="0")?"-"+res:res;
		}
		int c=cmp_abs(a,b);
		if(c==0) return "0";
		if(c>0){
			string res=sub_abs(a,b);
			return neg_a?"-"+res:res;
		}
		string res=sub_abs(b,a);
		return neg_b?"-"+res:res;
	}

	string sub_big(string a,string b){
		b=chuan_hoa(b);
		if(b=="0") return chuan_hoa(a);
		if(b[0]=='-') b=b.substr(1);
		else b="-"+b;
		return add_big(a,b);
	}

	string mul_big(string a,string b){
		a=chuan_hoa(a);b=chuan_hoa(b);
		if(a=="0"||b=="0") return "0";
		bool neg=(a[0]=='-')^(b[0]=='-');
		if(a[0]=='-') a=a.substr(1);
		if(b[0]=='-') b=b.substr(1);
		int n=a.size(),m=b.size();
		vector<int> p(n+m,0);
		for(int i=n-1;i>=0;i--)
			for(int j=m-1;j>=0;j--){
				int sum=(a[i]-'0')*(b[j]-'0')+p[i+j+1];
				p[i+j+1]=sum%10;
				p[i+j]+=sum/10;
			}
		string res="";
		for(int x:p) if(!(res.empty()&&x==0)) res+=char(x+'0');
		if(res.empty()) return "0";
		return neg?"-"+res:res;
	}

	// Chia so nguyen khong am cho b>0 (luu y b <= 9e17 de khong tran cur*10)
	pair<string,long long> div_mod_big(string a,long long b){
		a=chuan_hoa(a);
		string q="";
		long long rem=0;
		for(char ch:a){
			rem=rem*10+(ch-'0');
			q+=char(rem/b+'0');
			rem%=b;
		}
		return {chuan_hoa(q),rem};
	}
}

// [08] Sang Eratosthenes bitset & Kiem tra nguyen to O(sqrt(N))
namespace SangNguyenTo{
	const int MAXN=10000000;
	bitset<MAXN+8> not_prime;

	void sieve(int limit=MAXN){
		not_prime[0]=not_prime[1]=1;
		for(int i=4;i<=limit;i+=2) not_prime[i]=1;
		for(int i=3;1LL*i*i<=limit;i+=2)
			if(!not_prime[i])
				for(long long j=1LL*i*i;j<=limit;j+=2LL*i)
					not_prime[j]=1;
	}

	bool is_prime(long long n){
		if(n<=1) return false;
		if(n==2||n==3) return true;
		if(n%2==0||n%3==0) return false;
		for(long long i=5;i<=n/i;i+=6)
			if(n%i==0||n%(i+2)==0) return false;
		return true;
	}
}

// [09] Sang uoc nguyen to nho nhat SPF & Phan tich thua so
namespace SangSPF{
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
}

// [10] Dem uoc, Tong uoc & Phi ham Euler
namespace UocVaPhiEuler{
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
}

// [11] Tong tien to (Prefix Sum) 1D & 2D
namespace PrefixSum{
	const int MAXN=200005;
	const int MAXM=1005;
	int n,m;
	long long a[MAXN],pf[MAXN];
	long long g[MAXM][MAXM],pf2[MAXM][MAXM];

	void build_1d(){
		for(int i=1;i<=n;i++) pf[i]=pf[i-1]+a[i];
	}

	long long sum_1d(int l,int r){
		if(l>r) return 0;
		return pf[r]-pf[l-1];
	}

	void build_2d(){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				pf2[i][j]=pf2[i-1][j]+pf2[i][j-1]-pf2[i-1][j-1]+g[i][j];
	}

	long long sum_2d(int x1,int y1,int x2,int y2){
		if(x1>x2||y1>y2) return 0;
		return pf2[x2][y2]-pf2[x1-1][y2]-pf2[x2][y1-1]+pf2[x1-1][y1-1];
	}
}

// [12] Mang hieu (Difference Array) 1D & 2D
namespace MangHieuDiff{
	const int MAXN=200005;
	const int MAXM=1005;
	int n,m;
	long long d1[MAXN],a[MAXN];
	long long d2[MAXM][MAXM],g[MAXM][MAXM];

	void add_1d(int l,int r,long long val){
		d1[l]+=val;
		d1[r+1]-=val;
	}

	void build_1d(){
		for(int i=1;i<=n;i++){
			d1[i]+=d1[i-1];
			a[i]+=d1[i];
		}
	}

	void add_2d(int x1,int y1,int x2,int y2,long long val){
		d2[x1][y1]+=val;
		d2[x2+1][y1]-=val;
		d2[x1][y2+1]-=val;
		d2[x2+1][y2+1]+=val;
	}

	void build_2d(){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				d2[i][j]+=d2[i-1][j]+d2[i][j-1]-d2[i-1][j-1];
				g[i][j]+=d2[i][j];
			}
	}
}

// [13] Chat nhi phan tren mang, tren ket qua & so thuc
namespace ChatNhiPhan{
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
}

// [14] Hai con tro (Two Pointers) O(N)
namespace HaiConTro{
	const int MAXN=200005;
	int n,k;
	int a[MAXN];

	void doan_khac_nhau_max(){
		unordered_map<int,int> freq;
		int l=1,numdif=0,maxlen=0,pos=1;
		for(int r=1;r<=n;r++){
			freq[a[r]]++;
			if(freq[a[r]]==1) numdif++;
			while(numdif>k){
				freq[a[l]]--;
				if(freq[a[l]]==0) numdif--;
				l++;
			}
			if(r-l+1>maxlen){
				maxlen=r-l+1;
				pos=l;
			}
		}
		cout<<maxlen<<" "<<pos<<'\n';
	}

	long long dem_doan_tong_le(long long s){
		long long sum=0,res=0;
		int l=1;
		for(int r=1;r<=n;r++){
			sum+=a[r];
			while(sum>s&&l<=r){
				sum-=a[l];
				l++;
			}
			res+=(r-l+1);
		}
		return res;
	}
}

// [15] Cua so truot Min / Max bang Deque O(N)
namespace SlidingWindowDeque{
	const int MAXN=200005;
	int n,k;
	long long a[MAXN],mn[MAXN],mx[MAXN];

	void sliding_window(){
		deque<int> dq_min,dq_max;
		for(int i=1;i<=n;i++){
			while(!dq_min.empty()&&a[dq_min.back()]>=a[i]) dq_min.pop_back();
			dq_min.push_back(i);
			if(dq_min.front()<=i-k) dq_min.pop_front();

			while(!dq_max.empty()&&a[dq_max.back()]<=a[i]) dq_max.pop_back();
			dq_max.push_back(i);
			if(dq_max.front()<=i-k) dq_max.pop_front();

			if(i>=k){
				mn[i]=a[dq_min.front()];
				mx[i]=a[dq_max.front()];
			}
		}
	}
}

// [16] Ngan xep don dieu & Hinh chu nhat lon nhat Histogram
namespace MonotonicStack{
	const int MAXN=200005;
	int n,L[MAXN],R[MAXN];
	long long h[MAXN];

	long long largest_rectangle(){
		stack<int> st;
		for(int i=1;i<=n;i++){
			while(!st.empty()&&h[st.top()]>=h[i]) st.pop();
			L[i]=st.empty()?0:st.top();
			st.push(i);
		}
		while(!st.empty()) st.pop();
		for(int i=n;i>=1;i--){
			while(!st.empty()&&h[st.top()]>=h[i]) st.pop();
			R[i]=st.empty()?n+1:st.top();
			st.push(i);
		}
		long long res=0;
		for(int i=1;i<=n;i++){
			long long area=h[i]*(R[i]-L[i]-1);
			if(area>res) res=area;
		}
		return res;
	}
}

// [17] Disjoint Set Union (Path Compression + Union by Size)
namespace DSU{
	const int MAXN=200005;
	int n,m,comp_cnt;
	int par[MAXN],sz[MAXN];

	void dsu_init(int n_nodes){
		comp_cnt=n_nodes;
		for(int i=1;i<=n_nodes;i++){
			par[i]=i;
			sz[i]=1;
		}
	}

	int find_set(int u){
		if(par[u]==u) return u;
		return par[u]=find_set(par[u]);
	}

	bool unite(int u,int v){
		u=find_set(u);
		v=find_set(v);
		if(u==v) return false;
		if(sz[u]<sz[v]) swap(u,v);
		par[v]=u;
		sz[u]+=sz[v];
		comp_cnt--;
		return true;
	}
}

// [18] Sparse Table RMQ truy van O(1)
namespace SparseTableRMQ{
	const int MAXN=200005;
	const int LOG=18;
	int n,lg2[MAXN];
	long long a[MAXN],st[MAXN][LOG];

	void build_rmq(){
		lg2[1]=0;
		for(int i=2;i<=n;i++) lg2[i]=lg2[i/2]+1;
		for(int i=1;i<=n;i++) st[i][0]=a[i];
		for(int j=1;j<LOG;j++)
			for(int i=1;i+(1<<j)-1<=n;i++)
				st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}

	long long query_min(int l,int r){
		int j=lg2[r-l+1];
		return min(st[l][j],st[r-(1<<j)+1][j]);
	}
}

// [19] Fenwick Tree (BIT) 1D diem & doan
namespace FenwickBIT{
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
}

// [20] Segment Tree co ban (Point Update - Range Sum/Min)
namespace SegTreePoint{
	const int MAXN=200005;
	const long long INF=2e18;
	int n,q;
	long long an[MAXN],t_sum[4*MAXN],t_min[4*MAXN];

	void build(int id,int l,int r){
		if(l==r){
			t_sum[id]=an[l];
			t_min[id]=an[l];
			return;
		}
		int mid=(l+r)/2;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		t_sum[id]=t_sum[id*2]+t_sum[id*2+1];
		t_min[id]=min(t_min[id*2],t_min[id*2+1]);
	}

	void update(int id,int l,int r,int pos,long long x){
		if(l==r){
			t_sum[id]=x;
			t_min[id]=x;
			return;
		}
		int mid=(l+r)/2;
		if(pos<=mid) update(id*2,l,mid,pos,x);
		else update(id*2+1,mid+1,r,pos,x);
		t_sum[id]=t_sum[id*2]+t_sum[id*2+1];
		t_min[id]=min(t_min[id*2],t_min[id*2+1]);
	}

	long long get_sum(int id,int l,int r,int u,int v){
		if(v<l||u>r) return 0;
		if(u<=l&&r<=v) return t_sum[id];
		int mid=(l+r)/2;
		return get_sum(id*2,l,mid,u,v)+get_sum(id*2+1,mid+1,r,u,v);
	}

	long long get_min(int id,int l,int r,int u,int v){
		if(v<l||u>r) return INF;
		if(u<=l&&r<=v) return t_min[id];
		int mid=(l+r)/2;
		return min(get_min(id*2,l,mid,u,v),get_min(id*2+1,mid+1,r,u,v));
	}
}

// [21] Segment Tree Lazy Propagation (Add/Set + Sum/Max)
namespace SegTreeLazy{
	const int MAXN=200005;
	const long long NEG_INF=-2e18;
	int n,q;
	long long a[MAXN],t_sum[4*MAXN],t_max[4*MAXN],lz_add[4*MAXN],lz_set[4*MAXN];
	bool has_set[4*MAXN];

	void apply_set(int id,int l,int r,long long x){
		t_sum[id]=x*(r-l+1);
		t_max[id]=x;
		lz_set[id]=x;
		lz_add[id]=0;
		has_set[id]=true;
	}

	void apply_add(int id,int l,int r,long long val){
		t_sum[id]+=val*(r-l+1);
		t_max[id]+=val;
		if(has_set[id]) lz_set[id]+=val;
		else lz_add[id]+=val;
	}

	void push(int id,int l,int r){
		if(l==r) return;
		int mid=(l+r)/2;
		if(has_set[id]){
			apply_set(id*2,l,mid,lz_set[id]);
			apply_set(id*2+1,mid+1,r,lz_set[id]);
			has_set[id]=false;
		}
		if(lz_add[id]!=0){
			apply_add(id*2,l,mid,lz_add[id]);
			apply_add(id*2+1,mid+1,r,lz_add[id]);
			lz_add[id]=0;
		}
	}

	void build(int id,int l,int r){
		has_set[id]=false;
		lz_add[id]=0;
		if(l==r){
			t_sum[id]=t_max[id]=a[l];
			return;
		}
		int mid=(l+r)/2;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		t_sum[id]=t_sum[id*2]+t_sum[id*2+1];
		t_max[id]=max(t_max[id*2],t_max[id*2+1]);
	}

	void update_add(int id,int l,int r,int u,int v,long long val){
		if(v<l||u>r) return;
		if(u<=l&&r<=v){
			apply_add(id,l,r,val);
			return;
		}
		push(id,l,r);
		int mid=(l+r)/2;
		update_add(id*2,l,mid,u,v,val);
		update_add(id*2+1,mid+1,r,u,v,val);
		t_sum[id]=t_sum[id*2]+t_sum[id*2+1];
		t_max[id]=max(t_max[id*2],t_max[id*2+1]);
	}

	void update_set(int id,int l,int r,int u,int v,long long x){
		if(v<l||u>r) return;
		if(u<=l&&r<=v){
			apply_set(id,l,r,x);
			return;
		}
		push(id,l,r);
		int mid=(l+r)/2;
		update_set(id*2,l,mid,u,v,x);
		update_set(id*2+1,mid+1,r,u,v,x);
		t_sum[id]=t_sum[id*2]+t_sum[id*2+1];
		t_max[id]=max(t_max[id*2],t_max[id*2+1]);
	}

	long long get_sum(int id,int l,int r,int u,int v){
		if(v<l||u>r) return 0;
		if(u<=l&&r<=v) return t_sum[id];
		push(id,l,r);
		int mid=(l+r)/2;
		return get_sum(id*2,l,mid,u,v)+get_sum(id*2+1,mid+1,r,u,v);
	}

	long long get_max(int id,int l,int r,int u,int v){
		if(v<l||u>r) return NEG_INF;
		if(u<=l&&r<=v) return t_max[id];
		push(id,l,r);
		int mid=(l+r)/2;
		return max(get_max(id*2,l,mid,u,v),get_max(id*2+1,mid+1,r,u,v));
	}
}

// [22] Walk on Segment Tree (first >= x, k-th order)
namespace WalkOnSegTree{
	const int MAXN=200005;
	int n;
	long long a[MAXN],t_max[4*MAXN],t_cnt[4*MAXN];

	void build_max(int id,int l,int r){
		if(l==r){
			t_max[id]=a[l];
			return;
		}
		int mid=(l+r)/2;
		build_max(id*2,l,mid);
		build_max(id*2+1,mid+1,r);
		t_max[id]=max(t_max[id*2],t_max[id*2+1]);
	}

	void update_max(int id,int l,int r,int pos,long long x){
		if(l==r){
			t_max[id]=x;
			return;
		}
		int mid=(l+r)/2;
		if(pos<=mid) update_max(id*2,l,mid,pos,x);
		else update_max(id*2+1,mid+1,r,pos,x);
		t_max[id]=max(t_max[id*2],t_max[id*2+1]);
	}

	// Tra ve chi so nho nhat trong [u,v] co a[pos]>=x (-1 neu khong co)
	int find_first_ge(int id,int l,int r,int u,int v,long long x){
		if(v<l||u>r||t_max[id]<x) return -1;
		if(l==r) return l;
		int mid=(l+r)/2;
		int res=find_first_ge(id*2,l,mid,u,v,x);
		if(res!=-1) return res;
		return find_first_ge(id*2+1,mid+1,r,u,v,x);
	}

	// Cay tan so: them delta vao gia tri pos (1<=pos<=n)
	void add_freq(int id,int l,int r,int pos,long long delta){
		if(l==r){
			t_cnt[id]+=delta;
			return;
		}
		int mid=(l+r)/2;
		if(pos<=mid) add_freq(id*2,l,mid,pos,delta);
		else add_freq(id*2+1,mid+1,r,pos,delta);
		t_cnt[id]=t_cnt[id*2]+t_cnt[id*2+1];
	}

	// Tim gia tri nho thu k (1-indexed), tra ve -1 neu tong tan so < k
	int kth_order(int id,int l,int r,long long k){
		if(t_cnt[id]<k) return -1;
		if(l==r) return l;
		int mid=(l+r)/2;
		if(t_cnt[id*2]>=k) return kth_order(id*2,l,mid,k);
		return kth_order(id*2+1,mid+1,r,k-t_cnt[id*2]);
	}
}

// [23] BFS / DFS, TPLT, 2 phia, chu trinh & luoi 4 huong
namespace BfsDfsCoBan{
	const int MAXN=200005;
	int n,m;
	vector<int> adj[MAXN];
	int vis[MAXN],color[MAXN];

	void dfs(int u){
		vis[u]=1;
		for(int v:adj[u]){
			if(!vis[v]) dfs(v);
		}
	}

	void bfs(int s){
		queue<int> q;
		vis[s]=1;
		q.push(s);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int v:adj[u]){
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}

	bool check_bipartite(int s){
		queue<int> q;
		color[s]=0;
		q.push(s);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int v:adj[u]){
				if(color[v]==-1){
					color[v]=color[u]^1;
					q.push(v);
				}
				else if(color[v]==color[u]) return false;
			}
		}
		return true;
	}

	// Phat hien chu trinh do thi vo huong (vis: 0=chua tham, 1=da tham)
	bool has_cycle_undirected(int u,int p){
		vis[u]=1;
		for(int v:adj[u]){
			if(v==p) continue;
			if(vis[v]) return true;
			if(has_cycle_undirected(v,u)) return true;
		}
		return false;
	}

	// Phat hien chu trinh do thi co huong (vis: 0=chua, 1=dang trong stack, 2=xong)
	bool has_cycle_directed(int u){
		vis[u]=1;
		for(int v:adj[u]){
			if(vis[v]==1) return true;
			if(vis[v]==0&&has_cycle_directed(v)) return true;
		}
		vis[u]=2;
		return false;
	}

	// BFS tren luoi 4 huong (1..R, 1..C)
	const int dx[4]={-1,1,0,0};
	const int dy[4]={0,0,-1,1};
	int R,C;
	int d_grid[1005][1005];
	char grid[1005][1005];

	void bfs_grid(int sx,int sy){
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++) d_grid[i][j]=-1;
		queue<pair<int,int>> q;
		d_grid[sx][sy]=0;
		q.push({sx,sy});
		while(!q.empty()){
			int x=q.front().first,y=q.front().second;
			q.pop();
			for(int k=0;k<4;k++){
				int nx=x+dx[k],ny=y+dy[k];
				if(nx<1||nx>R||ny<1||ny>C) continue;
				if(grid[nx][ny]=='#'||d_grid[nx][ny]!=-1) continue;
				d_grid[nx][ny]=d_grid[x][y]+1;
				q.push({nx,ny});
			}
		}
	}
}

// [24] 0-1 BFS bang Deque O(V + E)
namespace Bfs01{
	const int MAXN=200005;
	const int INF=2e9;
	int n,m;
	vector<pair<int,int>> adj[MAXN];
	int dist_arr[MAXN];

	void bfs_01(int s){
		for(int i=1;i<=n;i++) dist_arr[i]=INF;
		deque<int> dq;
		dist_arr[s]=0;
		dq.push_front(s);
		while(!dq.empty()){
			int u=dq.front();
			dq.pop_front();
			for(auto e:adj[u]){
				int v=e.first,w=e.second;
				if(dist_arr[u]+w<dist_arr[v]){
					dist_arr[v]=dist_arr[u]+w;
					if(w==0) dq.push_front(v);
					else dq.push_back(v);
				}
			}
		}
	}
}

// [25] Dijkstra + Truy vet duong di ngan nhat
namespace Dijkstra{
	const int MAXN=200005;
	const long long INF=2e18;
	int n,m;
	vector<pair<int,long long>> adj[MAXN];
	long long dist_arr[MAXN];
	int par[MAXN];

	void dijkstra(int s){
		for(int i=1;i<=n;i++){
			dist_arr[i]=INF;
			par[i]=-1;
		}
		priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
		dist_arr[s]=0;
		pq.push({0,s});
		while(!pq.empty()){
			long long d=pq.top().first;
			int u=pq.top().second;
			pq.pop();
			if(d>dist_arr[u]) continue;
			for(auto e:adj[u]){
				int v=e.first;
				long long w=e.second;
				if(dist_arr[u]+w<dist_arr[v]){
					dist_arr[v]=dist_arr[u]+w;
					par[v]=u;
					pq.push({dist_arr[v],v});
				}
			}
		}
	}

	vector<int> restore_path(int s,int t){
		vector<int> path;
		if(dist_arr[t]==INF) return path;
		for(int v=t;v!=-1;v=par[v]) path.push_back(v);
		reverse(path.begin(),path.end());
		if(path.empty()||path[0]!=s) return {};
		return path;
	}
}

// [26] Bellman-Ford & Phat hien + truy vet chu trinh am
namespace BellmanFord{
	struct Edge{
		int u,v;
		long long w;
	};

	const int MAXN=2505;
	const long long INF=2e18;
	int n,m;
	vector<Edge> edges;
	long long dist_arr[MAXN];
	int par[MAXN];

	// Tim chu trinh am bat ky (khong phu thuoc dinh nguon khi khoi tao dist=0)
	vector<int> find_negative_cycle(){
		for(int i=1;i<=n;i++){
			dist_arr[i]=0;
			par[i]=-1;
		}
		int last=-1;
		for(int step=1;step<=n;step++){
			last=-1;
			for(const auto& e:edges){
				if(dist_arr[e.u]+e.w<dist_arr[e.v]){
					dist_arr[e.v]=dist_arr[e.u]+e.w;
					par[e.v]=e.u;
					last=e.v;
				}
			}
		}
		if(last==-1) return {};
		for(int i=1;i<=n;i++) last=par[last];
		vector<int> cycle;
		for(int v=last;;v=par[v]){
			cycle.push_back(v);
			if(v==last&&cycle.size()>1) break;
		}
		reverse(cycle.begin(),cycle.end());
		return cycle;
	}

	// Bellman-Ford tu dinh nguon s (tra ve false neu co chu trinh am den duoc tu s)
	bool bellman_ford(int s){
		for(int i=1;i<=n;i++){
			dist_arr[i]=INF;
			par[i]=-1;
		}
		dist_arr[s]=0;
		for(int step=1;step<n;step++){
			bool changed=false;
			for(const auto& e:edges){
				if(dist_arr[e.u]!=INF&&dist_arr[e.u]+e.w<dist_arr[e.v]){
					dist_arr[e.v]=dist_arr[e.u]+e.w;
					par[e.v]=e.u;
					changed=true;
				}
			}
			if(!changed) break;
		}
		for(const auto& e:edges)
			if(dist_arr[e.u]!=INF&&dist_arr[e.u]+e.w<dist_arr[e.v]) return false;
		return true;
	}
}

// [27] Floyd-Warshall moi cap dinh + truy vet
namespace FloydWarshall{
	const int MAXN=405;
	const long long INF=2e18;
	int n,m;
	long long d[MAXN][MAXN];
	int nxt[MAXN][MAXN];

	void floyd_init(){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				d[i][j]=(i==j?0:INF);
				nxt[i][j]=(i==j?i:-1);
			}
	}

	void floyd(){
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++){
				if(d[i][k]==INF) continue;
				for(int j=1;j<=n;j++){
					if(d[k][j]==INF) continue;
					if(d[i][k]+d[k][j]<d[i][j]){
						d[i][j]=d[i][k]+d[k][j];
						nxt[i][j]=nxt[i][k];
					}
				}
			}
	}

	vector<int> trace_path(int u,int v){
		if(nxt[u][v]==-1) return {};
		vector<int> path;
		path.push_back(u);
		while(u!=v){
			u=nxt[u][v];
			path.push_back(u);
		}
		return path;
	}
}

// [28] Cay khung nho nhat Kruskal
namespace KruskalMST{
	struct Edge{
		int u,v;
		long long w;
		bool operator<(const Edge& o) const{
			return w<o.w;
		}
	};

	const int MAXN=200005;
	int n,m;
	int par[MAXN],sz[MAXN];
	vector<Edge> edges,mst;

	void dsu_init(){
		for(int i=1;i<=n;i++){
			par[i]=i;
			sz[i]=1;
		}
	}

	int find_set(int u){
		if(par[u]==u) return u;
		return par[u]=find_set(par[u]);
	}

	bool unite(int u,int v){
		u=find_set(u);
		v=find_set(v);
		if(u==v) return false;
		if(sz[u]<sz[v]) swap(u,v);
		par[v]=u;
		sz[u]+=sz[v];
		return true;
	}

	long long kruskal(){
		sort(edges.begin(),edges.end());
		dsu_init();
		mst.clear();
		long long total=0;
		for(const auto& e:edges){
			if(unite(e.u,e.v)){
				total+=e.w;
				mst.push_back(e);
				if((int)mst.size()==n-1) break;
			}
		}
		if((int)mst.size()!=n-1) return -1;
		return total;
	}
}

// [29] Sap xep Topo (Kahn / DFS) & DP tren DAG
namespace TopoSort{
	const int MAXN=200005;
	int n,m,indeg[MAXN],vis[MAXN];
	vector<int> adj[MAXN],topo;

	bool kahn_topo(bool min_lex=false){
		topo.clear();
		if(!min_lex){
			queue<int> q;
			for(int i=1;i<=n;i++) if(indeg[i]==0) q.push(i);
			while(!q.empty()){
				int u=q.front();
				q.pop();
				topo.push_back(u);
				for(int v:adj[u]){
					indeg[v]--;
					if(indeg[v]==0) q.push(v);
				}
			}
		}
		else{
			priority_queue<int,vector<int>,greater<int>> pq;
			for(int i=1;i<=n;i++) if(indeg[i]==0) pq.push(i);
			while(!pq.empty()){
				int u=pq.top();
				pq.pop();
				topo.push_back(u);
				for(int v:adj[u]){
					indeg[v]--;
					if(indeg[v]==0) pq.push(v);
				}
			}
		}
		return (int)topo.size()==n;
	}

	bool dfs_topo(int u){
		vis[u]=1;
		for(int v:adj[u]){
			if(vis[v]==1) return false;
			if(vis[v]==0&&!dfs_topo(v)) return false;
		}
		vis[u]=2;
		topo.push_back(u);
		return true;
	}

	// DP duong di dai nhat tren DAG theo thu tu topo
	int dp_dag[MAXN];
	int longest_path_dag(){
		int res=0;
		for(int u:topo){
			for(int v:adj[u]) dp_dag[v]=max(dp_dag[v],dp_dag[u]+1);
			res=max(res,dp_dag[u]);
		}
		return res;
	}
}

// [30] Tarjan tim Cau & Khop (an toan da do thi)
namespace TarjanCauKhop{
	const int MAXN=200005;
	int n,m,timer;
	vector<pair<int,int>> adj[MAXN];
	int tin[MAXN],low[MAXN];
	bool is_cut[MAXN];
	vector<pair<int,int>> bridges;

	void dfs(int u,int pe_id){
		tin[u]=low[u]=++timer;
		int child=0;
		for(auto e:adj[u]){
			int v=e.first,id=e.second;
			if(id==pe_id) continue;
			if(tin[v]) low[u]=min(low[u],tin[v]);
			else{
				child++;
				dfs(v,id);
				low[u]=min(low[u],low[v]);
				if(low[v]>tin[u]) bridges.push_back({u,v});
				if(pe_id!=-1&&low[v]>=tin[u]) is_cut[u]=true;
			}
		}
		if(pe_id==-1&&child>1) is_cut[u]=true;
	}
}

// [31] Tarjan tim Thanh phan lien thong manh SCC & nen DAG
namespace TarjanSCC{
	const int MAXN=200005;
	int n,m,timer,scc_cnt;
	vector<int> adj[MAXN],dag[MAXN];
	int tin[MAXN],low[MAXN],scc_id[MAXN];
	bool on_stack[MAXN];
	stack<int> st;

	void dfs(int u){
		tin[u]=low[u]=++timer;
		st.push(u);
		on_stack[u]=true;
		for(int v:adj[u]){
			if(!tin[v]){
				dfs(v);
				low[u]=min(low[u],low[v]);
			}
			else if(on_stack[v]) low[u]=min(low[u],tin[v]);
		}
		if(low[u]==tin[u]){
			scc_cnt++;
			while(true){
				int v=st.top();
				st.pop();
				on_stack[v]=false;
				scc_id[v]=scc_cnt;
				if(v==u) break;
			}
		}
	}

	void build_dag(){
		for(int u=1;u<=n;u++)
			for(int v:adj[u])
				if(scc_id[u]!=scc_id[v])
					dag[scc_id[u]].push_back(scc_id[v]);
	}
}

// [32] LCA Binary Lifting + khoang cach & to tien thu k
namespace LCABinaryLifting{
	const int MAXN=200005;
	const int LOG=18;
	int n,q;
	vector<pair<int,long long>> adj[MAXN];
	int up[MAXN][LOG],h[MAXN];
	long long dist_root[MAXN];

	void dfs_lca(int u,int p){
		up[u][0]=p;
		for(int j=1;j<LOG;j++) up[u][j]=up[up[u][j-1]][j-1];
		for(auto e:adj[u]){
			int v=e.first;
			long long w=e.second;
			if(v==p) continue;
			h[v]=h[u]+1;
			dist_root[v]=dist_root[u]+w;
			dfs_lca(v,u);
		}
	}

	int kth_ancestor(int u,int k){
		for(int j=0;j<LOG;j++)
			if((k>>j)&1) u=up[u][j];
		return u;
	}

	int lca(int u,int v){
		if(h[u]<h[v]) swap(u,v);
		u=kth_ancestor(u,h[u]-h[v]);
		if(u==v) return u;
		for(int j=LOG-1;j>=0;j--)
			if(up[u][j]!=up[v][j]){
				u=up[u][j];
				v=up[v][j];
			}
		return up[u][0];
	}

	long long dist_uv(int u,int v){
		int w=lca(u,v);
		return dist_root[u]+dist_root[v]-2*dist_root[w];
	}
}

// [33] Euler Tour trai phang cay + BIT
namespace EulerTourCay{
	const int MAXN=200005;
	int n,q,timer;
	vector<int> adj[MAXN];
	int tin[MAXN],tout[MAXN];
	long long val[MAXN],bit[MAXN];

	void dfs_euler(int u,int p){
		tin[u]=++timer;
		for(int v:adj[u])
			if(v!=p) dfs_euler(v,u);
		tout[u]=timer;
	}

	void bit_add(int pos,long long delta){
		for(;pos<=n;pos+=pos&-pos) bit[pos]+=delta;
	}

	long long bit_get(int pos){
		long long res=0;
		for(;pos>0;pos-=pos&-pos) res+=bit[pos];
		return res;
	}

	void update_node(int u,long long new_val){
		long long delta=new_val-val[u];
		val[u]=new_val;
		bit_add(tin[u],delta);
	}

	long long query_subtree(int u){
		return bit_get(tout[u])-bit_get(tin[u]-1);
	}
}

// [34] Rolling Hash 2 modulo chong hack
namespace RollingHash{
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
}

// [35] Thuat toan KMP (Prefix Function)
namespace KMP{
	vector<int> build_pi(const string& s){
		int n=s.size();
		vector<int> pi(n,0);
		for(int i=1;i<n;i++){
			int j=pi[i-1];
			while(j>0&&s[i]!=s[j]) j=pi[j-1];
			if(s[i]==s[j]) j++;
			pi[i]=j;
		}
		return pi;
	}

	vector<int> kmp_search(const string& text,const string& pat){
		vector<int> pi=build_pi(pat),pos;
		int j=0,m=pat.size();
		for(int i=0;i<(int)text.size();i++){
			while(j>0&&text[i]!=pat[j]) j=pi[j-1];
			if(text[i]==pat[j]) j++;
			if(j==m){
				pos.push_back(i-m+2);
				j=pi[j-1];
			}
		}
		return pos;
	}
}

// [36] Thuat toan Z-function
namespace ZFunction{
	vector<int> build_z(const string& s){
		int n=s.size();
		vector<int> z(n,0);
		int l=0,r=0;
		for(int i=1;i<n;i++){
			if(i<=r) z[i]=min(r-i+1,z[i-l]);
			while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
			if(i+z[i]-1>r){
				l=i;
				r=i+z[i]-1;
			}
		}
		return z;
	}

	vector<int> z_search(const string& text,const string& pat){
		string comb=pat+"#"+text;
		vector<int> z=build_z(comb),pos;
		int m=pat.size();
		for(int i=m+1;i<(int)comb.size();i++)
			if(z[i]==m) pos.push_back(i-m);
		return pos;
	}
}

// [37] Trie xau ky tu & Binary Trie Max XOR
namespace CayTrie{
	const int MAXNODE=400005;

	// --- Phan 1: Trie xau ky tu ---
	int nxt_ch[MAXNODE][26],cnt_pass[MAXNODE],cnt_end[MAXNODE],sz_ch=1;

	void insert_str(const string& s){
		int u=1;
		for(char ch:s){
			int c=ch-'a';
			if(!nxt_ch[u][c]) nxt_ch[u][c]=++sz_ch;
			u=nxt_ch[u][c];
			cnt_pass[u]++;
		}
		cnt_end[u]++;
	}

	int count_word(const string& s){
		int u=1;
		for(char ch:s){
			int c=ch-'a';
			if(!nxt_ch[u][c]) return 0;
			u=nxt_ch[u][c];
		}
		return cnt_end[u];
	}

	int count_prefix(const string& s){
		int u=1;
		for(char ch:s){
			int c=ch-'a';
			if(!nxt_ch[u][c]) return 0;
			u=nxt_ch[u][c];
		}
		return cnt_pass[u];
	}

	// --- Phan 2: Binary Trie (30 bit) ---
	int nxt_bin[MAXNODE][2],sz_bin=1;

	void insert_num(int x){
		int u=1;
		for(int b=30;b>=0;b--){
			int bit=(x>>b)&1;
			if(!nxt_bin[u][bit]) nxt_bin[u][bit]=++sz_bin;
			u=nxt_bin[u][bit];
		}
	}

	int max_xor(int x){
		int u=1,res=0;
		for(int b=30;b>=0;b--){
			int bit=(x>>b)&1;
			if(nxt_bin[u][bit^1]){
				res|=(1<<b);
				u=nxt_bin[u][bit^1];
			}
			else if(nxt_bin[u][bit]) u=nxt_bin[u][bit];
			else break;
		}
		return res;
	}
}

// [38] Quay lui (to hop, hoan vi) & Nhanh can TSP
namespace QuayLuiNhanhCan{
	const int MAXN=20;
	const long long INF=2e18;
	int n,k;
	int x[MAXN];
	bool used[MAXN];

	void back_comb(int i,int start){
		if(i>k){
			for(int j=1;j<=k;j++) cout<<x[j]<<(j==k?'\n':' ');
			return;
		}
		for(int v=start;v<=n-k+i;v++){
			x[i]=v;
			back_comb(i+1,v+1);
		}
	}

	void back_perm(int i){
		if(i>n){
			for(int j=1;j<=n;j++) cout<<x[j]<<(j==n?'\n':' ');
			return;
		}
		for(int v=1;v<=n;v++){
			if(!used[v]){
				used[v]=true;
				x[i]=v;
				back_perm(i+1);
				used[v]=false;
			}
		}
	}

	// Nhanh can TSP: quay ve dinh 1
	long long cost[MAXN][MAXN],cmin=INF,best_tsp=INF;
	int path_tsp[MAXN];
	bool vis_tsp[MAXN];

	void branch_bound(int step,long long cur_cost){
		if(cur_cost+(n-step+1)*cmin>=best_tsp) return;
		if(step==n){
			if(cost[path_tsp[n]][1]<INF)
				best_tsp=min(best_tsp,cur_cost+cost[path_tsp[n]][1]);
			return;
		}
		int u=path_tsp[step];
		for(int v=2;v<=n;v++){
			if(!vis_tsp[v]&&cost[u][v]<INF){
				vis_tsp[v]=true;
				path_tsp[step+1]=v;
				branch_bound(step+1,cur_cost+cost[u][v]);
				vis_tsp[v]=false;
			}
		}
	}
}

// [39] Meet-in-the-middle chia doi tap hop (N <= 40)
namespace MeetInTheMiddle{
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
}

// [40] Tham lam lap lich chon doan & Noi day Huffman
namespace ThamLamKinhDien{
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
}

// [41] Kadane 1D & 2D (hinh chu nhat tong lon nhat)
namespace Kadane1D2D{
	const int MAXN=200005;
	const int MAXM=405;
	int n,m;
	long long a[MAXN];
	long long g[MAXM][MAXM],col[MAXM];

	long long kadane_1d(int& best_l,int& best_r){
		long long best=-2e18,cur=0;
		int cur_l=1;
		best_l=best_r=1;
		for(int i=1;i<=n;i++){
			if(cur+a[i]<a[i]){
				cur=a[i];
				cur_l=i;
			}
			else cur+=a[i];
			if(cur>best){
				best=cur;
				best_l=cur_l;
				best_r=i;
			}
		}
		return best;
	}

	long long kadane_2d(){
		long long res=-2e18;
		for(int top=1;top<=n;top++){
			for(int j=1;j<=m;j++) col[j]=0;
			for(int bot=top;bot<=n;bot++){
				long long cur=0,best_row=-2e18;
				for(int j=1;j<=m;j++){
					col[j]+=g[bot][j];
					cur=max(col[j],cur+col[j]);
					best_row=max(best_row,cur);
				}
				res=max(res,best_row);
			}
		}
		return res;
	}
}

// [42] Cai tui 0/1 (1D, 2D truy vet) & Unbounded
namespace Knapsack{
	const int MAXN=1005;
	const int MAXW=10005;
	int n,W;
	int w[MAXN];
	long long v[MAXN];
	long long dp1[MAXW],dp2[MAXN][MAXW];

	// 0/1 Knapsack: duyet nguoc tu W ve w[i]
	long long knapsack_01_1d(){
		for(int j=0;j<=W;j++) dp1[j]=0;
		for(int i=1;i<=n;i++)
			for(int j=W;j>=w[i];j--)
				dp1[j]=max(dp1[j],dp1[j-w[i]]+v[i]);
		return dp1[W];
	}

	// 0/1 Knapsack co truy vet cac mon duoc chon
	vector<int> knapsack_01_trace(long long& ans){
		for(int i=1;i<=n;i++)
			for(int j=0;j<=W;j++){
				dp2[i][j]=dp2[i-1][j];
				if(j>=w[i]) dp2[i][j]=max(dp2[i][j],dp2[i-1][j-w[i]]+v[i]);
			}
		ans=dp2[n][W];
		vector<int> chosen;
		int cur_w=W;
		for(int i=n;i>=1;i--){
			if(cur_w>=w[i]&&dp2[i][cur_w]==dp2[i-1][cur_w-w[i]]+v[i]){
				chosen.push_back(i);
				cur_w-=w[i];
			}
		}
		reverse(chosen.begin(),chosen.end());
		return chosen;
	}

	// Unbounded Knapsack: duyet xuoi tu w[i] len W
	long long knapsack_unbounded(){
		for(int j=0;j<=W;j++) dp1[j]=0;
		for(int i=1;i<=n;i++)
			for(int j=w[i];j<=W;j++)
				dp1[j]=max(dp1[j],dp1[j-w[i]]+v[i]);
		return dp1[W];
	}
}

// [43] LIS O(N log N) truy vet, LCS truy vet & Edit Distance
namespace LisLcsEdit{
	const int MAXN=200005;
	int n;
	long long a[MAXN];

	// Day con tang nghiem ngat dai nhat (doi lower_bound thanh upper_bound neu lay tang khong giam)
	vector<long long> lis_trace(){
		vector<long long> tails;
		vector<int> tail_idx,par(n+1,-1);
		for(int i=1;i<=n;i++){
			int pos=lower_bound(tails.begin(),tails.end(),a[i])-tails.begin();
			if(pos==(int)tails.size()){
				tails.push_back(a[i]);
				tail_idx.push_back(i);
			}
			else{
				tails[pos]=a[i];
				tail_idx[pos]=i;
			}
			if(pos>0) par[i]=tail_idx[pos-1];
		}
		vector<long long> res;
		if(tail_idx.empty()) return res;
		for(int cur=tail_idx.back();cur!=-1;cur=par[cur]) res.push_back(a[cur]);
		reverse(res.begin(),res.end());
		return res;
	}

	string lcs_trace(const string& s,const string& t){
		int len1=s.size(),len2=t.size();
		vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
		for(int i=1;i<=len1;i++)
			for(int j=1;j<=len2;j++){
				if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		string res="";
		int i=len1,j=len2;
		while(i>0&&j>0){
			if(s[i-1]==t[j-1]){
				res+=s[i-1];
				i--;j--;
			}
			else if(dp[i-1][j]>=dp[i][j-1]) i--;
			else j--;
		}
		reverse(res.begin(),res.end());
		return res;
	}

	int edit_distance(const string& s,const string& t){
		int len1=s.size(),len2=t.size();
		vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
		for(int i=0;i<=len1;i++) dp[i][0]=i;
		for(int j=0;j<=len2;j++) dp[0][j]=j;
		for(int i=1;i<=len1;i++)
			for(int j=1;j<=len2;j++){
				if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
				else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
			}
		return dp[len1][len2];
	}
}

// [44] Quy hoach dong tren doan [l,r] (Interval DP)
namespace DpKhoang{
	const int MAXN=505;
	const long long INF=2e18;
	int n;
	long long a[MAXN],pf[MAXN],dp[MAXN][MAXN];

	long long interval_dp(){
		for(int i=1;i<=n;i++){
			pf[i]=pf[i-1]+a[i];
			dp[i][i]=0;
		}
		for(int len=2;len<=n;len++){
			for(int l=1;l+len-1<=n;l++){
				int r=l+len-1;
				dp[l][r]=INF;
				long long cost_lr=pf[r]-pf[l-1];
				for(int k=l;k<r;k++)
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+cost_lr);
			}
		}
		return dp[1][n];
	}
}

// [45] Bitmask DP (TSP N <= 20)
namespace BitmaskDP{
	const int MAXN=20;
	const long long INF=2e18;
	int n;
	long long w[MAXN][MAXN];

	long long tsp_min(){
		int full=(1<<n)-1;
		vector<vector<long long>> dp(1<<n,vector<long long>(n,INF));
		dp[1][0]=0;
		for(int mask=1;mask<=full;mask++){
			if(!(mask&1)) continue;
			for(int u=0;u<n;u++){
				if(dp[mask][u]==INF) continue;
				for(int v=0;v<n;v++){
					if((mask>>v)&1) continue;
					if(w[u][v]>=INF/2) continue;
					int nmask=mask|(1<<v);
					dp[nmask][v]=min(dp[nmask][v],dp[mask][u]+w[u][v]);
				}
			}
		}
		long long res=INF;
		for(int u=1;u<n;u++)
			if(dp[full][u]<INF&&w[u][0]<INF/2)
				res=min(res,dp[full][u]+w[u][0]);
		return res>=INF?-1:res;
	}
}

// [46] Digit DP dem so trong [L, R]
namespace DigitDP{
	string s_num;
	int target_sum;
	long long memo[20][200][2];

	long long dp_digit(int pos,int sum,bool tight){
		if(sum>target_sum) return 0;
		if(pos==(int)s_num.size()) return sum==target_sum;
		long long& res=memo[pos][sum][tight];
		if(res!=-1) return res;
		res=0;
		int lim=tight?(s_num[pos]-'0'):9;
		for(int d=0;d<=lim;d++){
			res+=dp_digit(pos+1,sum+d,tight&&(d==lim));
		}
		return res;
	}

	long long count_up_to(long long x){
		if(x<0) return 0;
		s_num=to_string(x);
		memset(memo,-1,sizeof(memo));
		return dp_digit(0,0,true);
	}
}

// [47] Tree DP tap doc lap & duong kinh cay
namespace TreeDPCoBan{
	const int MAXN=200005;
	int n;
	vector<int> adj[MAXN];
	long long w[MAXN],dp[MAXN][2];
	int down[MAXN],diam;

	void dfs_indep(int u,int p){
		dp[u][0]=0;
		dp[u][1]=w[u];
		for(int v:adj[u]){
			if(v==p) continue;
			dfs_indep(v,u);
			dp[u][0]+=max(dp[v][0],dp[v][1]);
			dp[u][1]+=dp[v][0];
		}
	}

	void dfs_diam(int u,int p){
		int mx1=0,mx2=0;
		for(int v:adj[u]){
			if(v==p) continue;
			dfs_diam(v,u);
			int len=down[v]+1;
			if(len>=mx1){
				mx2=mx1;
				mx1=len;
			}
			else if(len>mx2) mx2=len;
		}
		down[u]=mx1;
		diam=max(diam,mx1+mx2);
	}
}

// [48] Tree DP Rerooting (doi goc cay O(N))
namespace TreeDPRerooting{
	const int MAXN=200005;
	int n,sz[MAXN];
	vector<int> adj[MAXN];
	long long sub[MAXN],ans[MAXN];

	void dfs1(int u,int p){
		sz[u]=1;
		sub[u]=0;
		for(int v:adj[u]){
			if(v==p) continue;
			dfs1(v,u);
			sz[u]+=sz[v];
			sub[u]+=sub[v]+sz[v];
		}
	}

	void dfs2(int u,int p){
		for(int v:adj[u]){
			if(v==p) continue;
			ans[v]=ans[u]-sz[v]+(n-sz[v]);
			dfs2(v,u);
		}
	}
}

// [49] Toi uu DP bang Segment Tree & Monotonic Deque
namespace DpToiUu{
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
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	// Goi ham tu namespace can dung, vi du: Dijkstra::dijkstra(1);
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
