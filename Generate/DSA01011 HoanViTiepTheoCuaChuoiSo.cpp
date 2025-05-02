#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int tt;cin >> tt;
        string s;
        cin >> s;
        if(next_permutation(s.begin(),s.end())){
            cout <<tt <<" "<< s << endl;
        }
        else{
            cout << tt <<" "<< "BIGGEST" << endl;
        }
    }
}