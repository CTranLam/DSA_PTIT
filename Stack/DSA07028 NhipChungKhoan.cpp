#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// stock span problem
void solve(int a[],int n){
    stack<int> st;
    vector<int> res(n);
    for(int i=0 ; i<n ; i++){
        //Tim thang dau tien lon hon a[i] ben trai
        while(!st.empty() && a[st.top()] <= a[i]){
            st.pop(); // loai bo het thangbe hon hien tai
        }
        if(st.empty()) res[i]=i+1;
        else res[i]=i-st.top();
        st.push(i);
    }
    for(int i=0 ; i<n ; i++) cout << res[i] <<" ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;cin >> n;
        int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        solve(a,n);
    }
}