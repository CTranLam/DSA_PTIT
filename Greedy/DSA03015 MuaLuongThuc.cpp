#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,s,m;
        cin >> n >> s >> m;
        int songay=s-(s/7);
        if(n*songay < m*s){
            cout << -1 << endl;
        }
        else{
            cout << (m*s + n-1)/n << endl;
        }
    }
}