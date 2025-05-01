#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first < b.first;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> v;
        for(int i=0 ; i<n ; i++){
            int x;
            cin >> x;
            v.push_back({x,i});
        }
        sort(v.begin(),v.end(),cmp);
        int ans=INT_MIN;
        int minPos=v[0].second;
        // la 1 day tang dan 
        for(int i=1 ; i<n ; i++){
            ans=max(ans,v[i].second-minPos);
            minPos=min(v[i].second,minPos);// luon tim vi tri di qua be nhat
        }
        cout << ans << endl;
    }
}