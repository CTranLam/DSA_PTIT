#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> v;
void Try(int sum,int last){
    if(sum==n){
        cout <<"(";
        for(int i=0 ; i<v.size(); i++){
            if(i != v.size()-1) cout << v[i] <<" ";
            else cout << v[i];
        }
        cout <<") ";
    }
    for(int i=last ; i>=1 ; i--){
        if(sum + i<=n){
            v.push_back(i);
            Try(sum+i,i);
            v.pop_back();
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        Try(0,n);
        cout << endl;
    }
}