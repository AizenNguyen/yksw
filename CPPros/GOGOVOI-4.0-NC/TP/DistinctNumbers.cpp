#include<iostream>
#include<algorithm> //solve_tp
#include<vector> //solve_tp
#include<set> //solve_set
using namespace std;
int n;
void solve_tp(){
	int l,r,diffnum;
	l=r=diffnum=1;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end());
	while(r<=n){
		if(a[l]!=a[r]){
			l=r;
			diffnum++;
		}
		else r++;
	}
	cout<<diffnum<<'\n';
	diffnum=1;
}
void solve_set(){
	int x;
	set<int> st;
	for(int i=1;i<=n;i++){
		cin>>x;
		st.insert(x);
	}
	cout<<st.size();
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	solve_tp();
	//solve_set();
}