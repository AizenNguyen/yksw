#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<ctime>
using namespace std;
int n,k,m,x,asz,surpsz;
long long seg_cnt,slash_cnt;
vector<int> a(1,0),surp(1,0);
int main(){
	if(fopen("CUTLINE.INP","r")){
		freopen("CUTLINE.INP","r",stdin);
		freopen("CUTLINE.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x%m==0) a.emplace_back(x);
		else if(x>m) surp.emplace_back(x);
	}
	asz=a.size()-1; surpsz=surp.size()-1;
	sort(a.begin()+1,a.end());
	for(int i=1;i<=asz&&seg_cnt<k;i++){
		seg_cnt+=a[i]/m;
		slash_cnt+=a[i]/m-1;
	}
	if(seg_cnt==k){
		cout<<slash_cnt;
		return 0;
	}
	else if(seg_cnt>k){
		cout<<slash_cnt-(seg_cnt-k-1);
		return 0;
	}
	sort(surp.begin()+1,surp.end());
	for(int i=1;i<=surpsz&&seg_cnt<k;i++){
		seg_cnt+=surp[i]/m;
		slash_cnt+=surp[i]/m;
	}
	if(seg_cnt==k) cout<<slash_cnt;
	else if(seg_cnt>k) cout<<slash_cnt-(seg_cnt-k);
	else cout<<-1;
	cerr<<"w "<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
}