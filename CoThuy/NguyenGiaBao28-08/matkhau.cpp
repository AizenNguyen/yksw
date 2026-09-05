#include <iostream>
#include <string>
using namespace std;
short tmpsize;
int checksnt,res=2;
string s,tmp;
bool dssnt[1000010];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("matkhau.inp","r",stdin);
    freopen("matkhau.out","w",stdout);
    dssnt[0]=dssnt[1]=1;
    for(int i=4;i<=1000001;i+=2)
        dssnt[i]=1;
    for(int i=3;i*i<=1000001;++i)
        if(dssnt[i]==0)
            for(int j=i*i;j<=1000000;j+=i)
                dssnt[j]=1;
    cin>>s;
    s+=" ";
    for(int k=0;k<s.size();++k){
        if (s[k]>='0'&&s[k]<='9'){
            if(tmpsize==7){
                for(int i=0;i<tmpsize;++i){
                    for(int j=i+1;j<=tmpsize;++j){
                        if(j-i>7)
                            break;
                        checksnt=stoi(tmp.substr(i,j-i));
                        if(checksnt<=1000000&&!dssnt[checksnt])
                            res=max(res,checksnt);
                    }
                }
                tmp.erase(0, 1);
                tmpsize--;
            }
            tmp+=s[k];
            tmpsize++;
        }
        else{
            for(int i=0;i<tmpsize;++i){
                for (int j=i+1;j<=tmpsize;++j){
                    if(j-i>7)
                        break;
                    checksnt=stoi(tmp.substr(i,j-i));
                    if(checksnt<=1000000&&!dssnt[checksnt])
                        res=max(res,checksnt);
                }
            }
            tmp="";
            tmpsize=0;
        }
    }
    cout << res;
}
