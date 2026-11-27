// Cua so truot tim Min / Max tren moi doan do dai k bang Deque: O(N), 1-indexed
#include<iostream>
#include<cstdio>
#include<ctime>
#include<deque>
using namespace std;

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

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n>>k){
		for(int i=1;i<=n;i++) cin>>a[i];
		sliding_window();
		for(int i=k;i<=n;i++) cout<<mn[i]<<(i==n?'\n':' ');
		for(int i=k;i<=n;i++) cout<<mx[i]<<(i==n?'\n':' ');
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
