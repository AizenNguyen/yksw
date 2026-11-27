// Digit DP: Dem so luong so trong doan [L, R] co tong chu so bang target_sum
// Co the mo rong them trang thai (prev_d, started, rem) tuy de bai
#include<iostream>
#include<cstdio>
#include<ctime>
#include<string>
#include<cstring>
using namespace std;

string s_num;
int target_sum;
long long memo[20][200][2];

long long dp_digit(int pos,int sum,bool tight){
	if(sum>target_sum) return 0;
	if(pos==(int)s_num.size()) return sum==target_sum;
	long long& res=memo[pos][sum][tight];
	if(res!=-1) return res;
	res=0;
	int lim=tight?(s_num[pos]-'0'):9;
	for(int d=0;d<=lim;d++){
		res+=dp_digit(pos+1,sum+d,tight&&(d==lim));
	}
	return res;
}

long long count_up_to(long long x){
	if(x<0) return 0;
	s_num=to_string(x);
	memset(memo,-1,sizeof(memo));
	return dp_digit(0,0,true);
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long l,r;
	if(cin>>l>>r>>target_sum){
		cout<<count_up_to(r)-count_up_to(l-1)<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
