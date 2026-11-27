// Cay Trie: (1) Trie chuoi ky tu thuong 'a'..'z'; (2) Trie nhi phan tim cap XOR lon nhat
// Do phuc tap: O(|S|) hoac O(30) moi thao tac
#include<iostream>
#include<cstdio>
#include<ctime>
#include<string>
#include<algorithm>
using namespace std;

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

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	if(cin>>n){
		int ans=0;
		insert_num(0);
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			ans=max(ans,max_xor(x));
			insert_num(x);
		}
		cout<<ans<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
