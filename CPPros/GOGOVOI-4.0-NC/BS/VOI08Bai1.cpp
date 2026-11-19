#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long minval=2e18;
void brute(){
    vector<int> b(n+1),c(n+1);
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)
            minval=minval<abs(c[i]+b[j])?minval:abs(c[i]+b[j]);
    }
    cout<<minval<<'\n';
    minval=2e18;
}
void solve_bs(){
	int val;
    vector<int> b(n+1),c(n+1);
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    sort(b.begin()+1,b.end());
    for(int i=1;i<=n;i++){
        auto it=lower_bound(b.begin()+1,b.end(),-c[i]);
        if(it!=b.end()){
    		val=abs(*it+c[i]);
    		minval=minval<val?minval:val;
    	}
    	if(it!=b.begin()+1){
    		val=abs(*(it-1)+c[i]);
    		minval=minval<val?minval:val;
		}
	}
    cout<<minval<<'\n';
    minval=2e18;
}
void solve_tp(){
	int l=1,r=n,val;
	vector<int> b(n+1),c(n+1);
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(b.begin()+1,b.end());
	sort(c.begin()+1,c.end());
	while(r>=1){
		val=abs(a[l]+a[r]);
		if(val<abs(a[l]+a[r])) l++;
	}
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    //brute();
    solve_bs();
    //solve_tp();
}