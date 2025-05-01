#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n ;
        int a[n];
        int minn=INT_MAX,maxn=INT_MIN;
        set<int> se;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            se.insert(a[i]);
        }
        cout << (*se.rbegin()-*se.begin()+1)-se.size() << endl; 
    }
}