#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;
}
int main(){
    int t;cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> v;
        int s[n];
        int f[n];
        for(int i=0 ; i<n ; i++){
            cin >> s[i];
        }
        for(int i=0 ; i<n ; i++){
            cin >> f[i];
            v.push_back({s[i],f[i]});
        }
        sort(v.begin(),v.end(),cmp);
        int cnt=1;
        int ed=v[0].second;
        for(int i=1 ; i<n ; i++){
            if(v[i].first >= ed){
                ++cnt;
                ed=v[i].second;
            }
        }
        cout << cnt << endl;
    }
}