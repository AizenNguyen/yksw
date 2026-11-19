#include<iostream>
using namespace std;
short m,n,cnt_n;
char c;
void brute(){
	short a[n+1][m+1];
	for(int i=1;i<=m;i++){
		cnt_n=1;
		while(cin>>c){
			a[i][cnt_n]=c-'0';
			cnt_n++;
		}
	}
}
int main(){
	if(fopen("plan.inp","r")){
		freopen("plan.inp","r",stdin);
		freopen("plan.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>m>>n;
	brute();
}