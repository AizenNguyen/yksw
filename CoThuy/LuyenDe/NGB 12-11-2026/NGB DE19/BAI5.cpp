#include<iostream>
#include<vector>
using namespace std;
short n;
int x1,y1,x2,y2;
void sub1(){
    long long ax1,ay1,ax2,ay2;
    long long bx1,by1,bx2,by2;
    cin>>ax1>>ay1>>ax2>>ay2;
    cin>>bx1>>by1>>bx2>>by2;
    if(ax1>ax2) swap(ax1,ax2);
    if(ay1>ay2) swap(ay1,ay2);
    if(bx1>bx2) swap(bx1,bx2);
    if(by1>by2) swap(by1,by2);
    long long s1=(ax2-ax1)*(ay2-ay1);
    long long s2=(bx2-bx1)*(by2-by1);
    long long overlap_w=max(0LL,min(ax2, bx2)-max(ax1, bx1));
    long long overlap_h=max(0LL,min(ay2, by2)-max(ay1, by1));
    long long scover=overlap_w*overlap_h;
    cout<<s1+s2-scover<<'\n';
}
int main(){
	if(fopen("BAI5.INP","r")){
		freopen("BAI5.INP","r",stdin);
		freopen("BAI5.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	sub1();
}