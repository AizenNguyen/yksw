#include<iostream>
using namespace std;
int n;
long long pf[200005];
void brute(){
	int a[n+1];
	long long left_s,right_s,cnt;
	a[0]=left_s=cnt=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		left_s+=a[i];
		right_s=0;
		for(int j=i+1;j<=n;j++)
			right_s+=a[j];
		if(left_s==right_s) cnt++;
	}
	cout<<cnt<<'\n';
}
void solve_pf(){
	int x;
	long long cnt,half_s;
	pf[0]=cnt=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		pf[i]=pf[i-1]+x;
	}
	if(pf[n]&1){
		cout<<0;
		return;
	}
	half_s=pf[n]/2;
	for(int i=1;i<n;i++)
		if(pf[i]==half_s)
			cnt++;
	cout<<cnt<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	//brute();
	solve_pf();
}