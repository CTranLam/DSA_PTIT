#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void nho_hon_ben_trai(int l[],int a[],int n){
    stack<int> st;
    for(int i=n-1 ; i>=0 ; i--){
        while(!st.empty() && a[i] < a[st.top()]){
            l[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        l[st.top()]=-1;
        st.pop();
    }
}
void nho_hon_ben_phai(int r[],int a[],int n){
    stack<int> st;
    for(int i=0 ; i<n ; i++){
        while(!st.empty() && a[i] < a[st.top()]){
            r[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        r[st.top()]=n;
        st.pop();
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        int l[n],r[n];
        nho_hon_ben_phai(r,a,n);
        nho_hon_ben_trai(l,a,n);
        ll res=0;
        for(int i=0 ; i<n ; i++){
            int rong=r[i]-l[i]-1;
            res=max(res,(ll)rong*a[i]);
        }
        cout << res << endl;
    }
}