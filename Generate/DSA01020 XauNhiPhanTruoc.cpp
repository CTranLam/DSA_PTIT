#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int k=s.length()-1;
        while(k >= 0 && s[k] == '0'){
            s[k]='1';
            --k;
        }
        if(k==-1){
            for(int i=0 ; i<s.length() ; i++){
                cout << '1';
            }
            cout << endl;
        }
        else{
            s[k]='0';
            cout << s << endl;
        }
    }
}