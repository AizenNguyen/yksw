#include<iostream>
using namespace std;
int t,s1;
short l,r;
long long s2,s3; 
void brute(){
	for(int i=1;i<=t;i++){
		cin>>l>>r;
		for(int j=l;j<=r;j++){
			s1+=j;
			s2+=j*j;
			s3+=j*j*j;
		}
		cout<<s1<<" "<<s2<<" "<<s3<<'\n';
		s1=s2=s3=0;
	}
}
void solve(){
	
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	brute();
}