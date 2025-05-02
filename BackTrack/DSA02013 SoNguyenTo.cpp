#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[1000005];
void sang(){
    f[0]=f[1]=1;
    for(int i=2 ; i<=sqrt(1000005) ; i++){
        if(f[i]==0){
            for(int j=i*i ; j<1000005 ; j+=i){
                f[j]=1;
            }
        }
    }
}
int n,p,s;
vector<vector<int>> ans;
void Try(int pos,int cnt,int sum,vector<int> v){
    if(cnt==n){
        if(sum==s){
            ans.push_back(v);
        }
        else return;
    }
    for(int i=pos ; i<= s ; i++){
        if(f[i]==0){
            sum+=i;
            v.push_back(i);
            Try(i+1,cnt+1,sum,v);
            sum-=i;
            v.pop_back();
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    sang();
    while(t--){
        cin >> n >> p >> s;
        vector<int> v;
        Try(p+1,0,0,v);
        cout << ans.size() << endl;
        for(auto x : ans){
            for(int i : x){
                cout << i <<" ";
            }
            cout << endl;
        }
        ans.clear();
    }
}