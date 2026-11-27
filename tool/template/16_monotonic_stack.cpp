// Ngan xep don dieu (Monotonic Stack): O(N), 1-indexed
// Tim L[i]/R[i] nho hon gan nhat & Bai mau Hinh chu nhat dien tich lon nhat (Histogram)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<stack>
#include<algorithm>
using namespace std;

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

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n){
		for(int i=1;i<=n;i++) cin>>h[i];
		cout<<largest_rectangle()<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
