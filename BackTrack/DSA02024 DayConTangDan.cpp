#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[25];
vector<string> ans;
int cnt=0;
void Try(int i,vector<int> v){
    if(v.size() >=3){
        string s="";
        for(int i=1 ; i<v.size() ; i++){
            s+=to_string(v[i])+" ";
        }
        ans.push_back(s);
    }
    for(int j=i ; j<=n ; j++){
        if(a[j] >= v.back()){
            v.push_back(a[j]);
            Try(j+1,v);
            v.pop_back();
        }
    }
}
int main(){
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }
    vector<int> v;
    v.push_back(0);
    Try(1,v);
    sort(ans.begin(),ans.end());
    for(string x : ans){
        cout << x <<endl;
    }
}