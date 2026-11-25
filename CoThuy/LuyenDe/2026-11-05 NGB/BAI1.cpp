#include<iostream>
using namespace std;
long long l,r,s1,slr,res=1000000000;
bool check(){
	return 2*s1<=slr;
}
void brute(){
	long long tmp,s2,delta=1000000000000000000;
	tmp=s2=0;
	slr=(r-l+1)*(r+l)/2;
	//slr=(r*r-l*l+r+l)/2;
	for(int i=l;i<r;i++){
	 	s1+=i;
	 	s2=abs(slr-s1);
	 	tmp=abs(s1-s2);
	 	if(tmp<delta){
	 		delta=tmp;
	 		res=i;
	 	}
	}
	cout<<res<<'\n';
	res=1000000000;
}
void solve(){
	long long low=l,high=r-1,mid,delta1,delta2;
	slr=(r-l+1)*(r+l)/2;
	//slr=(r*r-l*l+r+l)/2;
	while(low<=high){
		mid=(low+high)/2;
		s1=(mid-l+1)*(mid+l)/2;
		if(check()){
			low=mid+1;
			res=mid;
		}
		else high=mid-1;
	}
	if(res+1<r){
		delta1=abs(2*((res-l+1)*(res+l)/2)-slr);
		delta2=abs(2*((res-l+2)*(res+l+1)/2)-slr);
		if(delta2<delta1) res++;
	}
	cout<<res<<'\n';
	res=1000000000;
}
int main(){
	if(fopen("BAI1.INP","r")){
		freopen("BAI1.INP","r",stdin);
		freopen("BAI1.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>l>>r;
	if(r<=1000) brute();
	else solve();
}