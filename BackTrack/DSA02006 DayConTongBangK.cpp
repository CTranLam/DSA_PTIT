#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int a[100];
bool check=false;
void Try(int i,int sum,vector<int> v){
    if(sum==k){
        check=true;
        cout <<"[";
        for(int j=0; j<v.size()-1 ; j++){
            cout << v[j] <<" ";
        }
        cout << v.back() <<"] ";
        return;
    }
    if(sum > k) return;
    for(int j=i ; j<=n ;j++){
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
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        memset(a,0,sizeof(a));
        for(int i=1; i<=n ; i++){
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
            cout << endl;
        }
    }
}