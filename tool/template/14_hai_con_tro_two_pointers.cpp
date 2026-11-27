// Hai con tro (Two Pointers), 1-indexed, O(N)
// Mau 1: Doan dai nhat co <= k gia tri khac nhau; Mau 2: Dem so doan tong <= S (a[i]>=0)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<unordered_map>
using namespace std;

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

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n>>k){
		for(int i=1;i<=n;i++) cin>>a[i];
		doan_khac_nhau_max();
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
