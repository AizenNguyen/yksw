#include<iostream>
#include<algorithm> //solve 3(sort)
#include<vector> //solve 3(sort)
#include<map> //solve 1,2(freq)
using namespace std;
int n;
void brute(){
	int a[n+1];
	long long s,cnt;
	a[0]=cnt=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		s=0;
		for(int j=i;j<=n;j++){
			s+=a[j];
			if(s==0) cnt++;
		}
	}
	cout<<cnt<<'\n';
}
void solve_pf_freqformula(){
	int x;
	long long cnt,s;
	cnt=s=0;
	map<long long,int> freq; freq[0]=1;
	for(int i=1;i<=n;i++){
		cin>>x;
		s=s+x;
		freq[s]++;
	}
	for(auto x:freq) cnt+=1LL*x.second*(x.second-1)/2;
	cout<<cnt<<'\n';
}
void solve_pf_iterateandcount(){
	int x;
	long long cnt,s;
	cnt=s=0;
	map<long long,int> freq; freq[0]=1;
	for(int i=1;i<=n;i++){
		cin>>x;
		s=s+x;
		cnt+=freq[s]++;
	}
	cout<<cnt<<'\n';
}
void solve_pf_sort(){
	int x;
	long long cnt,cur=1;
	vector<long long> pf(n+1);
	pf[0]=cnt=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		pf[i]=pf[i-1]+x;
	}
	sort(pf.begin(),pf.end());
	for(int i=1;i<=n;i++){
		if(pf[i]==pf[i-1]) cur++;
		else{
			cnt+=cur*(cur-1)/2;
			cur=1;
		}
	}
	cnt+=cur*(cur-1)/2;
	cout<<cnt<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	//brute();
	//solve_pf_freqformula();
	//solve_pf_iterateandcount();
	solve_pf_sort();
}