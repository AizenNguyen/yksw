// Thuat toan Z-function: z[i] = do dai tien to chung dai nhat cua s va s[i..n-1], O(N)
// Kem ham tim vi tri xuat hien (1-indexed) cua pat trong text
#include<iostream>
#include<cstdio>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

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

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	string text,pat;
	if(cin>>text>>pat){
		vector<int> res=z_search(text,pat);
		cout<<res.size()<<'\n';
		for(int x:res) cout<<x<<" ";
		cout<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
