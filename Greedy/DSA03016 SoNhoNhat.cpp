#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int s,d;
        cin >> s >> d;
        if(s > 9*d){
            cout << -1 << endl;
        }
        else{
            d-=1;
            s-=1;
            string res="";
            while(d--){
                if(s >= 9){
                    res="9"+res;
                    s-=9;
                }
                else{
                    res=to_string(s)+res;
                    s=0;
                }
            }
            s+=1;
            res=to_string(s)+res;
            cout << res << endl;
        }
    }
}