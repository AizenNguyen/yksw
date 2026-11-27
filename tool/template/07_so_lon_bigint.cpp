// So lon BigInt dung string: so sanh, cong, tru (ho tro dau am), nhan, chia lay du voi long long
// Do phuc tap: cong/tru O(N), nhan O(N*M), chia long long O(N)
#include<iostream>
#include<cstdio>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

string chuan_hoa(string s){
	if(s.empty()) return "0";
	bool am=(s[0]=='-');
	int i=(s[0]=='-'||s[0]=='+')?1:0;
	while(i<(int)s.size()-1&&s[i]=='0') i++;
	string res=s.substr(i);
	if(res=="0") return "0";
	return am?"-"+res:res;
}

int cmp_abs(const string& a,const string& b){
	if(a.size()!=b.size()) return a.size()<b.size()?-1:1;
	if(a==b) return 0;
	return a<b?-1:1;
}

string add_abs(const string& a,const string& b){
	string res="";
	int i=(int)a.size()-1,j=(int)b.size()-1,carry=0;
	while(i>=0||j>=0||carry){
		int sum=carry;
		if(i>=0) sum+=a[i--]-'0';
		if(j>=0) sum+=b[j--]-'0';
		res+=char(sum%10+'0');
		carry=sum/10;
	}
	reverse(res.begin(),res.end());
	return chuan_hoa(res);
}

// Gia su a>=b>=0
string sub_abs(const string& a,const string& b){
	string res="";
	int i=(int)a.size()-1,j=(int)b.size()-1,borrow=0;
	while(i>=0){
		int d=(a[i--]-'0')-borrow-(j>=0?b[j--]-'0':0);
		if(d<0){
			d+=10;
			borrow=1;
		}
		else borrow=0;
		res+=char(d+'0');
	}
	reverse(res.begin(),res.end());
	return chuan_hoa(res);
}

string add_big(string a,string b){
	a=chuan_hoa(a);b=chuan_hoa(b);
	bool neg_a=(a[0]=='-'),neg_b=(b[0]=='-');
	if(neg_a) a=a.substr(1);
	if(neg_b) b=b.substr(1);
	if(neg_a==neg_b){
		string res=add_abs(a,b);
		return (neg_a&&res!="0")?"-"+res:res;
	}
	int c=cmp_abs(a,b);
	if(c==0) return "0";
	if(c>0){
		string res=sub_abs(a,b);
		return neg_a?"-"+res:res;
	}
	string res=sub_abs(b,a);
	return neg_b?"-"+res:res;
}

string sub_big(string a,string b){
	b=chuan_hoa(b);
	if(b=="0") return chuan_hoa(a);
	if(b[0]=='-') b=b.substr(1);
	else b="-"+b;
	return add_big(a,b);
}

string mul_big(string a,string b){
	a=chuan_hoa(a);b=chuan_hoa(b);
	if(a=="0"||b=="0") return "0";
	bool neg=(a[0]=='-')^(b[0]=='-');
	if(a[0]=='-') a=a.substr(1);
	if(b[0]=='-') b=b.substr(1);
	int n=a.size(),m=b.size();
	vector<int> p(n+m,0);
	for(int i=n-1;i>=0;i--)
		for(int j=m-1;j>=0;j--){
			int sum=(a[i]-'0')*(b[j]-'0')+p[i+j+1];
			p[i+j+1]=sum%10;
			p[i+j]+=sum/10;
		}
	string res="";
	for(int x:p) if(!(res.empty()&&x==0)) res+=char(x+'0');
	if(res.empty()) return "0";
	return neg?"-"+res:res;
}

// Chia so nguyen khong am cho b>0 (luu y b <= 9e17 de khong tran cur*10)
pair<string,long long> div_mod_big(string a,long long b){
	a=chuan_hoa(a);
	string q="";
	long long rem=0;
	for(char ch:a){
		rem=rem*10+(ch-'0');
		q+=char(rem/b+'0');
		rem%=b;
	}
	return {chuan_hoa(q),rem};
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	string a,b;
	if(cin>>a>>b){
		cout<<add_big(a,b)<<'\n';
		cout<<sub_big(a,b)<<'\n';
		cout<<mul_big(a,b)<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
