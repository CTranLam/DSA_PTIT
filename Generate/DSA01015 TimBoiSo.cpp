#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string boiSo(int n){
    queue<string> q;
    q.push("9");
    while(!q.empty()){
        string tmp=q.front();
        q.pop();
        if(stoll(tmp)%n==0) return tmp;
        q.push(tmp+"0");
        q.push(tmp+"9");
    }
    return "0";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << boiSo(n) << endl;
    }
    return 0;
}