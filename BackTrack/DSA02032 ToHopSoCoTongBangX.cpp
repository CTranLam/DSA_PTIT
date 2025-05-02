#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x;
int a[100];
bool check=false;
vector<string> ans;
void Try(int i,int sum,vector<int> v){
    if(sum==x){
        check=true;
        string s="{";
        for(int i=0 ; i<v.size()-1 ;i++){
            s+=to_string(v[i])+" ";
        }
        s+=to_string(v.back());
        s+="}";
        ans.push_back(s);
        return;
    }
    if(sum > x) return;
    for(int j=i ; j<=n ; j++){
        sum+=a[j];
        v.push_back(a[j]);
        Try(j,sum,v);
        sum-=a[j];
        v.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> x;
        memset(a,0,sizeof(a));
        for(int i=1 ; i<=n ; i++){
            cin >> a[i];
        }
        sort(a+1,a+n+1);     
        vector<int> v;
        check=false;
        Try(1,0,v);
        if(!check){
            cout << -1 << endl;
        }
        else{
            cout << ans.size() <<" ";
            for(string x : ans){
                cout << x <<" ";
            }
            cout << endl;
        }
        ans.clear();
    }
}