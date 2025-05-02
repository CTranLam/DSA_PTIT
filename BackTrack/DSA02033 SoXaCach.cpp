#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int used[100];
void Try(vector<int> v){
    if(v.size()==n+1){
        for(int i=1; i<v.size() ; i++){
            cout << v[i];
        }
        cout << endl;
        return;
    }
    for(int j=1 ; j<=n ; j++){
        if(!used[j]){
            if(abs(j-v.back()) != 1){
                v.push_back(j);
                used[j]=1;
                Try(v);
                v.pop_back();
                used[j]=0;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >>t;
    while(t--){
        cin >> n;
        memset(used,0,sizeof(used));
        vector<int> v;
        v.push_back(-5);
        Try(v);
    }
}