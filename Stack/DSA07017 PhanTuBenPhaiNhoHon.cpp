#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> solve_greater(int a[],int n){
    stack<int> st;
    st.push(0);
    vector<int> res(n);
    for(int i=1 ; i<n ; i++){
        if(a[i] <= a[st.top()]){
            st.push(i);
        }
        else{
            while(!st.empty() && a[i] > a[st.top()]){
                res[st.top()] = i; // luu lai chi so de sau tim
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        res[st.top()]=-1;
        st.pop();
    }
    return res;
}
vector<int> solve_smaller(int a[],int n){
    stack<int> st;
    st.push(0);
    vector<int> res(n);
    for(int i=1 ; i<n ; i++){
        if(a[i] >= a[st.top()]){
            st.push(i);
        }
        else{
            while(!st.empty() && a[i] < a[st.top()]){
                res[st.top()]=a[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        res[st.top()]=-1;
        st.pop();
    }
    return res;
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
        vector<int> gr=solve_greater(a,n);
        vector<int> sm=solve_smaller(a,n);
        for(int i=0 ; i<n ; i++){
            if(gr[i]==-1){
                cout << -1 <<" ";
            }
            else{
                cout << sm[gr[i]] <<" ";
            }
        }
        cout << endl;
    }

}