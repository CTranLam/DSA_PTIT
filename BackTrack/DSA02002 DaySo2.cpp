#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[20];
vector<string> ans;
void Try(vector<int>& v){
    string s="[";
    for(int i=0 ; i<v.size()-1; i++){
        s+= to_string(v[i])+" ";
    }
    s+=to_string(v.back())+"]";
    ans.push_back(s);
    if(v.size()==1) return;
    else{
        vector<int> tmp;
        for(int i=1 ; i<v.size(); i++){
            tmp.push_back(v[i]+v[i-1]);
        }
        Try(tmp);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            v.push_back(a[i]);
        }
        Try(v);
        for(int i=ans.size()-1 ; i>=0 ; i--){
            cout << ans[i] <<" ";
        }
        cout << endl;
        ans.clear();
    }
}