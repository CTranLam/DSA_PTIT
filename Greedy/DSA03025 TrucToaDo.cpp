#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> v;
        for(int i=0 ; i<n ; i++){
            int x,y;
            cin >> x >> y;
            v.push_back({x,y});
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