// Kadane 1D (O(N)) & Kadane 2D - Hinh chu nhat tong lon nhat (O(N^2 * M))
// Xu ly dung ca truong hop mang toan so am (chon it nhat 1 phan tu)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;

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

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n){
		for(int i=1;i<=n;i++) cin>>a[i];
		int l,r;
		cout<<kadane_1d(l,r)<<" ("<<l<<".."<<r<<")\n";
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
