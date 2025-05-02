#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,s;
int a[100];
int cnt=INT_MAX;
bool ok=false;
void Try(int i,int sum,vector<int> v){
    if(sum==s){
        ok=true;
        int tmp=v.size();
        cnt=min(tmp,cnt);
        return;
    }
    if(sum > s || v.size() > cnt) return;
    for(int j=i ; j<n ; j++){
        sum+=a[j];
        v.push_back(a[j]);
        Try(j+1,sum,v);
        sum-=a[j];
        v.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> s;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    sort(a,a+n,greater<int>());
    vector<int> v;
    Try(0,0,v);
    if(!ok) cout << -1 << endl;
    else cout << cnt << endl;
}