// LIS O(N log N) + truy vet, LCS O(N*M) + truy vet, Edit Distance O(N*M)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

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

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(cin>>n){
		for(int i=1;i<=n;i++) cin>>a[i];
		vector<long long> ans=lis_trace();
		cout<<ans.size()<<'\n';
		for(long long x:ans) cout<<x<<" ";
		cout<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
