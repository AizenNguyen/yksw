// Bo sinh test ngau nhien (mang, hoan vi, cay, do thi lien thong) & cham trau stress test
// Luu y: rieng file sinh test cho phep dung #include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

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

int main(){
	const int NUM_TEST=1000;
	for(int t=1;t<=NUM_TEST;t++){
		sinh();
		if(system("trau.exe < sinh.inp > sinh.ans")!=0){
			cout<<"[-] TRAU RTE AT TEST "<<t<<'\n';
			return 0;
		}
		if(system("thuat.exe < sinh.inp > sinh.out")!=0){
			cout<<"[-] THUAT RTE AT TEST "<<t<<'\n';
			return 0;
		}
		if(system("fc sinh.out sinh.ans > nul")!=0){
			cout<<"[-] TEST "<<t<<" WRONG!\n";
			return 0;
		}
		if(t%100==0) cout<<"Passed "<<t<<" tests...\n";
	}
	cout<<"\n=> ALL "<<NUM_TEST<<" TESTS PASSED!\n";
	return 0;
}
