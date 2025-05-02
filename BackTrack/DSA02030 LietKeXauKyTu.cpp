#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char c;
int k;
void Try(int i,vector<int>& v){
    if(v.size()==k){
        for(int x : v){
            cout << char('A'+x);
        }
        cout << endl;
        return;
    }
    for(int j=i; j<=c-'A' ; j++){
        v.push_back(j);
        Try(j,v);
        v.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> c;
    cin >> k;
    vector<int> v;
    Try(0,v);
}