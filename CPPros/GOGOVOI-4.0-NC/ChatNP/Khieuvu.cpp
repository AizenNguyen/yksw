#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long k,res;
void brute(){
    long long a[n+10]; a[0]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[j]-k==a[i]) res++;
    cout<<res<<'\n';
    res=0;
}   
void solve_bs(){
	int cnt_al;
    long long ar,a[n+10]; a[0]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int l=1;l<=n;l++){
        ar=a[l]+k;
        if(ar>a[n]) break;
        cnt_al=1;
        while(l+1<=n&&a[l]==a[l+1]){
        	cnt_al++;
        	l++;
        }
        auto first_ar=lower_bound(a+l+1,a+n+1,ar);
        if(first_ar==a+n+1||*first_ar!=ar) continue;
        auto last_ar=upper_bound(a+l+1,a+n+1,ar);
        res+=1LL*cnt_al*(last_ar-first_ar);
    }
    cout<<res<<'\n';
    res=0;
}
void solve_tp_mine(){
    int l=1,r=2
    long long diff,cnt_first,cnt_delta;
    cnt_first=cnt_delta=1;
    long long a[n+10]; a[0]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    while(r<=n){
        diff=a[l]+k;
        if(diff==a[r]){
            while(diff==a[r+1]){
                cnt_delta++;
                r++;
            }
            while(a[l]==a[l+1]){
                cnt_first++;
                l++;
            }
            res+=1LL*cnt_first*cnt_delta;
            cnt_delta=cnt_first=1;
            l++;
        }
        while(a[l]+k<a[r]) l++;
        if(a[l]+k!=a[r]) r++;
    }
    cout<<res<<'\n';
    res=0;
}
void solve_tp_std(){
    int l=1,r=2,diff;
    long long cnt_l,cnt_r,a[n+10]; a[0]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    while(r<=n){
        diff=a[r]-a[l];
        if(diff<k) r++;
        else if(diff>k){
            l++;
            if(l==r) r++;
        }
        else{
            cnt_l=cnt_r=1;
            while(l+1<=n&&a[l]==a[l+1]){cnt_l++; l++;}
            while(r+1<=n&&a[l]==a[l+1]){cnt_r++; r++;}
            res+=cnt_l*cnt_r;
            l++; r++;
        }
    }
    cout<<res<<'\n';
    res=0;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    //brute();
    solve_bs();
    //solve_tp_mine();
    //solve_tp_std();
}