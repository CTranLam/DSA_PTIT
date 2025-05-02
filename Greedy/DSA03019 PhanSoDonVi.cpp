#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool check=false;
        int c4=0,c7=0;
        c7=n/7; // chon cang nhieu so 7 cang tot
        while(c7 > 0){
            int x=n-c7*7;
            if(x%4==0){
                c4=x/4;
                check=true;
                break;
            }
            else{
                --c7;
            }
        }
        if(!check) cout << -1 << endl;
        else{
            for(int i=0 ; i<c4 ; i++) cout << 4;
            for(int i=0 ; i<c7 ; i++) cout << 7;
            cout << endl;
        }
    }
}