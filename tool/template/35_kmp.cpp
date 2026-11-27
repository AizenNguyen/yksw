// Thuat toan KMP (Prefix Function): O(N + M)
// Tra ve danh sach vi tri xuat hien (1-indexed) cua xau mau pat trong xau text
#include<iostream>
#include<cstdio>
#include<ctime>
#include<string>
#include<vector>
using namespace std;

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

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	string text,pat;
	if(cin>>text>>pat){
		vector<int> res=kmp_search(text,pat);
		cout<<res.size()<<'\n';
		for(int x:res) cout<<x<<" ";
		cout<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
