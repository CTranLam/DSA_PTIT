#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
        int res[n];
        stack<int> st;
        st.push(0);
        for(int i=1 ; i<n ; i++){
            if(a[i] <= a[st.top()]){
                st.push(i);
            }
            else{
                while(!st.empty() && a[i] > a[st.top()]){
                    res[st.top()] = a[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            res[st.top()]=-1;
            st.pop();
        }
        for(int i=0 ; i<n ; i++){
            cout << res[i] <<" ";
        }
        cout << endl;
    }

}