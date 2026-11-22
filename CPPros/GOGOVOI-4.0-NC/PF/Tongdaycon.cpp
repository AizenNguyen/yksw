#include<iostream>
#include<vector>
using namespace std;
short t;
int n;
void brute(){

}
void solve(){
	int x;
	long long snow,Minpf,Max_x,MaxSub1,MaxSub2;
	snow=Minpf=MaxSub1=0;
	MaxSub2=-1e18;
	for(int i=1;i<=n;i++){
		cin>>x;
		Max_x=Max_x>x?Max_x:x;
		snow=snow+x;
		if(x>0) MaxSub1+=x;
		MaxSub2=MaxSub2>snow-Minpf?MaxSub2:snow-Minpf;
	}
	if(MaxSub1==0) MaxSub1=Max_x;
	MaxSub1=MaxSub1>Max_x?MaxSub1:Max_x;
	cout<<MaxSub1<<" "<<MaxSub2<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		//brute();
		solve();
	}
}