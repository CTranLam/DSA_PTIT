#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int i=s.length()-1;
        while(i >= 0 && s[i]=='1'){
            s[i]='0';
            --i;
        }
        if(i != -1){
            s[i]='1';
        }
        for(char x : s){
            cout << x;
        }
        cout << endl;
    }
}